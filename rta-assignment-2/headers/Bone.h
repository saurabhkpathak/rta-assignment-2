#pragma once
#include <gl/glut.h>
#include "headers\vector3.h"
#define _USE_MATH_DEFINES // enable the definition of M_PI
#include <math.h>
#define PI 3.14159265359
#ifndef BONE_H
#define BONE_H


class Bone {

public:

	Bone();
	void box(GLdouble width, GLdouble height, GLdouble lenght);
	void box(GLdouble width, GLdouble height, GLdouble lenght, GLint* colors);
	void sphere(GLdouble radius, GLint slices, GLint stacks);
	void sphere(GLdouble radius, GLint slices, GLint stacks, GLint* colors);

private:

	Vector3 spherePoint(GLdouble lat, GLdouble lon, GLdouble n_lat, GLdouble n_lon, GLdouble radius);
};

#endif