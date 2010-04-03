/*
 * main.cpp
 *
 *  Created on: 01.04.2010
 *      Author: r2p2
 */

#include <curses.h>
#include <unistd.h>
#include <signal.h>

#include "HyperCube.h"

bool running = true;

static void onsig(int dummy __attribute__((__unused__)))
{
	running = false;
}


int main()
{
	(void)signal(SIGHUP, onsig);
	(void)signal(SIGINT, onsig);
	(void)signal(SIGTERM, onsig);


	WINDOW *window = 0;
	window = initscr();

	HyperCube hc;

	while(running) {
		hc.rotate_y(0.2);
		hc.rotate_z(0.3);
		hc.rotate_x(0.5);

		hc.move_(0,0,-8);

		hc.render('#');
		refresh();
		hc.render(' ');
		move(0,0);

		hc.move_(0,0,8);

		usleep(20000);
	}

	endwin();

	return 0;
}
