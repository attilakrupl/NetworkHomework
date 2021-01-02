/*!
 * \file   server_win32.cpp
 * \author Attila Krüpl dr.
 * \date   29/12/2020
 */

#include "stdafx.h"

using namespace nProtocol;

Server::Server()
    : mNumberOfConnections( 0 )
{
    mTCPEndpointAddress.sin_family           = AF_INET;
    mTCPEndpointAddress.sin_port             = htons( 54000 );
    mTCPEndpointAddress.sin_addr.S_un.S_addr = INADDR_ANY;
    mTCPSocket                               = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
    if ( mTCPSocket == INVALID_SOCKET )
    {
        std::cout << "ERROR - TCP Server Socket creation failed! Error code: " << WSAGetLastError() << std::endl;
    }
    std::cout << "SUCCESS - Server socket creation succeeded!" << std::endl;
}

Server::~Server()
{}

void Server::Bind()
{
    const int lBindResult = bind( mTCPSocket, (SocketAddress_np*)&mTCPEndpointAddress, sizeof( mTCPEndpointAddress ) );
    if ( lBindResult == SOCKET_ERROR )
    {
        std::cout << "ERROR - Binding failed! Error code: " << WSAGetLastError() << std::endl;
    }
    std::cout << "SUCCESS - Binding succeeded!" << std::endl;
}

void Server::Listen()
{
    const int lListenResult = listen( mTCPSocket, kNumerOfConnections );
    if ( lListenResult == SOCKET_ERROR )
    {
        std::cout << "ERROR - Start listening failed! Error code: " << WSAGetLastError() << std::endl;
    }
    std::cout << "SUCCESS - Listening started successfully!" << std::endl;
}

void Server::Accept( SocketAddress_np* aTCPClientAddress, int* aTCPClientAddressLength )
{
    Socket_np lAcceptedSocket = accept( mTCPSocket, aTCPClientAddress, aTCPClientAddressLength );
    if ( lAcceptedSocket == INVALID_SOCKET )
    {
        std::cout << "ERROR - Accepting client connection failed! Error code: " << WSAGetLastError() << std::endl;
    }
    std::cout << "SUCCESS - Accepted client connection successfully!" << std::endl;
    mNumberOfConnections++;
    mNodeContainer.push_back( lAcceptedSocket );
}

void Server::Send()
{
    if ( mSendBufferSize != 0 )
    {
        int lSendResult;
        for ( Socket_np& lSocket : mNodeContainer )
        {
            if ( lSocket == NULL )
            {
                break;
            }

            lSendResult = send( lSocket, mSendBuffer, mSendBufferSize, 0 );
            if ( lSendResult == SOCKET_ERROR )
            {
                std::cout << "ERROR - Sending failed! Error code: " << WSAGetLastError() << std::endl;
            }
            std::cout << "SUCCESS - Sending to  successfully!" << std::endl;
        }
    }
}

void Server::Recieve()
{

}

void Server::Shutdown()
{

}

void Server::Close()
{

}
