/*
 * Point.h
 *
 *  Created on: 01.04.2010
 *      Author: r2p2
 */

#ifndef POINT_H_
#define POINT_H_

#include "Screen.h"

class Point
{
public:
	Point(double x, double y, double z);
	virtual ~Point();

	void rotate_x(double angle);
	void rotate_y(double angle);
	void rotate_z(double angle);
	void move_(double x_delta, double y_delta, double z_delta);

	void render(Screen &s, char c);
	int screen_x(Screen &s);
	int screen_y(Screen &s);

	double x;
	double y;
	double z;
};

#endif /* POINT_H_ */
