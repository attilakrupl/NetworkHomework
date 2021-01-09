/*!
 * \file   asocket.cpp
 * \author Attila Krüpl dr.
 * \date   22/11/2020
 */

#include "stdafx.h"

using namespace nProtocol;

aSocket::aSocket()
    : mWinSocketData()
    , mTCPEndpointAddress()
    , mTCPClientAddress()
    , mTCPSocket( 0 )
{
    const int lWSAStartupResult = WSAStartup( MAKEWORD( 2, 2 ), &mWinSocketData );
    if ( lWSAStartupResult )
    {
        PROTO_ERROR( eProtocolError::WSAStartupError, "Starting up WSA didn't succeed!", 0 );
    }
    PROTO_INFO( "Starting up WSA succeeded!" );
}
