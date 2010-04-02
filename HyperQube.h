/*
 * HyperQube.h
 *
 *  Created on: 01.04.2010
 *      Author: r2p2
 */

#ifndef HYPERQUBE_H_
#define HYPERQUBE_H_

#include "Line.h"
#include "Point.h"

class HyperQube
{
	Line *lines[12];

public:
	HyperQube();
	virtual ~HyperQube();

	void rotate_x(double angle);
	void rotate_y(double angle);
	void rotate_z(double angle);
	void move_(double x_delta, double y_delta, double z_delta);

	void render(char);
};

#endif /* HYPERQUBE_H_ */
