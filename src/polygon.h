#ifndef __polygon_h__
#define __polygon_h__

#include "Point.h"
#include "renderable.h"

#include <vector>

class Renderable;
class Polygon : public Object3D, public Renderable
{
public:
	Polygon (const Point& /*p1*/, const Point& /*p2*/, const Point& /*p3*/);
	virtual ~Polygon ();

	Point normal_vector() const;

	// Object3D
	virtual void rotate(double /*x*/, double /*y*/, double /*z*/);
	virtual void move(double /*x*/, double /*y*/, double /*z*/);
	virtual void move_to(double /*x*/, double /*y*/, double /*z*/);

	// Renderable
	virtual std::vector<Polygon> polygons() const;

private:
	Point _p[3];
};

#endif /* __polygon.h__  */
