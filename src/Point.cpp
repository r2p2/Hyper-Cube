/*
 * Point.cpp
 *
 *  Created on: 01.04.2010
 *      Author: r2p2
 */

#include "Point.h"
#include "matrix.h"

#include <cmath>
#include <curses.h>

Point::Point(double x, double y, double z)
: x(x)
, y(y)
, z(z)
{
}

Point::~Point()
{
}

double Point::absolute() const
{
    return sqrt(x*x+y*y+z*z);
}

const Point& Point::normalize()
{
    double abs = absolute();
    x /= abs;
    y /= abs;
    z /= abs;
    return *this;
}

void Point::move(double x, double y, double z)
{
	this->x += x;
	this->y += y;
	this->z += z;
}

void Point::move_to(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Point::rotate(double x, double y, double z)
{
	const Matrix rot_x = make_rotation_matrix_x(x);
	const Matrix rot_y = make_rotation_matrix_y(y);
	const Matrix rot_z = make_rotation_matrix_z(z);

	Point p(x, y, z);
	p = multiply(rot_x, p);
	p = multiply(rot_y, p);
	p = multiply(rot_z, p);

	// TODO refactoring
	x = p.x;
	y = p.y;
	z = p.z;
}

Point substract(const Point& p1, const Point& p2)
{
    return Point(p2.x-p1.x, p2.y-p1.y, p2.z-p1.z);
}

Point cross_product(const Point& p1, const Point& p2)
{
    return Point(
            p1.y*p2.z - p1.z*p2.y,
            p1.z*p2.x - p1.x*p2.z,
            p1.x*p2.y - p1.y*p2.x
        );
}
