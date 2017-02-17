#include <gl/glut.h>
#include "vector3.h"
#define _USE_MATH_DEFINES // enable the definition of M_PI
#include <math.h>
#define PI 3.14159265359
#ifndef GEOMETRY_H
#define GEOMETRY_H


class Geometry {

public :

	Geometry();

	/* Name : box()
       Description :  Renders a box centered in the origin coordinates
       Parameters : x,y,z are center coordinates.
    */
	void box(GLdouble width, GLdouble height, GLdouble lenght);

    /* Name : box()
       Description :  Renders a box centered in the origin coordinates
       Parameters : x,y,z are center coordinates,colors contains red,green,blue value for each face.
    */
	void box(GLdouble width, GLdouble height, GLdouble lenght,GLint* colors);

	/* Name : sphere()
	   Description : Renders a sphere centered in the origin coordinates. 
				     The sphere is subdivided around the Z axis into slices and along the Z axis into stacks.
	   Parameters :  radius The radius of the sphere.
                     slices The number of subdivisions around the Z axis (similar to lines of longitude).
                     stacks The number of subdivisions along the Z axis (similar to lines of latitude).
	*/
	void sphere(GLdouble radius,GLint slices, GLint stacks);


	/* Name : sphere()
	   Description : Renders a sphere centered in the origin coordinates. 
				     The sphere is subdivided around the Z axis into slices and along the Z axis into stacks.
	   Parameters :  radius The radius of the sphere.
                     slices The number of subdivisions around the Z axis (similar to lines of longitude).
                     stacks The number of subdivisions along the Z axis (similar to lines of latitude).
				     colors The colors for triangles.Colors contains red,green,blue components.
	*/
	void sphere(GLdouble radius,GLint slices, GLint stacks,GLint* colors);

	void drawLamp(int arm1Angle,int arm2Angle,int arm3Angle);

private:

    Vector3 spherePoint(GLdouble lat, GLdouble lon, GLdouble n_lat, GLdouble n_lon,GLdouble radius);

	/*
		Add a light 
		Used in drawLamp() method
	*/
	void addLight();

};

#endif