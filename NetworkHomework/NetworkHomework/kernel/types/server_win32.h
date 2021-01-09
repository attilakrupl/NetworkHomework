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
        using ConnectionArray = std::vector<Socket_np>;                                  /*! The connection container alias                     */

    private:
        ConnectionArray mNodeContainer;                                                  /*! The node/connection container                      */

    private:
        char mReceiveBuffer[kReceiveBufferSize] = "";                                    /*! The receiver buffer buffer                         */
        char mSendBuffer[kSendBufferSize] = "MessageBack";                               /*! Dummy send buffer                                  */

    private:
        void Accept();
        void Recieve();
        void Send( const Socket_np& aSocket );

    public:
        Server();
        ~Server();

    public:
        virtual eProtocolError Initialize() override;
        virtual eProtocolError Deinitialize() override;
        virtual eProtocolError Run() override;
    };
}
