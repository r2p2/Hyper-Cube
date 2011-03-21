/*
 * Line.h
 *
 *  Created on: 02.04.2010
 *      Author: r2p2
 */

#ifndef LINE_H_
#define LINE_H_

#include <vector>

#include "Screen.h"
#include "Object3D.h"
#include "Point.h"

struct Point2d {
  int x, y;
};

class Line : public Object3D
{
  std::vector<Point2d> cache;

  Point start;
  Point end;

  int sgn(int);

public:
  Line(Point a, Point b);
  virtual ~Line();

  void rotate_x(double angle);
  void rotate_y(double angle);
  void rotate_z(double angle);
  void move_(double x_delta, double y_delta, double z_delta);

  void render(Screen &s, char c);

private:
  void render_new(Screen &s, char c);
  void render_cache(Screen &s, char c);
};

#endif /* LINE_H_ */
