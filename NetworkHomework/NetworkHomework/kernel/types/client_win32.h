/*!
 * \file   client_win32.h
 * \author Attila Krüpl dr.
 * \date   29/12/2020
 */

#pragma once

namespace nProtocol
{
    class Client : public aSocket
    {
    public:
        Client();
        ~Client();

    public:
        virtual void Connect()  override;
        virtual void Send()     override;
        virtual void Recieve()  override;
        virtual void Shutdown() override;
        virtual void Close()    override;
    };
}
