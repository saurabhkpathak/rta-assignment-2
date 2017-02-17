#include "headers\Skeleton.h"
#include "headers\Bone.h"

Skeleton::Skeleton() {}

Bone Skeleton::getBone() {
	return this->bone;
}

void Skeleton::drawLamp(int arm1Angle, int arm2Angle, int arm3Angle) {

	Bone geo;

	int colors1[] = { 0,0,255, 0,0,255 };
	//int colors2[]={    255,153,51, 255,153,51, 255,153,51, 
	//255,153,51, 255,153,51, 255,153,51};
	int colors3[] = { 255,0,0, 255,0,0, 255,0,0, 255,0,0, 255,0,0, 255,0,0 };

	glPushMatrix();

	float   HEIGHT_CYL_A = 0.05f;//BASE CYLINDER HEIGHT
	float   HEIGHT_CYL_B = 0.05f;//MIDDLE CYLINDERS HEIGHT
	float   HEIGHT_CYL_C = 0.05f;//TOP CYLINDER HEIGHT
	float   SPHERE_RADIUS = 0.05f;//SPHERE RADIUS

	/* Draw Base Start */
	glRotatef(arm1Angle, 0, 1, 0);
	glTranslatef(0, HEIGHT_CYL_A / 2, 0);
	geo.box(HEIGHT_CYL_A, HEIGHT_CYL_A, HEIGHT_CYL_A, colors3);
	/* Draw Base End */

	/* Draw Sphere Joint Start*/
	glTranslatef(0, SPHERE_RADIUS / 2 + HEIGHT_CYL_A, 0);
	geo.sphere(SPHERE_RADIUS, 10, 10, colors1);
	/* Draw Sphere Joint End*/

	/* Draw first middle Arm Start */
	glRotatef(-20, 0, 0, 1);
	glTranslatef(0, SPHERE_RADIUS + HEIGHT_CYL_B / 2, 0);
	geo.box(HEIGHT_CYL_A, HEIGHT_CYL_B, HEIGHT_CYL_A, colors3);
	/* Draw first middle Arm End */

	/* Draw Sphere Joint Start*/
	glTranslatef(0, SPHERE_RADIUS + HEIGHT_CYL_B / 2, 0);
	geo.sphere(SPHERE_RADIUS, 10, 10, colors1);
	/* Draw Sphere Joint End*/

	/* Draw second middle Arm Start */
	glRotatef(arm2Angle, 0, 0, 1);
	glTranslatef(0, SPHERE_RADIUS + HEIGHT_CYL_B / 2, 0);
	geo.box(HEIGHT_CYL_A, HEIGHT_CYL_B, HEIGHT_CYL_A, colors3);
	/* Draw second middle Arm End */

	/* Draw Sphere Joint Start*/
	glTranslatef(0, SPHERE_RADIUS + HEIGHT_CYL_B / 2, 0);
	geo.sphere(SPHERE_RADIUS, 10, 10, colors1);
	/* Draw Sphere Joint End*/

	/* Draw third Arm Start */
	glRotatef(arm3Angle, 0, 0, 1);
	glTranslatef(0, SPHERE_RADIUS + HEIGHT_CYL_C / 2, 0);


	geo.box(HEIGHT_CYL_A, HEIGHT_CYL_C, HEIGHT_CYL_A, colors3);
	/* Draw third  Arm End */

	/*Sphere emission*/
	//GLfloat mat_emission[] = { 0.5, 0.8, 0.9, 0.0 };
	//glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);

	/* Draw Sphere Final  Start*/
	//glTranslatef(0, SPHERE_RADIUS + HEIGHT_CYL_C / 2, 0);
	//geo.sphere(SPHERE_RADIUS, 10, 10, colors1);
	//glEnable(GL_LIGHT1);
	/* Draw Sphere Final End*/

	/*Put light near the final sphere*/
	glEnable(GL_LIGHT1);
	GLfloat pos[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat color[] = { 1.0, 1.0, 1.0, 1.0 };
	//glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);// set cutoff angle
	glLightfv(GL_LIGHT1, GL_POSITION, pos);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, color);
	//glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2); 


	GLfloat mat_emission2[] = { 0, 0, 0, 0.0 };
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission2);



	glPopMatrix();

}