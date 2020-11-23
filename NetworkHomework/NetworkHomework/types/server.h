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
    private:
        static constexpr int kNumerOfConnections = 3;                       /*! The maximum number of node connections           */

    private:
        using ConnectionArray = std::array<SOCKET, kNumerOfConnections>;    /*! The connection container alias                   */

    private:
        int             mNumberOfConnections;                               /*! The current total number of existing connections */
        ConnectionArray mNodeContainer;                                     /*! The node/connection container                    */

    public:
        Server();
        ~Server();

    public:
        virtual void Bind()     override;
        virtual void Listen()   override;
        virtual void Accept( SOCKADDR* aTCPClientAddress, int* aTCPClientAddressLength )   override;
        virtual void Send()     override;
        virtual void Recieve()  override;
        virtual void Shutdown() override;
        virtual void Close()    override;
    };
}
