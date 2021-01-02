/*!
 * \file   protocoldefines.h
 * \author Attila Krüpl dr.
 * \date   31/12/2020
 */

#pragma once

namespace nProtocol
{
#ifdef _WIN64
    using SocketData_np      = WSADATA;
    using SocketAddressIn_np = sockaddr_in;
    using Socket_np          = SOCKET;
    using SocketAddress_np   = SOCKADDR;
#endif // _WIN64
}
