/*!
 * \file   main.cpp
 * \author Attila Kr�pl dr.
 * \date   22/11/2020
 */

#include "stdafx.h"

using namespace nProtocol;

int main( int argc, char** argv )
{
    Server s;
    s.Bind();
    s.Listen();


    return 0;
}
