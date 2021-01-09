/*!
 * \file   server_win32.cpp
 * \author Attila Krüpl dr.
 * \date   29/12/2020
 */

#include "stdafx.h"

using namespace nProtocol;

void Server::Accept()
{
    WSAPOLLFD lListeningSocketFD         = {};
              lListeningSocketFD.fd      = mTCPSocket;
              lListeningSocketFD.events  = kServerReadPollFlag;
              lListeningSocketFD.revents = kServerPollREvents;
    const int lNumberOfSocketsInArray    = kNumberOfServerSockets;
    const int lTimeOut                   = kPollTimeoutTimeOutMilS;
    
    if ( WSAPoll(&lListeningSocketFD, lNumberOfSocketsInArray, lTimeOut ) >= 0 )
    {
        if ( lListeningSocketFD.revents & kServerReadPollFlag )
        {
            SocketAddressIn_np lClient;
            int lClientSize = sizeof( lClient );

            char lHost[NI_MAXHOST];
            char lService[NI_MAXSERV];

            ZeroMemory( lHost, NI_MAXHOST );
            ZeroMemory( lService, NI_MAXSERV );

            Socket_np lAcceptedSocket = accept( mTCPSocket, (sockaddr*)&lClient, &lClientSize );
            if ( lAcceptedSocket == INVALID_SOCKET )
            {
                std::cout << "ERROR - Accepting client connection failed! Error code: " << WSAGetLastError() << std::endl;
                return;
            }

            if ( getnameinfo( (sockaddr*)&lClient, sizeof( lClient ), lHost, NI_MAXHOST, lService, NI_MAXSERV, 0 ) == 0 )
            {
                std::cout << "SUCCESS - " << lHost << " connected on port " << lService << std::endl;
            }
            else
            {
                inet_ntop( AF_INET, &lClient.sin_addr, lHost, NI_MAXHOST );
                std::cout << "SUCCESS - " << lHost << " connected on port " << ntohs( lClient.sin_port ) << std::endl;
            }

            std::cout << "SUCCESS - Accepted client connection successfully! Socket: " << lAcceptedSocket << std::endl;
            
                  unsigned long lNonBlocking = 1;
            const int           lResult      = ioctlsocket( lAcceptedSocket, FIONBIO, &lNonBlocking );
            if ( lResult == SOCKET_ERROR )
            {
                PROTO_ERROR( nProtocol::eProtocolError::CantMakeClientSocketNonBlocking, "Can't make client socket non blocking!", WSAGetLastError() );
            }

            mNodeContainer.push_back( lAcceptedSocket );
        }
    }
}

void Server::Send( const Socket_np& aSocket )
{
    const int lSendBufferSize = (int)sizeof( mSendBuffer ) + 1;
    if ( lSendBufferSize != 0 )
    {
        int lSendResult;

        if ( aSocket == NULL )
        {
            return;
        }

        lSendResult = send( aSocket, mReceiveBuffer, sizeof(mReceiveBuffer), 0 );
        if ( lSendResult == SOCKET_ERROR )
        {
            std::cout << "ERROR - Sending failed! Socket: " << aSocket << " Error code: " << WSAGetLastError() << std::endl;
            return;
        }
        std::cout << "SUCCESS - Sending to socket successful! Socket: " << aSocket << " Send result: " << lSendResult << std::endl;
    }
}

void Server::Recieve()
{
    ConnectionArray lConnectionToRemove = {};

    for ( const Socket_np& lSocket : mNodeContainer )
    {
        if ( lSocket == NULL )
        {
            break;
        }
        
        struct timeval lTimeout;
        struct fd_set lFds;

        lTimeout.tv_sec = kPollTimeoutTimeOutSec;
        lTimeout.tv_usec = kPollTimeoutTimeOutMicS;

        FD_ZERO( &lFds );
        FD_SET( lSocket, &lFds );
        if ( select( 0, &lFds, 0, 0, &lTimeout ) > 0 )
        {
            ZeroMemory( mReceiveBuffer, kReceiveBufferSize );
        
            int lBytesRecieved = recv( lSocket, mReceiveBuffer, kReceiveBufferSize, 0 );

            if ( lBytesRecieved == SOCKET_ERROR )
            {
                PROTO_ERROR( nProtocol::eProtocolError::ReceivingFailed, "Error in receiving process on socket", WSAGetLastError() );
                lConnectionToRemove.push_back( lSocket );
                continue;
            }
            if ( lBytesRecieved == 0 )
            {
                std::cout << "ERROR - Client disconnected. Socket: " << lSocket << std::endl;
                closesocket( lSocket );
                lConnectionToRemove.push_back( lSocket );
                continue;
            }

            std::cout << "RECIEVING - Received the following size: " << lBytesRecieved << std::endl;
            std::cout << "RECIEVING - Received the following message: " << mReceiveBuffer << std::endl;

            Send( lSocket );
        }
    }

    for ( const Socket_np& lSockToErase : lConnectionToRemove )
    {
        std::cout << "REMOVING - Removing dead socket connection: " << lSockToErase << std::endl;
        mNodeContainer.erase( std::remove( mNodeContainer.begin(), mNodeContainer.end(), lSockToErase ), mNodeContainer.end() );
    }

    lConnectionToRemove.clear();
}

Server::Server()
{}

Server::~Server()
{
    Deinitialize();
}

eProtocolError Server::Initialize()
{
    mTCPEndpointAddress.sin_family           = kSocketInFamily;
    mTCPEndpointAddress.sin_port             = htons( kSocketInPort );
    mTCPEndpointAddress.sin_addr.S_un.S_addr = kSocketInAdderss;

    mTCPSocket = socket( kSocketInFamily, kServerSocketType, kServerSocketProtocol );
    if ( mTCPSocket == INVALID_SOCKET )
    {
        PROTO_ERROR( eProtocolError::SocketCreationFailed, "TCP server socket creation failed!", WSAGetLastError() );
        return eProtocolError::SocketCreationFailed;
    }
    PROTO_INFO( "Server socket creation succeeded!" );

    const int lBindResult = bind( mTCPSocket, (SocketAddress_np*)&mTCPEndpointAddress, sizeof( mTCPEndpointAddress ) );
    if ( lBindResult == SOCKET_ERROR )
    {
        PROTO_ERROR( eProtocolError::SocketBindingFailed, "TCP server socket binding failed!!", WSAGetLastError() );
        return eProtocolError::SocketBindingFailed;
    }
    PROTO_INFO( "Server socket binding succeeded!" );

    const int lListenResult = listen( mTCPSocket, kNumerOfConnections );
    if ( lListenResult == SOCKET_ERROR )
    {
        PROTO_ERROR( eProtocolError::SocketListeningFailed, "Start listening failed!", WSAGetLastError() );
        return eProtocolError::SocketListeningFailed;
    }
    PROTO_INFO( "Listening started successfully!" );

    return eProtocolError::OK;
}

eProtocolError Server::Deinitialize()
{
    for ( auto lSocket : mNodeContainer )
    {
        closesocket( lSocket );
    }
    closesocket( mTCPSocket );
    WSACleanup();

    return eProtocolError::OK;
}

eProtocolError Server::Run()
{
    Accept();
    Recieve();

    return eProtocolError::OK;
}
