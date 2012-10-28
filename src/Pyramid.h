/*
 * Pyramid.h
 *
 *  Created on: 02.06.2011
 *      Author: r2p2
 */

#ifndef Pyramid_H_
#define Pyramid_H_

#include "Screen.h"
#include "Object3D.h"
#include "Line.h"
#include "Point.h"

class Pyramid : public Object3D
{
  Line *lines[8];

public:
  Pyramid();
  virtual ~Pyramid();

  void rotate_x(double angle);
  void rotate_y(double angle);
  void rotate_z(double angle);
  void move_(double x_delta, double y_delta, double z_delta);

  void render(Screen &s, char c);
};

#endif /* Pyramid_H_ */
