/*
 * main.cpp
 *
 *  Created on: 01.04.2010
 *      Author: r2p2
 */


#include <unistd.h>
#include <signal.h>

#include "HyperCube.h"

bool running = true;

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
