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
using namespace std;

//int main( int argc, char** argv )
//{
//    WSADATA lWsaData;
//    WORD lVersion = MAKEWORD( 2, 2 );
//
//    int lWSOk = WSAStartup( lVersion, &lWsaData );
//    if ( lWSOk != 0 )
//    {
//        cerr << "Can't initialize WinSock" << endl;
//        return -1;
//    }
//
//    SOCKET lListening = socket( AF_INET, SOCK_STREAM, 0 );
//    if ( lListening == INVALID_SOCKET )
//    {
//        cerr << "Can't create socket" << endl;
//        return -2;
//    }
//
//    sockaddr_in lHint;
//    lHint.sin_family = AF_INET;
//    lHint.sin_port = htons( 54000 );
//    lHint.sin_addr.S_un.S_addr = INADDR_ANY;
//
//    bind( lListening, (sockaddr*)&lHint, sizeof( lHint ) );
//
//    listen( lListening, SOMAXCONN );
//
//    sockaddr_in lClient;
//    int lClientSize = sizeof( lClient );
//
//    SOCKET lClientSocket = accept( lListening, (sockaddr*)&lClient, &lClientSize );
//    if ( lClientSocket == INVALID_SOCKET )
//    {
//        std::cout << "ERROR - Accepting client connection failed! Error code: " << WSAGetLastError() << std::endl;
//        return -3;
//    }
//
//    char lHost[NI_MAXHOST];
//    char lService[NI_MAXSERV];
//
//    ZeroMemory( lHost, NI_MAXHOST );
//    ZeroMemory( lService, NI_MAXSERV );
//
//    if ( getnameinfo( (sockaddr*)&lClient, sizeof( lClient ), lHost, NI_MAXHOST, lService, NI_MAXSERV, 0 ) == 0 )
//    {
//        std::cout << "SUCCESS - " << lHost << " connected on port " << lService << std::endl;
//    }
//    else
//    {
//        inet_ntop( AF_INET, &lClient.sin_addr, lHost, NI_MAXHOST );
//        std::cout << "SUCCESS - " << lHost << " connected on port " << ntohs( lClient.sin_port ) << std::endl;
//    }
//
//    char lBuffer[4096];
//
//    while( true )
//    {
//        ZeroMemory( lBuffer, 4096 );
//
//        int lBytesReceived = recv(lClientSocket, lBuffer, 4096, 0);
//        if ( lBytesReceived == SOCKET_ERROR )
//        {
//            cerr << "Error in receiving process." << endl;
//            break;
//        }
//
//        if ( lBytesReceived == 0 )
//        {
//            cout << "Client disconnected" << endl;
//            break;
//        }
//
//        std::cout << "RECIEVING - Received the following size: " << lBytesReceived << std::endl;
//        std::cout << "RECIEVING - Received the following message: " << lBuffer << std::endl;
//
//        send( lClientSocket, lBuffer, lBytesReceived + 1, 0);
//    }
//
//
//    closesocket( lListening );
//    closesocket( lClientSocket );
//
//    WSACleanup();
//
//    return 0;
//}

int main( int argc, char** argv )
{
    Server lServerInstance;

    if ( lServerInstance.Initialize() != eProtocolError::OK )
    {
        return -1;
    }

    bool lHasBeenStarted = false;

    while( true )
    {
        if ( !lHasBeenStarted )
        {
            lServerInstance.Run();
            lHasBeenStarted = true;
        }

        Sleep(50);
    }



    return 0;
}