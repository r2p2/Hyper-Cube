#include "matrix.h"

#include <cmath>

Matrix::Matrix()
: _array()
{
	for (int y = 0; y < 3; ++y)
	{
		for (int x = 0; x < 3; ++x)
		{
			_array[y][x] = 0;
		}
	}
}

Matrix::~Matrix()
{
}

const double& Matrix::at(uint8_t x, uint8_t y) const
{
	return _array[y][x];
}

double& Matrix::at(uint8_t x, uint8_t y)
{
	return _array[y][x];
}

Point multiply(const Matrix& matrix, const Point& point)
{
	return Point(
		matrix.at(0,0)*point.x + matrix.at(1,0)*point.y + matrix.at(2,0)*point.z,
		matrix.at(0,1)*point.x + matrix.at(1,1)*point.y + matrix.at(2,1)*point.z,
		matrix.at(0,2)*point.x + matrix.at(1,2)*point.y + matrix.at(2,2)*point.z
		);
}

Matrix make_rotation_matrix_x(double degree)
{
	Matrix rot_matrix;

	double rad = degree*3.14159265/180;

	rot_matrix.at(0,0) = 1;
	rot_matrix.at(1,1) = cos(rad);
	rot_matrix.at(2,1) = sin(rad);
	rot_matrix.at(1,2) = -sin(rad);
	rot_matrix.at(2,2) = cos(rad);

	return rot_matrix;
}

Matrix make_rotation_matrix_y(double degree)
{
	Matrix rot_matrix;

	double rad = degree*3.14159265/180;

	rot_matrix.at(0,0) = cos(rad);
	rot_matrix.at(2,0) = -sin(rad);
	rot_matrix.at(1,1) = 1;
	rot_matrix.at(0,2) = sin(rad);
	rot_matrix.at(2,2) = cos(rad);

	return rot_matrix;
}

Matrix make_rotation_matrix_z(double degree)
{
	Matrix rot_matrix;

	double rad = degree*3.14159265/180;

	rot_matrix.at(0,0) = cos(rad);
	rot_matrix.at(1,0) = sin(rad);
	rot_matrix.at(0,1) = -sin(rad);
	rot_matrix.at(1,1) = cos(rad);
	rot_matrix.at(2,2) = 1;

	return rot_matrix;
}
