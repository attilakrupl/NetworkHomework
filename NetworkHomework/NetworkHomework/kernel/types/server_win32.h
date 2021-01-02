/*!
 * \file   server_win32.h
 * \author Attila Krüpl dr.
 * \date   29/12/2020
 */

#pragma once

namespace nProtocol
{
    class Server : public aSocket
    {
    private:
        static constexpr int kNumerOfConnections = SOMAXCONN;                  /*! The maximum number of node connections           */

    private:
        using ConnectionArray = std::vector<Socket_np>;                        /*! The connection container alias                   */

    private:
        int             mNumberOfConnections;                                  /*! The current total number of existing connections */
        ConnectionArray mNodeContainer;                                        /*! The node/connection container                    */

    private:
        char mSendBuffer[512] = "This is the send buffer!";                    /*! Dummy send buffer                                */
        int  mSendBufferSize  = (int)strlen( mSendBuffer ) + 1;                /*! Dummy send buffer size                           */

    public:
        Server();
        ~Server();

    public:
        virtual void Bind()     override;
        virtual void Listen()   override;
        virtual void Accept( SocketAddress_np* aTCPClientAddress, int* aTCPClientAddressLength )   override;
        virtual void Send()     override;
        virtual void Recieve()  override;
        virtual void Shutdown() override;
        virtual void Close()    override;
    };
}
