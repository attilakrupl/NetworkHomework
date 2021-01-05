/*!
 * \file   client_win32.cpp
 * \author Attila Krüpl dr.
 * \date   29/12/2020
 */

#include "stdafx.h"

using namespace nProtocol;

Client::Client()
{}

Client::~Client()
{}

eProtocolError Client::Initialize()
{
    return eProtocolError::OK;
}

eProtocolError Client::Deinitialize()
{
    return eProtocolError::OK;
}

eProtocolError Client::Run()
{
    return eProtocolError::OK;
}

