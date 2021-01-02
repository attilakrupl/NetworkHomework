/*!
 * \file   main.cpp
 * \author Attila Krüpl dr.
 * \date   22/11/2020
 * 
 * \brief based on this tutorial: https://www.youtube.com/watch?v=TP5Q0cs6uNo&ab_channel=ASystemProgrammingChannel
 * \brief and this:               https://www.youtube.com/watch?v=WDn-htpBlnU&ab_channel=SloanKelly
 * 
 */

#include "stdafx.h"

using namespace nProtocol;

int main( int argc, char** argv )
{
    Server s;
    s.Bind();
    s.Listen();

    while ( true )
    {
        SocketAddress_np lClient;
        int lClientSize = sizeof( lClient );
        s.Accept( &lClient, &lClientSize );

        char lHost[NI_MAXHOST];
        char lService[NI_MAXSERV];

        ZeroMemory( lHost, NI_MAXHOST );
        ZeroMemory( lService, NI_MAXSERV );

        if ( getnameinfo((sockaddr*)&lClient, sizeof(lClient), lHost, NI_MAXHOST, lService, NI_MAXSERV, 0 ) == 0 )
        {
            std::cout << lHost << " connected on port " << lService << std::endl;
        }
        else
        {
            inet_ntop( AF_INET, &lClient.sin_addr, lHost, NI_MAXHOST );
        }

        Sleep( 1000 );
    }

    return 0;
}
