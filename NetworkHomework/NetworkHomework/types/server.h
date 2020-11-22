/*!
 * \file   server.h
 * \author Attila Krüpl dr.
 * \date   22/11/2020
 */

#pragma once

namespace nProtocol
{
    class Server : public aSocket
    {
    public:
        Server();
        ~Server();

    public:
        virtual void Bind()     override;
        virtual void Listen()   override;
        virtual void Accept()   override;
        virtual void Send()     override;
        virtual void Recieve()  override;
        virtual void Shutdown() override;
        virtual void Close()    override;
    };
}
