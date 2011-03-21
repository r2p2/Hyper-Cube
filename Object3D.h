/*
 * Object3D,h
 *
 * Created on: 20.03.2011
 *     Author: r2p2
 */

#ifndef OBJECT3D_H_
#define OBJECT3D_H_

class Object3D
{
public:
  Object3D();
  virtual ~Object3D();

  virtual void rotate_x(double angle) = 0;
  virtual void rotate_y(double angle) = 0;
  virtual void rotate_z(double angle) = 0;
  virtual void move_(double x_delta, double y_delta, double z_delta) = 0;
};

#endif