/*
 * HyperCube.h
 *
 *  Created on: 01.04.2010
 *      Author: r2p2
 */

#ifndef HyperCube_H_
#define HyperCube_H_

#include "Screen.h"
#include "Line.h"
#include "Point.h"

class HyperCube
{
  Line *lines[12];

public:
  HyperCube();
  virtual ~HyperCube();

  void rotate_x(double angle);
  void rotate_y(double angle);
  void rotate_z(double angle);
  void move_(double x_delta, double y_delta, double z_delta);

  void render(Screen &s, char c);
};

#endif /* HyperCube_H_ */
