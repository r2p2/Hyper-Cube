/*
 * Object3D,h
 *
 * Created on: 20.03.2011
 *     Author: r2p2
 */

#ifndef OBJECT3D_H_
#define OBJECT3D_H_

class Object3D
{
public:
	Object3D();
	virtual ~Object3D();

	virtual void rotate(double /*x*/, double /*y*/, double /*z*/) = 0;
	virtual void move(double /*x*/, double /*y*/, double /*z*/) = 0;
	virtual void move_to(double /*x*/, double /*y*/, double /*z*/) = 0;
	// virtual void look_at(const Point& /*point*/) = 0; // put into camera
};

#endif
