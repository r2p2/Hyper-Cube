/*
 * HyperCube.h
 *
 *  Created on: 23.03.2011
 *      Author: r2p2
 */

#ifndef HyperCube_H_
#define HyperCube_H_

#include <curses.h>

#include "Screen.h"
#include "Object3D.h"
#include "Cube.h"

class HyperCube
{
  WINDOW *window;
  Screen screen;
  Object3D *object;
  
  bool running;
  double rot_x;
  double rot_y;
  double rot_z;
  int delay;
  
public:
  HyperCube();
  virtual ~HyperCube();
  
  void loop();
  void set_default();
};

#endif /* HyperCube_H_ */