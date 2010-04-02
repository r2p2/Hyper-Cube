/*
 * Line.cpp
 *
 *  Created on: 02.04.2010
 *      Author: r2p2
 */

#include "Line.h"

Line::Line(Point a, Point b)
:start(a), end(b)
{}

Line::~Line()
{}

void Line::rotate_x(double angle)
{
	start.rotate_x(angle);
	end.rotate_x(angle);
}

void Line::rotate_y(double angle)
{
	start.rotate_y(angle);
	end.rotate_y(angle);
}

void Line::rotate_z(double angle)
{
	start.rotate_z(angle);
	end.rotate_z(angle);
}

void Line::move_(double x_delta, double y_delta, double z_delta)
{
	start.move_(x_delta, y_delta, z_delta);
	end.move_(x_delta, y_delta, z_delta);
}

void Line::render(char c)
{
	Point p(0,0,0);

	double dx = end.x-start.x;
	double dy = end.y-start.y;
	double dz = end.z-start.z;

	double steps = 50;
	for(double i = 0; i <= 1; i+=1.0/steps)
	{
		p.x = start.x+dx*i;
		p.y = start.y+dy*i;
		p.z = start.z+dz*i;

		p.render(c);
	}
}
