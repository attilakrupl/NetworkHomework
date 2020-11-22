/*!
 * \file   main.cpp
 * \author Attila Krüpl dr.
 * \date   22/11/2020
 * 
 * \brief based on this tutorial: https://www.youtube.com/watch?v=TP5Q0cs6uNo&ab_channel=ASystemProgrammingChannel
 * 
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
