/*!
 * \file   protocolerrors.h
 * \author Attila Krüpl dr.
 * \date   04/01/2021
 */

#pragma once

namespace nProtocol
{
    enum class eProtocolError
    {
          Undefined            = -1
        , OK                   = 0
        , SocketCreationFailed = 66000
        , SocketBindingFailed
        , SocketListeningFailed
        , WSAStartupError
        , Last
    };
}