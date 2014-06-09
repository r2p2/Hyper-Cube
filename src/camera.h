#ifndef __camera_h__
#define __camera_h__

#include "Point.h"

class Camera : public Object3D
{
public:
	Camera(const Point& /*position*/, const Point& /*orientation*/);
	virtual ~Camera ();

	void look_at(const Point& point);

	// Object3D
	virtual void rotate(double /*x*/, double /*y*/, double /*z*/);
	virtual void move(double /*x*/, double /*y*/, double /*z*/);
	virtual void move_to(double /*x*/, double /*y*/, double /*z*/);

private:
	Point _position;
	Point _orientation;
};

#endif /* __camera.h__  */
