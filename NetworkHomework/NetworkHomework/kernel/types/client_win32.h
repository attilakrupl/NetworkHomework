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
        virtual eProtocolError Initialize() override;
        virtual eProtocolError Deinitialize() override;
        virtual eProtocolError Run() override;
    };
}
