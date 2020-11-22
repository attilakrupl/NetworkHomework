/*!
 * \file   server.h
 * \author Attila Kr�pl dr.
 * \date   22/11/2020
 */

#pragma once

namespace nProtocol
{
    class Server : public aSocket
    {
    private:
        static constexpr int kNumerOfConnections = 3;               /*! The maximum number of node connections */

    private:
        std::array<SOCKET, kNumerOfConnections> mNodeContainer;     /*! The node/connection container          */

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
