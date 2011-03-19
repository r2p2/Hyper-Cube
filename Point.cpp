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
:x(x), y(y), z(z)
{
}

Point::~Point()
{
}

void Point::rotate_x(double angle)
{
  double rad = angle/180*3.1415926535;

  double _y = std::cos(rad)*y - std::sin(rad)*z;
  double _z = std::sin(rad)*y + std::cos(rad)*z;

  y = _y;
  z = _z;
}

void Point::rotate_y(double angle)
{
  double rad = angle/180*3.1415926535;

  double _x =   std::cos(rad)*x + std::sin(rad)*z;
  double _z = - std::sin(rad)*x + std::cos(rad)*z;

  x = _x;
  z = _z;
}

void Point::rotate_z(double angle)
{
  double rad = angle/180*3.1415926535;

  double _x = std::cos(rad)*x - std::sin(rad)*y;
  double _y = std::sin(rad)*x + std::cos(rad)*y;

  x = _x;
  y = _y;
}

void Point::move_(double x_delta, double y_delta, double z_delta)
{
  x += x_delta;
  y += y_delta;
  z += z_delta;
}

void Point::render(Screen &s, char c)
{
  s.canvas[screen_y(s)][screen_x(s)] = c;
  //mvaddch(screen_y(s), , c);
}

int Point::screen_x(Screen &s)
{
  double sx = (x*2)/(0.1-z);
  double width = (double)s.width;
  return (int)(width*sx + width/2);
}

int Point::screen_y(Screen &s)
{
  double sy = (y*2)/(0.1-z);
  double height = (double)s.height;
  return (int)(height*sy + height/2);
}
