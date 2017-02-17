#pragma once
#include <gl/glut.h>
#include "headers\vector3.h"
#include "Bone.h"
#define _USE_MATH_DEFINES // enable the definition of M_PI
#include <math.h>
#define PI 3.14159265359
#ifndef SKELETON_H
#define SKELETON_H


class Skeleton {

public:

	Skeleton();
	void drawLamp(int arm1Angle, int arm2Angle, int arm3Angle);
	Bone getBone();

private:

	void addLight();
	Bone bone;
};

#endif