/*
 * Line.cpp
 *
 *  Created on: 02.04.2010
 *      Author: r2p2
 */

#include <curses.h>
#include <cmath>


#include "Line.h"

#include <iostream>
#include <fstream>

Line::Line(Point a, Point b)
:start(a), end(b)
{}

Line::~Line()
{}

void Line::rotate_x(double angle)
{
	cache.clear();

	start.rotate_x(angle);
	end.rotate_x(angle);
}

void Line::rotate_y(double angle)
{
	cache.clear();

	start.rotate_y(angle);
	end.rotate_y(angle);
}

void Line::rotate_z(double angle)
{
	cache.clear();

	start.rotate_z(angle);
	end.rotate_z(angle);
}

void Line::move_(double x_delta, double y_delta, double z_delta)
{
	cache.clear();

	start.move_(x_delta, y_delta, z_delta);
	end.move_(x_delta, y_delta, z_delta);
}

void Line::render(char c)
{
	if(cache.empty())
	{
		Point2d p = {0,0};

		int startx = start.screen_x();
		int starty = start.screen_y();
		int dx = end.screen_x()-startx;
		int dy = end.screen_y()-starty;

		int rx = 0;
		int ry = 0;

		int abs_dx = dx>=0?dx:dx*-1;
		int abs_dy = dy>=0?dy:dy*-1;

		int steps = abs_dx>abs_dy?dx:dy;
		if(steps<0) steps *= -1;

		float fx = (float)dx/steps;
		float fy = (float)dy/steps;

		for(int i = 0; i <= steps; i++)
		{
			rx = startx+fx*i;
			ry = starty+fy*i;
			mvaddch(ry, rx, c);

			p.x = rx;
			p.y = ry;
			cache.push_back(p);
		}
	}
	else
	{
		for(unsigned int i=0; i<cache.size(); i++)
		{
			mvaddch(cache[i].y, cache[i].x, c);
		}
	}
}
