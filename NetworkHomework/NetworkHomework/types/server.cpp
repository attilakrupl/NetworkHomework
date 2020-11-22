/*!
 * \file   server.cpp
 * \author Attila Kr�pl dr.
 * \date   22/11/2020
 */

#include "stdafx.h"

using namespace nProtocol;

static constexpr int kNumerOfConnections = 3;       /*! The maximum number of connections */

Server::Server()
{
             mTCPEndpointAddress.sin_family    = AF_INET;
             mTCPEndpointAddress.sin_port      = htons( 1985 );
    hostent* lHostByName                       = gethostbyname( "127.0.0.1" );
    memcpy( &mTCPEndpointAddress.sin_addr, lHostByName->h_addr, lHostByName->h_length );

    mTCPSocket = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
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
    const int lBindResult = bind( mTCPSocket, (SOCKADDR*)&mTCPEndpointAddress, sizeof( mTCPEndpointAddress ) );
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

void Server::Accept()
{

}

void Server::Send()
{

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