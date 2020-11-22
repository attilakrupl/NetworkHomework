/*!
 * \file   stdafx.h
 * \author Attila Krüpl dr.
 * \date   22/11/2020
 */

#pragma once

#ifdef _WIN64
    #define _WINSOCK_DEPRECATED_NO_WARNINGS

    #include <WinSock2.h>
    #include <WS2tcpip.h>
#endif // WIN32

#include <iostream>
#include <array>

#include "types/asocket.h"
#include "types/server.h"
#include "types/client.h"
