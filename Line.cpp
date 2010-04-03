/*
 * Line.cpp
 *
 *  Created on: 02.04.2010
 *      Author: r2p2
 */

#include <curses.h>
#include <cmath>

#include "Line.h"

Line::Line(Point a, Point b)
:start(a), end(b)
{}

Line::~Line()
{}

int Line::sgn(int x){
  return (x > 0) ? 1 : (x < 0) ? -1 : 0;
}

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
		/* nach Bresenham */
		Point2d p = {0,0};

		int x, y, t, pdx, pdy, ddx, ddy, es, el, err;

		int startx = start.screen_x();
		int starty = start.screen_y();
		int endx = end.screen_x();
		int endy = end.screen_y();

		int dx = endx-startx;
		int dy = endy-starty;

		int incx = sgn(dx);
		int incy = sgn(dy);

		if(dx<0) dx = -dx;
		if(dy<0) dy = -dy;

		if (dx>dy)
		{
			pdx = incx;
			pdy = 0;
			ddx = incx;
			ddy = incy;
			es = dy;
			el = dx;
		}
		else
		{
			pdx = 0;
			pdy = incy;
			ddx = incx;
			ddy = incy;
			es = dx;
			el = dy;
		}

		x = startx;
		y = starty;
		err = el/2;

		mvaddch(y, x, c);
		p.x = x;
		p.y = y;
		cache.push_back(p);

		for(t=0; t<el; ++t)
		{
			err -= es;
			if(err<0)
			{
				err += el;
				x += ddx;
				y += ddy;
			}
			else
			{
				x += pdx;
				y += pdy;
			}
			mvaddch(y, x, c);
			p.x = x;
			p.y = y;
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
