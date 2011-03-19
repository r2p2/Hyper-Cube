/*
 * main.cpp
 *
 *  Created on: 01.04.2010
 *      Author: r2p2
 */

#include <curses.h>
#include <unistd.h>
#include <signal.h>

#include "Screen.h"
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
    
    int key = 0;

    double def_rot_x = 0.0;
    double def_rot_y = 0.0;
    double def_rot_z = 0.0;
    int def_sleep = 20000;

    double rot_x = def_rot_x;
    double rot_y = def_rot_y;
    double rot_z = def_rot_z;
    int sleep = def_sleep;

	WINDOW *window = 0;
	window = initscr();
    wtimeout(window, 0);

	Screen s;
	HyperCube hc;

	while(running) {
        key = wgetch(window);
        switch(key)
        {
            case '+':
                if(sleep-100 > 0)
                    sleep -= 100;
                break;
            case '-':
                if(sleep+100 > 1000000)
                    sleep += 100;
                break;
            case '6':
                rot_y += 0.1;
                break;
            case '4':
                rot_y -= 0.1;
                break;
            case '8':
                rot_x += 0.1;
                break;
            case '2':
                rot_x -= 0.1;
                break;
            case '5':
                rot_x = def_rot_x;
                rot_y = def_rot_y;
                rot_z = def_rot_z;
                sleep = def_sleep;
                break;
            case 'q':
                running = false;
            default:
                break;
        }


		hc.rotate_y(rot_y);
		hc.rotate_z(rot_z);
		hc.rotate_x(rot_x);

		hc.move_(0,0,-8);

		if(s.is_size_changed())
			s.on_size_changed();

		hc.render(s, '#');
		s.render();
		hc.render(s, ' ');
		move(0,0);

		hc.move_(0,0,8);

		usleep(sleep);
	}
	endwin();

	return 0;
}
