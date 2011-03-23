/*
 * Cube.h
 *
 *  Created on: 01.04.2010
 *      Author: r2p2
 */

#ifndef Cube_H_
#define Cube_H_

#include "Screen.h"
#include "Object3D.h"
#include "Line.h"
#include "Point.h"

class Cube : public Object3D
{
  Line *lines[12];

public:
  Cube();
  virtual ~Cube();

  void rotate_x(double angle);
  void rotate_y(double angle);
  void rotate_z(double angle);
  void move_(double x_delta, double y_delta, double z_delta);

  void render(Screen &s, char c);
};

#endif /* Cube_H_ */
