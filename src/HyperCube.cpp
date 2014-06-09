/*
 * HyperCube.cpp
 *
 *  Created on: 01.04.2010
 *      Author: r2p2
 */

#include "HyperCube.h"

#include "polygon.h"

HyperCube::HyperCube()
: screen()
, camera(Point(0, 0, -3), Point(0, 0, 1))
, world()
, renderer(world)
, running(false)
, delay(0)
{
    renderer.add_viewport(camera, screen);

    set_default();
}

HyperCube::~HyperCube()
{
}

void HyperCube::loop()
{
    running = true;

    while (running)
    {
        switch (screen.key_pressed())
        {
        case '+':

            if (delay - 100 > 0)
                delay -= 100;

            break;
        case '-':

            if (delay + 100 > 1000000)
                delay += 100;

            break;
        case '6':
            camera.rotate(0, 1, 0);
            break;
        case '4':
            camera.rotate(0, -1, 0);
            break;
        case '8':
            camera.rotate(1, 0, 0);
            break;
        case '2':
            camera.rotate(-1, 0, 0);
            break;
        case '1':
            camera.rotate(0, 0, -1);
            break;
        case '3':
            camera.rotate(0, 0, 1);
            break;
        case '5':
            set_default();
            break;
        case '!':
            //world.clear();
            //world.add(new Cube());
            break;
        case '"':
            //world.clear();
            //world.add(new Pyramid());
            break;
        case 'q':
            running = false;
        default:
            break;
        }

        if (screen.is_size_changed())
            screen.on_size_changed();

	renderer.render();
        //object->render(screen, '#');
        //screen.render();
        //object->render(screen, ' ');

        usleep(delay);
    }
}

void HyperCube::set_default()
{
    delay = 20000;
    camera.move_to(0.0, 0.0, -2.0);
    camera.look_at(Point(0.0, 0.0, 0.1));
    world.add(new Polygon(Point(-1, -1, 0), Point(1, -1, 0), Point(0, 1, 0)));
}
