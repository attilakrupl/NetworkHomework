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
        static constexpr int            kNumerOfConnections     = SOMAXCONN;      /*! The maximum number of node connections             */
        static constexpr int            kSendBufferSize         = 4096;           /*! The maximum number of bytes a send buffer can hold */
        static constexpr int            kReceiveBufferSize      = 4096;           /*! The maximum number of bytes the buffer can receive */
        static constexpr short          kSocketInFamily         = AF_INET;        /*! The socket family                                  */
        static constexpr unsigned short kSocketInPort           = 54000;          /*! The client socket port                             */
        static constexpr unsigned long  kSocketInAdderss        = INADDR_ANY;     /*! The client socket address                          */
        static constexpr int            kServerSocketType       = SOCK_STREAM;    /*! The server socket type                             */
        static constexpr int            kServerSocketProtocol   = IPPROTO_TCP;    /*! The server socket protocol                         */
        static constexpr int            kServerReadPollFlag     = POLLRDNORM;     /*! The read poll flag                                 */
        static constexpr int            kServerPollREvents      = 0;              /*! The default server poll revents                    */
        static constexpr int            kNumberOfServerSockets  = 1;              /*! The number of server sockets to be polled          */
        static constexpr int            kPollTimeoutTimeOutMicS = 1000;           /*! The poll timeout value (microseconds)              */
        static constexpr int            kPollTimeoutTimeOutMilS = 1;              /*! The poll timeout value (milliseconds)              */
        static constexpr int            kPollTimeoutTimeOutSec  = 0;              /*! The poll timeout value (seconds)                   */

    protected:
        SocketData_np      mWinSocketData;
        SocketAddressIn_np mTCPEndpointAddress;
        SocketAddressIn_np mTCPClientAddress;
        Socket_np          mTCPSocket;

    protected:
        aSocket();

    public:
        virtual eProtocolError Initialize() = 0;
        virtual eProtocolError Deinitialize() = 0;
        virtual eProtocolError Run() = 0;
    };
}