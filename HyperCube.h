/*
 * HyperCube.h
 *
 *  Created on: 23.03.2011
 *      Author: r2p2
 */

#ifndef HyperCube_H_
#define HyperCube_H_

#include "Screen.h"
#include "Object3D.h"

class HyperCube : public Object3D
{
  WINDOW *window = 0;
  Screen screen;
  Object3D *object;

public:
  HyperCube();
  virtual ~HyperCube();
};

#endif /* HyperCube_H_ */