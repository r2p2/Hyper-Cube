/*
 * Pyramid.cpp
 *
 *  Created on: 02.06.2011
 *      Author: r2p2
 */

#include "Pyramid.h"

Pyramid::Pyramid()
    : Object3D()
{
    Point points[5] =
    {
        Point(-0.9, +0.9, -0.9),
        Point(-0.9, -0.9, -0.9),
        Point(+0.9, -0.9, -0.9),
        Point(+0.9, +0.9, -0.9),
        Point( 0.0,  0.0, +0.9),
    };
    lines[0] = new Line(points[0], points[1]);
    lines[1] = new Line(points[1], points[2]);
    lines[2] = new Line(points[2], points[3]);
    lines[3] = new Line(points[0], points[3]);
    lines[4] = new Line(points[4], points[0]);
    lines[5] = new Line(points[4], points[1]);
    lines[6] = new Line(points[4], points[2]);
    lines[7] = new Line(points[4], points[3]);
}

Pyramid::~Pyramid()
{
    for (int i = 0; i < 8; i++)
    {
        delete lines[i];
    }
}

void Pyramid::rotate_y(double angle)
{
    for (int i = 0; i < 8; i++)
    {
        lines[i]->rotate_y(angle);
    }
}

void Pyramid::rotate_x(double angle)
{
    for (int i = 0; i < 8; i++)
    {
        lines[i]->rotate_x(angle);
    }
}

void Pyramid::rotate_z(double angle)
{
    for (int i = 0; i < 8; i++)
    {
        lines[i]->rotate_z(angle);
    }
}

void Pyramid::move_(double x_delta, double y_delta, double z_delta)
{
    for (int i = 0; i < 8; i++)
    {
        lines[i]->move_(x_delta, y_delta, z_delta);
    }
}

void Pyramid::render(Screen& s, char c)
{
    for (int i = 0; i < 8; i++)
    {
        lines[i]->render(s, c);
    }
}
