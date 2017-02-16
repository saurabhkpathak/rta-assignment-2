#include <GL\Geometry.h>

Geometry::Geometry(){}


void Geometry::box(GLdouble width, GLdouble height, GLdouble lenght){
	 
		 // Front
		 glBegin(GL_QUADS);
		  glNormal3d(0, 0, lenght/2);
		  glVertex3d(-width/2, height/2, lenght/2);
		  glVertex3d(width/2, height/2, lenght/2);
          glVertex3d(width/2, -height/2, lenght/2);
          glVertex3d(-width/2, -height/2, lenght/2);
         glEnd();

		  // Right
		 glBegin(GL_QUADS);
		  glNormal3d(-width/2, 0, 0);
		  glVertex3d(-width/2, +height/2, -lenght/2);
		  glVertex3d(-width/2, +height/2, lenght/2);
          glVertex3d(-width/2, -height/2, lenght/2);
          glVertex3d(-width/2, -height/2, -lenght/2);
         glEnd();

		  // Back
		 glBegin(GL_QUADS);
		  glNormal3d(0, 0, -lenght/2);
		  glVertex3d(width/2, height/2, -lenght/2);
		  glVertex3d(-width/2, height/2, -lenght/2);
          glVertex3d(-width/2, -height/2, -lenght/2);
          glVertex3d(width/2, -height/2, -lenght/2);
         glEnd();

		  // Left
		 glBegin(GL_QUADS);
		  glNormal3d(width/2, 0, 0);
		  glVertex3d(width/2, height/2, lenght/2);
		  glVertex3d(width/2, height/2, -lenght/2);
          glVertex3d(width/2, -height/2, -lenght/2);
          glVertex3d(width/2, -height/2, lenght/2);
         glEnd();

		 // Top
		 glBegin(GL_QUADS);
		  glNormal3d(0, height/2, 0);
		  glVertex3d(-width/2, height/2, -lenght/2);
		  glVertex3d(width/2, height/2, -lenght/2);
          glVertex3d(width/2, height/2, lenght/2);
          glVertex3d(-width/2, height/2, lenght/2);
         glEnd();

		 
		 // Bottom
		 glBegin(GL_QUADS);
		  glNormal3d(0, -height/2, 0);
		  glVertex3d(-width/2, -height/2, lenght/2);
		  glVertex3d(width/2, -height/2, lenght/2);
          glVertex3d(width/2, -height/2, -lenght/2);
          glVertex3d(-width/2, -height/2, -lenght/2);
         glEnd();

	
	}

void Geometry::box(GLdouble width, GLdouble height, GLdouble lenght,GLint* colors){
	 
		 // Front
		 glBegin(GL_QUADS);
		  glNormal3d(0, 0, lenght/2);
		  glColor3ub(colors[0],colors[1],colors[2]);
		  glVertex3d(-width/2, height/2, lenght/2);
		  glVertex3d(width/2, height/2, lenght/2);
          glVertex3d(width/2, -height/2, lenght/2);
          glVertex3d(-width/2, -height/2, lenght/2);
         glEnd();

		  // Right
		 glBegin(GL_QUADS);
		  glNormal3d(-width/2, 0, 0);
		  glColor3ub(colors[3],colors[4],colors[5]);
		  glVertex3d(-width/2, height/2, -lenght/2);
		  glVertex3d(-width/2, height/2, lenght/2);
          glVertex3d(-width/2, -height/2, lenght/2);
          glVertex3d(-width/2, -height/2, -lenght/2);
         glEnd();

		  // Back
		 glBegin(GL_QUADS);
		  glNormal3d(0, 0, -lenght/2);
		  glColor3ub(colors[6],colors[7],colors[8]);
		  glVertex3d(width/2, height/2, -lenght/2);
		  glVertex3d(-width/2, height/2, -lenght/2);
          glVertex3d(-width/2, -height/2, -lenght/2);
          glVertex3d(width/2, -height/2, -lenght/2);
         glEnd();

		  // Left
		 glBegin(GL_QUADS);
		  glNormal3d(width/2, 0, 0);
		  glColor3ub(colors[9],colors[10],colors[11]);
		  glVertex3d(width/2, height/2, lenght/2);
		  glVertex3d(width/2, height/2, -lenght/2);
          glVertex3d(width/2, -height/2, -lenght/2);
          glVertex3d(width/2, -height/2, lenght/2);
         glEnd();

		 // Top
		 glBegin(GL_QUADS);
		  glNormal3d(0, height/2, 0);
		  glColor3ub(colors[12],colors[13],colors[14]);
		  glVertex3d(-width/2, height/2, -lenght/2);
		  glVertex3d(+width/2, height/2, -lenght/2);
          glVertex3d(+width/2, height/2, lenght/2);
          glVertex3d(-width/2, height/2, lenght/2);
         glEnd();

		 
		 // Bottom
		 glBegin(GL_QUADS);
		  glNormal3d(0, -height/2, 0);
		  glColor3ub(colors[15],colors[16],colors[17]);
		  glVertex3d(-width/2, -height/2, lenght/2);
		  glVertex3d(width/2, -height/2, lenght/2);
          glVertex3d(width/2, -height/2, -lenght/2);
          glVertex3d(-width/2, -height/2, -lenght/2);
         glEnd();

		 
	}

void Geometry::sphere(GLdouble radius,GLint slices, GLint stacks){

	// the sphere is made by quads, each quad is composed by two triangles
	glBegin(GL_TRIANGLES);
	for (GLfloat lat = 0; lat < stacks; lat += 1.f)
		for (GLfloat lon = 0; lon < slices; lon += 1.f)
		{
			Vector3 p;

			// -- first triangle
			p = spherePoint(lat, lon, stacks, slices,radius);
 	        glNormal3d(p.x,p.y,p.z);
			glVertex3d(p.x,p.y,p.z);

			p = spherePoint(lat + 1, lon, stacks, slices,radius);
			glNormal3d(p.x,p.y,p.z);
			glVertex3d(p.x,p.y,p.z);

			p = spherePoint(lat + 1, lon + 1, stacks, slices,radius);
			glNormal3d(p.x,p.y,p.z);
			glVertex3d(p.x,p.y,p.z);


			// -- second triangle
			p = spherePoint(lat, lon, stacks, slices,radius);
 	        glNormal3d(p.x,p.y,p.z);
			glVertex3d(p.x,p.y,p.z);

			p = spherePoint(lat + 1, lon + 1, stacks, slices,radius);
			glNormal3d(p.x,p.y,p.z);
			glVertex3d(p.x,p.y,p.z);

			p = spherePoint(lat, lon + 1, stacks, slices,radius);
			glNormal3d(p.x,p.y,p.z);
			glVertex3d(p.x,p.y,p.z);

	}
	glEnd();
}

void Geometry::sphere(GLdouble radius,GLint slices, GLint stacks,GLint* colors){
    int color=1;
	// the sphere is made by quads, each quad is composed by two triangles
	glBegin(GL_TRIANGLES);
	for (GLfloat lat = 0; lat < stacks; lat += 1.f){
		if( color == 1){
				glColor3ub(colors[0],colors[1],colors[2]);
				color=2;
		}else{
				glColor3ub(colors[3],colors[4],colors[5]);
				color=1;
		}
		for (GLfloat lon = 0; lon < slices; lon += 1.f){
			Vector3 p;
			if( color == 1){
				glColor3ub(colors[0],colors[1],colors[2]);
				color=2;
			}else{
				glColor3ub(colors[3],colors[4],colors[5]);
				color=1;
			}
			// -- first triangle
			p = spherePoint(lat, lon, stacks, slices,radius);
 	        glNormal3d(p.x,p.y,p.z);
			glVertex3d(p.x,p.y,p.z);

			p = spherePoint(lat + 1, lon, stacks, slices,radius);
			glNormal3d(p.x,p.y,p.z);
			glVertex3d(p.x,p.y,p.z);

			p = spherePoint(lat + 1, lon + 1, stacks, slices,radius);
			glNormal3d(p.x,p.y,p.z);
			glVertex3d(p.x,p.y,p.z);


			// -- second triangle
			
			p = spherePoint(lat, lon, stacks, slices,radius);
 	        glNormal3d(p.x,p.y,p.z);
			glVertex3d(p.x,p.y,p.z);

			p = spherePoint(lat + 1, lon + 1, stacks, slices,radius);
			glNormal3d(p.x,p.y,p.z);
			glVertex3d(p.x,p.y,p.z);

			p = spherePoint(lat, lon + 1, stacks, slices,radius);
			glNormal3d(p.x,p.y,p.z);
			glVertex3d(p.x,p.y,p.z);

		}
	}
	glEnd();
}



void Geometry::drawLamp(int arm1Angle,int arm2Angle,int arm3Angle){
 
 Geometry geo;

 int colors1[]={0,127,255, 102,255,0};
 int colors2[]={    255,153,51, 255,153,51, 255,153,51, 
        255,153,51, 255,153,51, 255,153,51};
 
 glPushMatrix();

 float   HEIGHT_CYL_A  = 0.5f;//BASE CYLINDER HEIGHT
 float   HEIGHT_CYL_B	 = 1.5f;//MIDDLE CYLINDERS HEIGHT
 float   HEIGHT_CYL_C  = 0.5f;//TOP CYLINDER HEIGHT
 float   SPHERE_RADIUS = 0.5f;//SPHERE RADIUS
 
 /* Draw Base Start */
 glRotatef(arm1Angle,0,1,0);
 glTranslatef(0,HEIGHT_CYL_A/2,0);
 geo.box(2,HEIGHT_CYL_A,2,colors2);
 /* Draw Base End */

 /* Draw Sphere Joint Start*/
  glTranslatef(0,SPHERE_RADIUS/2+HEIGHT_CYL_A,0);
  geo.sphere(SPHERE_RADIUS,10,10,colors1);
 /* Draw Sphere Joint End*/

 /* Draw first middle Arm Start */
 glRotatef(-20,0,0,1);
 glTranslatef(0,SPHERE_RADIUS+HEIGHT_CYL_B/2,0);
 geo.box(1,HEIGHT_CYL_B,1,colors2);
 /* Draw first middle Arm End */

 /* Draw Sphere Joint Start*/
  glTranslatef(0,SPHERE_RADIUS+HEIGHT_CYL_B/2,0);
  geo.sphere(SPHERE_RADIUS,10,10,colors1);
 /* Draw Sphere Joint End*/

 /* Draw second middle Arm Start */
 glRotatef(arm2Angle,0,0,1);
 glTranslatef(0,SPHERE_RADIUS+HEIGHT_CYL_B/2,0);
 geo.box(1,HEIGHT_CYL_B,1,colors2);
  /* Draw second middle Arm End */

  /* Draw Sphere Joint Start*/
  glTranslatef(0,SPHERE_RADIUS+HEIGHT_CYL_B/2,0);
  geo.sphere(SPHERE_RADIUS,10,10,colors1);
 /* Draw Sphere Joint End*/

   /* Draw third Arm Start */
 glRotatef(arm3Angle,0,0,1);
 glTranslatef(0,SPHERE_RADIUS+HEIGHT_CYL_C/2,0);


 geo.box(2,HEIGHT_CYL_C,2,colors2);
  /* Draw third  Arm End */

 /*Sphere emission*/
 GLfloat mat_emission[] = {0.5, 0.8, 0.9, 0.0};
 glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
 
 /* Draw Sphere Final  Start*/
  glTranslatef(0,SPHERE_RADIUS+HEIGHT_CYL_C/2,0);
  geo.sphere(SPHERE_RADIUS,10,10,colors1);
  glEnable(GL_LIGHT1);
 /* Draw Sphere Final End*/
  
  /*Put light near the final sphere*/
  glEnable(GL_LIGHT1);
  GLfloat pos[]={ 0.0, 0.0, 0.0, 1.0};
  GLfloat color[]={ 1.0, 1.0, 1.0, 1.0};
  //glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);// set cutoff angle
  glLightfv(GL_LIGHT1, GL_POSITION, pos); 
  glLightfv(GL_LIGHT1, GL_DIFFUSE, color);
  //glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2); 


  GLfloat mat_emission2[] = {0, 0, 0, 0.0};
  glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission2);



 glPopMatrix();

}

Vector3 Geometry::spherePoint(GLdouble lat, GLdouble lon, GLdouble n_lat, GLdouble n_lon,
					GLdouble radius){
 return Vector3(
		radius*sin(PI * (lat/n_lat)) * cos(2 * PI * (lon/n_lon)), 
		radius*sin(PI * (lat/n_lat)) * sin(2 * PI * (lon/n_lon)), 
		radius*cos(PI * (lat/n_lat)));
}

