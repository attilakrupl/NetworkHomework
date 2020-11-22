/*!
 * \file   asocket.cpp
 * \author Attila Krüpl dr.
 * \date   22/11/2020
 */

#include "stdafx.h"

using namespace nProtocol;

aSocket::aSocket()
{
    const int lWSAStartupResult = WSAStartup( MAKEWORD( 2, 2 ), &mWinSocketData );
    if ( lWSAStartupResult )
    {
        std::cout << "ERROR - Starting up WSA didn't succeed! Error code: " << lWSAStartupResult << std::endl;
    }
    std::cout << "SUCCESS - Starting up WSA succeeded!" << std::endl;
}

void aSocket::Bind()
{}

void aSocket::Listen()
{}

void aSocket::Connect()
{}

void aSocket::Accept()
{}
