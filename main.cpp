/*
 * main.cpp
 *
 *  Created on: 01.04.2010
 *      Author: r2p2
 */

#include <curses.h>
#include <unistd.h>
#include "HyperQube.h"
#include <iostream>

int main()
{
	WINDOW *window = 0;
	window = initscr();
	//clear();

	HyperQube hq;
	do {
		hq.rotate_y(0.2);
		hq.rotate_z(0.3);
		hq.rotate_x(0.5);
		hq.move_(0,0,-8);
		hq.render('#');
		refresh();
		hq.render(' ');
		move(0,0);
		usleep(20000);
		hq.move_(0,0,8);
	} while(true);

	endwin();

	return 0;
}
