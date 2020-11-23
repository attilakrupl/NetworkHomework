/*!
 * \file   asocket.h
 * \author Attila Krüpl dr.
 * \date   22/11/2020
 */

#pragma once

namespace nProtocol
{
    class aSocket
    {
    protected:
        WSADATA     mWinSocketData;
        sockaddr_in mTCPEndpointAddress;
        sockaddr_in mTCPClientAddress;
        SOCKET      mTCPSocket;

    protected:
        aSocket();

    public:
        virtual void Bind();
        virtual void Listen();
        virtual void Connect();
        virtual void Accept( SOCKADDR* aTCPClientAddress, int* aTCPClientAddressLength );
    public:
        virtual void Send()     = 0;
        virtual void Recieve()  = 0;
        virtual void Shutdown() = 0;
        virtual void Close()    = 0;
    };
}