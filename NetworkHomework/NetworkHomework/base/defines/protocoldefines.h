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

    #define __FILENAME__ (strrchr(__FILE__, '\\') ? std::string(strrchr(__FILE__, '\\') + 1) : std::string(__FILE__) )
    #define PROTO_ERROR( aError, aMessage, aSystemError ) std::cout << "ERROR! Error number is: " << (int)aError << " Message: " << aMessage << " System error: " << aSystemError << " File: " << __FILENAME__ << " Line: " << __LINE__ << std::endl;
    #define PROTO_INFO( aMessage ) std::cout << "INFO! " << aMessage << std::endl;
}
