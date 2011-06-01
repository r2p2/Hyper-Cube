/*
 * HyperCube.cpp
 *
 *  Created on: 01.04.2010
 *      Author: r2p2
 */

#include "HyperCube.h"

HyperCube::HyperCube()
:screen()
,object(new Cube())
,running(false)
,rot_x(0)
,rot_y(0)
,rot_z(0)
,delay(0)
{
  set_default();
}

HyperCube::~HyperCube()
{
}

void HyperCube::loop()
{
  running = true;
  
  while(running) {
    switch(screen.key_pressed())
    {
      case '+':
        if(delay-100 > 0)
        delay -= 100;
        break;
      case '-':
        if(delay+100 > 1000000)
        delay += 100;
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
      case '1':
	rot_z -= 0.1;
	break;
      case '3':
	rot_z += 0.1;
	break;
      case '5':
        set_default();
        break;
      case 'q':
        running = false;
      default:
         break;
    }

    object->rotate_y(rot_y);
    object->rotate_z(rot_z);
    object->rotate_x(rot_x);

    object->move_(0,0,-8);

    if(screen.is_size_changed())
      screen.on_size_changed();

    object->render(screen, '#');
    screen.render();
    object->render(screen, ' ');
    move(0,0);

    object->move_(0,0,8);

    usleep(delay);
  }
}

void HyperCube::set_default()
{
  rot_x = 0;
  rot_y = 0;
  rot_z = 0;
  delay = 20000;
}
