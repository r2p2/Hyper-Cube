#ifndef __matrix_h__
#define __matrix_h__

#include "Point.h"

#include <stdint.h>

class Matrix
{
public:
	Matrix();
	virtual ~Matrix ();

	const double& at(uint8_t /*x*/, uint8_t /*y*/) const;
	double& at(uint8_t /*x*/, uint8_t /*y*/);

private:
	double _array[3][3];
};

Point multiply(const Matrix& /*matrix*/, const Point& /*point*/);
Matrix make_rotation_matrix_x(double degree);
Matrix make_rotation_matrix_y(double degree);
Matrix make_rotation_matrix_z(double degree);

#endif /* __matrix.h__  */
