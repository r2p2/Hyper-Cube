#include "polygon.h"

Polygon::Polygon(const Point& p1, const Point& p2, const Point& p3)
: _p({p1, p2, p3})
{
}

Polygon::~Polygon()
{
}

Point Polygon::normal_vector() const
{
	const Point first_line = substract(_p[1], _p[0]);
	const Point second_line = substract(_p[2], _p[1]);

	Point norm_vector = cross_product(first_line, second_line);
	norm_vector.normalize();
	return norm_vector;
}

void Polygon::move(double x, double y, double z)
{
	_p[0].move(x, y, z);
	_p[1].move(x, y, z);
	_p[2].move(x, y, z);
}

void Polygon::move_to(double x, double y, double z)
{
	_p[0].move_to(x, y, z);
	_p[1].move_to(x, y, z);
	_p[2].move_to(x, y, z);
}

void Polygon::rotate(double x, double y, double z)
{
	_p[0].rotate(x, y, z);
	_p[1].rotate(x, y, z);
	_p[2].rotate(x, y, z);
}

std::vector<Polygon> Polygon::polygons() const
{
	std::vector<Polygon> polygons;
	polygons.push_back(*this);

	return polygons;
}


