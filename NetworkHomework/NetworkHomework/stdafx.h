/*!
 * \file   stdafx.h
 * \author Attila Krüpl dr.
 * \date   22/11/2020
 */

#pragma once

#include <iostream>
#include <array>
#include <vector>

#ifdef _WIN64
    #define _WINSOCK_DEPRECATED_NO_WARNINGS

    #include <WinSock2.h>
    #include <WS2tcpip.h>

    #pragma comment (lib, "ws2_32.lib")
#endif // WIN64

#include "base/defines/protocoldefines.h"

#include "types/asocket.h"

#ifdef _WIN64
    #include "kernel/types/server_win32.h"
    #include "kernel/types/client_win32.h"
#endif // WIN64
