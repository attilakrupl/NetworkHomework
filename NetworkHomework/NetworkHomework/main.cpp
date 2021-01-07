/*!
 * \file   main.cpp
 * \author Attila Krüpl dr.
 * \date   22/11/2020
 * 
 * \brief based on this tutorial: https://www.youtube.com/watch?v=TP5Q0cs6uNo&ab_channel=ASystemProgrammingChannel
 * \brief and this:               https://www.youtube.com/watch?v=WDn-htpBlnU&ab_channel=SloanKelly
 * \brief design pattern:         https://vichargrave.github.io/programming/tcp-ip-network-programming-design-patterns-in-cpp/
 * \brief another example:        https://www.installsetupconfig.com/win32programming/windowsocketwinsock214_12.html
 * 
 */

#include "stdafx.h"

using namespace nProtocol;
using namespace std;

int main( int argc, char** argv )
{
    Server lServerInstance;

    if ( lServerInstance.Initialize() != eProtocolError::OK )
    {
        return -1;
    }

    bool lShouldBeRunning = true;

    while ( lShouldBeRunning )
    {
        lServerInstance.Run();
    }

    return 0;
}