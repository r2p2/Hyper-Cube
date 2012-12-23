/*
 * main.cpp
 *
 *  Created on: 01.04.2010
 *      Author: r2p2
 *     Version: 1.2.0.1
 */


#include <unistd.h>
#include <signal.h>

#include "HyperCube.h"

static void onsig(int dummy __attribute__((__unused__)))
{
    // press q
}

int main()
{
    (void)signal(SIGHUP, onsig);
    (void)signal(SIGINT, onsig);
    (void)signal(SIGTERM, onsig);
    HyperCube hq;
    hq.loop();
    return 0;
}
