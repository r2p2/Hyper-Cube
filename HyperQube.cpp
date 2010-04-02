/*
 * HyperQube.cpp
 *
 *  Created on: 01.04.2010
 *      Author: r2p2
 */

#include "HyperQube.h"

HyperQube::HyperQube()
{
	Point *points[8];
	points[0] = new Point(-0.9, -0.9, +0.9);
	points[1] = new Point(+0.9, -0.9, +0.9);
	points[2] = new Point(+0.9, +0.9, +0.9);
	points[3] = new Point(-0.9, +0.9, +0.9);
	points[4] = new Point(-0.9, -0.9, -0.9);
	points[5] = new Point(+0.9, -0.9, -0.9);
	points[6] = new Point(+0.9, +0.9, -0.9);
	points[7] = new Point(-0.9, +0.9, -0.9);

	lines[0] = new Line(*points[0], *points[1]);
	lines[1] = new Line(*points[1], *points[2]);
	lines[2] = new Line(*points[2], *points[3]);
	lines[3] = new Line(*points[0], *points[3]);
	lines[4] = new Line(*points[4], *points[5]);
	lines[5] = new Line(*points[5], *points[6]);
	lines[6] = new Line(*points[6], *points[7]);
	lines[7] = new Line(*points[7], *points[4]);
	lines[8] = new Line(*points[0], *points[4]);
	lines[9] = new Line(*points[1], *points[5]);
	lines[10] = new Line(*points[2], *points[6]);
	lines[11] = new Line(*points[3], *points[7]);

	for(int i = 0; i < 8; i++)
	{
		delete points[i];
	}
}

HyperQube::~HyperQube()
{
	for(int i = 0; i < 12; i++)
	{
		delete lines[i];
	}
}

void HyperQube::rotate_y(double angle)
{
	for(int i = 0; i < 12; i++)
	{
		lines[i]->rotate_y(angle);
	}
}

void HyperQube::rotate_x(double angle)
{
	for(int i = 0; i < 12; i++)
	{
		lines[i]->rotate_x(angle);
	}
}

void HyperQube::rotate_z(double angle)
{
	for(int i = 0; i < 12; i++)
	{
		lines[i]->rotate_z(angle);
	}
}

void HyperQube::move_(double x_delta, double y_delta, double z_delta)
{
	for(int i = 0; i < 12; i++)
	{
		lines[i]->move_(x_delta, y_delta, z_delta);
	}
}

void HyperQube::render(char c)
{
	for(int i = 0; i < 12; i++)
	{
		lines[i]->render(c);
	}
}
