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
        bool            mShouldRunning;                                                  /*! The threaded services should be running or not     */
        std::mutex      mMutex;                                                          /*! The mutex used to protect the container            */

    private:
        char mRecieveBuffer[kSendBufferSize];                                            /*! The reciever buffer buffer                         */
        char mSendBuffer[kSendBufferSize] = "Message back";                              /*! Dummy send buffer                                  */
        int  mSendBufferSize              = (int)strlen( mSendBuffer ) + 1;              /*! Dummy send buffer size                             */

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
