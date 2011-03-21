/*
 * Point.cpp
 *
 *  Created on: 01.04.2010
 *      Author: r2p2
 */

#include "Point.h"

#include <cmath>
#include <curses.h>

Point::Point(double x, double y, double z)
:Object3D(x, y, z)
{
}

Point::~Point()
{
}

void Point::rotate_x(double angle)
{
  double rad = angle/180*3.1415926535;

  double _y = std::cos(rad)*center_y - std::sin(rad)*center_z;
  double _z = std::sin(rad)*center_y + std::cos(rad)*center_z;

  y = _y;
  z = _z;
}

void Point::rotate_y(double angle)
{
  double rad = angle/180*3.1415926535;

  double _x =   std::cos(rad)*center_x + std::sin(rad)*center_z;
  double _z = - std::sin(rad)*center_x + std::cos(rad)*center_z;

  x = _x;
  z = _z;
}

void Point::rotate_z(double angle)
{
  double rad = angle/180*3.1415926535;

  double _x = std::cos(rad)*center_x - std::sin(rad)*center_y;
  double _y = std::sin(rad)*center_x + std::cos(rad)*center_y;

  center_x = _x;
  center_y = _y;
}

void Point::move_(double x_delta, double y_delta, double z_delta)
{
  center_x += x_delta;
  center_y += y_delta;
  center_z += z_delta;
}

void Point::render(Screen &s, char c)
{
  s.canvas[screen_y(s)][screen_x(s)] = c;
}

int Point::screen_x(Screen &s)
{
  double sx = (center_x*2)/(0.1-center_z);
  double width = (double)s.width;
  return (int)(width*sx + width/2);
}

int Point::screen_y(Screen &s)
{
  double sy = (y*2)/(0.1-z);
  double height = (double)s.height;
  return (int)(height*sy + height/2);
}
