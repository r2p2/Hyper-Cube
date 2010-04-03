/*
 * main.cpp
 *
 *  Created on: 01.04.2010
 *      Author: r2p2
 */

#include <curses.h>
#include <unistd.h>
#include <signal.h>

#include "HyperQube.h"

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

	HyperQube hq;

	while(running) {
		hq.rotate_y(0.2);
		hq.rotate_z(0.3);
		hq.rotate_x(0.5);

		hq.move_(0,0,-8);

		hq.render('#');
		refresh();
		hq.render(' ');
		move(0,0);

		hq.move_(0,0,8);

		usleep(20000);

	}

	/*
	Point a(-0.8,0.8,-1);
	Point b(0.8,0.8,1);
	Line l(a,b);
	do {
		l.rotate_y(0.2);

		l.move_(0,0,-8);
		l.render('#');
		refresh();
		l.render(' ');
		move(0,0);
		usleep(20000);
		l.move_(0,0,8);
	} while(true);
	*/

	endwin();

	return 0;
}
