#include "camera.h"

Camera::Camera(const Point& position, const Point& orientation)
: Object3D()
, _position(position)
, _orientation(orientation)
{
}

Camera::~Camera()
{}

void Camera::look_at(const Point& point)
{
	_orientation = substract(_position, point);
	_orientation.normalize();
}

void Camera::move(double x, double y, double z)
{
	_position.move(x, y, z);
}

void Camera::move_to(double x, double y, double z)
{
	_position.move_to(x, y, z);
}

void Camera::rotate(double x, double y, double z)
{
	_position.rotate(x, y, z);
}
