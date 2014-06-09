/*
 * Point.h
 *
 *  Created on: 01.04.2010
 *      Author: r2p2
 */

#ifndef POINT_H_
#define POINT_H_

#include "Object3D.h"

class Point : public Object3D
{
public:
    Point(double x, double y, double z);
    virtual ~Point();

    double absolute() const;
    const Point& normalize();

    // Object3D
    virtual void rotate(double /*x*/, double /*y*/, double /*z*/);
    virtual void move(double /*x*/, double /*y*/, double /*z*/);
    virtual void move_to(double /*x*/, double /*y*/, double /*z*/);

    double x;
    double y;
    double z;
};

Point substract(const Point& /*p1*/, const Point& /*p2*/);
Point cross_product(const Point& /*p1*/, const Point& /*p2*/);

#endif /* POINT_H_ */
