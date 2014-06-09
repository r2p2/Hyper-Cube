/*
 * HyperCube.h
 *
 *  Created on: 23.03.2011
 *      Author: r2p2
 */

#ifndef HyperCube_H_
#define HyperCube_H_

#include "Screen.h"
#include "camera.h"
#include "world.h"
#include "wire_renderer.h"

#include <unistd.h>

class HyperCube
{
    Screen       screen;
    Camera       camera;
    World        world;
    WireRenderer renderer;

    bool running;
    int delay;

public:
    HyperCube();
    virtual ~HyperCube();

    void loop();
    void set_default();
};

#endif /* HyperCube_H_ */
