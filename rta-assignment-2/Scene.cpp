#include "headers\Scene.h"

#include "headers\Skeleton.h"
#include <stdlib.h>


Vector3 Scene::lastPoint;
Vector3 Scene::mouse2D;
Vector3 Scene::mouse3D;

enum Scene::MovementType;
	
Scene::MovementType Scene::Movement;    
	
double Scene::M_ROTSCALE;
double Scene::M_ZOOMSCALE;
float  Scene::fitFactor;

GLfloat Scene::light_diffuse_0[4];
GLfloat Scene::light_positio_0[4];

	
int Scene::windowSizeX;
int Scene::windowSizeY;

GLint Scene::FPS=60;

float Scene::arm3Angle=-70;
float Scene::arm2Angle=-20;
float Scene::arm1Angle=0;
unsigned char Scene::keyPressed;

void Scene::mouseClick(int button, int state, int x, int y) {
 
	mouse2D = Vector3(x, windowSizeY - y, 0);
    
	if (state == GLUT_UP)
	{
		// Turn-off rotations and zoom.
		Movement = NONE;
		glutPostRedisplay();
		return;
	}

	switch (button)
	{
	case (GLUT_LEFT_BUTTON):

		// Turn on user interactive rotations.
		// As the user moves the mouse, the scene will rotate.
		Movement = ROTATE;

		// Map the mouse position to a logical sphere location.
		// Keep it in the class variable lastPoint.
		lastPoint = trackBallMapping( x, y );
		mouse3D=mouseUnProject();
		break;

	case (GLUT_MIDDLE_BUTTON):

		// Turn on user interactive zooming.
		// As the user moves the mouse, the scene will zoom in or out
		//   depending on the x-direction of travel.
		Movement = ZOOM;

		// Set the last point, so future mouse movements can determine
		//   the distance moved.
		lastPoint.x = (double) x;
		lastPoint.y = (double) y;

		break;

	case (GLUT_RIGHT_BUTTON):
		Movement = NONE;
		break;
	}
    
	glutPostRedisplay();

}

void Scene::mouseMotion(int x, int y){
	Vector3 direction;
	double pixel_diff;
	double rot_angle, zoom_factor;
	Vector3 curPoint;

	switch (Movement) 
	{
	case ROTATE :
		{
			curPoint = trackBallMapping( x, y );
			direction = curPoint - lastPoint;
			double velocity = direction.Length(); 
			if( velocity > 0.0001 )
			{
				Vector3 rotAxis;
				rotAxis = lastPoint ^ curPoint ;
				rotAxis.Normalize();
				rot_angle = velocity * M_ROTSCALE;

				static GLdouble m[4][4];
				glGetFloatv( GL_MODELVIEW_MATRIX, (GLfloat *) m );
				glLoadIdentity();
				glRotated( rot_angle, rotAxis.x, rotAxis.y, rotAxis.z );
				glMultMatrixf( (GLfloat *) m );

				glutPostRedisplay();
			}
			break;
		}
	case ZOOM :
		pixel_diff = y - lastPoint.y; 
		zoom_factor = 1.0 + pixel_diff * M_ZOOMSCALE;
		glScaled( zoom_factor, zoom_factor, zoom_factor );

		// Set the current point, so the lastPoint will be saved properly below.
		curPoint.x = (double) x;  curPoint.y = (double) y;  (double) curPoint.z = 0;

		//  If we want to see it, we need to force the system to redraw the scene.
		glutPostRedisplay();
		break;
	}

	// Save the location of the current point for the next movement. 
	lastPoint = curPoint;	// in spherical coordinates
	mouse2D = Vector3(x, windowSizeY - y, 0);	// in window coordinates
}

void Scene::reshape(int width, int height){

 	windowSizeX = width;
	windowSizeY = height;

	// Determine the new aspect ratio
	GLdouble gldAspect = (GLdouble) width/ (GLdouble) height;

	// Reset the projection matrix with the new aspect ratio.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0, gldAspect, 0.01, 60.0);
	glTranslatef( 0.0, 0.0, -7.0 );

	// Set the viewport to take up the entire window.
	glViewport(0, 0, width, height);

}

void Scene::draw(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_LIGHTING);
	
	drawAxes(4);
    drawPlane();
    Skeleton geo;
	//Bone bone = geo.getBone();
	/* YOUR CODE HERE*/
    geo.drawLamp(arm1Angle,arm2Angle,arm3Angle);
    glPushMatrix();
	glTranslatef(3,1,3);
	//bone.box(2,2,2);
    glPopMatrix();
	glutSwapBuffers();

}
void Scene::keyboardDown(unsigned char key, int x, int y) {
	Scene::keyPressed=key;
	
	switch(key) 
	{
	case 'Q':
	case 'q':
	case  27:   // ESC
		exit(0);
	}

	glutPostRedisplay();
}

void Scene::keyboardUp(unsigned char key, int x, int y) {
	keyPressed=' ';
}

void Scene::animation(int t){
	switch(Scene::keyPressed) 
	{
    case 'g':arm3Angle+=1;if(arm3Angle>=360 )  arm3Angle/=360;break;
	case 'h':arm3Angle-=1;if(arm3Angle<=-360 ) arm3Angle/=360;break;
	case 'd':arm2Angle+=1;if(arm2Angle>=360 )  arm2Angle/=360;break;
	case 'f':arm2Angle-=1;if(arm2Angle<=-360 ) arm2Angle/=360;break;
	case 'a':arm1Angle+=1;if(arm1Angle>=360 )  arm1Angle/=360;break;
	case 's':arm1Angle-=1;if(arm1Angle<=-360)  arm1Angle/=360;break;
	}
 	glutPostRedisplay();
	glutTimerFunc((int) 1000/FPS, animation, 0);
}

void Scene::initGL(){
 	/* Used for the trackball implementation*/
	M_ROTSCALE = 90.0;
	M_ZOOMSCALE = 0.008;
	fitFactor = 1.f;

	/*Default lighting*/
	light_diffuse_0[0] = 1;
	light_diffuse_0[1] = 1;
	light_diffuse_0[2] = 1;
	light_diffuse_0[3] = 1.0;
	
	light_positio_0[0] = 1;
	light_positio_0[1] = 1;
	light_positio_0[2] = 1;
	light_positio_0[3] = 0;

	/* size of the window */
	windowSizeX = 800;
	windowSizeY = 480;

    glLightfv (GL_LIGHT0, GL_DIFFUSE,	light_diffuse_0);
	glLightfv (GL_LIGHT0, GL_POSITION,	light_positio_0);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	reshape(windowSizeX, windowSizeY);

	glClearColor(0.126f, 0.126f, 0.128f, 1.0f);
	glClearDepth(1.0f);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glShadeModel(GL_SMOOTH);
	glEnable(GL_NORMALIZE);

	
}

void Scene::setWindowSize(int width,int height){
  windowSizeX=width;
  windowSizeY=height;
}

Vector3 Scene::trackBallMapping(int x, int y){
    Vector3 v;
	double d;

	v.x = (2.0 * x - windowSizeX) / windowSizeX;
	v.y = (windowSizeY - 2.0 * y) / windowSizeY;
	v.z = 0.0;
	d = v.Length();
	d = (d < 1.0) ? d : 1.0;  // If d is > 1, then clamp it at one.
	v.z = sqrtf( (float)(1.001 - d * d) );  // project the line segment up to the surface of the sphere.

	v.Normalize();  // We forced d to be less than one, not v, so need to normalize somewhere.

	return v;
}

Vector3 Scene::mouseUnProject(){
	GLint viewport[4];                  // Where The Viewport Values Will Be Stored
	glGetIntegerv(GL_VIEWPORT, viewport);           // Retrieves The Viewport Values (X, Y, Width, Height)

	GLdouble modelview[16];                 // Where The 16 Doubles Of The Modelview Matrix Are To Be Stored
	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);       // Retrieve The Modelview Matrix

	GLdouble projection[16];                // Where The 16 Doubles Of The Projection Matrix Are To Be Stored
	glGetDoublev(GL_PROJECTION_MATRIX, projection);     // Retrieve The Projection Matrix

	GLint winX, winY, winZ;               // Holds Our X, Y and Z Coordinates
 
	winX = (GLint)mouse2D.x;                  // Holds The Mouse X Coordinate
	winY = (GLint)mouse2D.y;                  // Holds The Mouse Y Coordinate

	//winY = (float)viewport[3] - winY;           // Subtract The Current Mouse Y Coordinate From The Screen Height.
	glReadPixels(winX, winY, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);

	GLdouble pX;
	GLdouble pY;
	GLdouble pZ;

	gluUnProject( winX, winY, winZ, modelview, projection, viewport, &pX, &pY, &pZ);
	
	//ROUND 2 DECIMAL
	  pX= ((GLint)(pX * 10 + .5) / 10.0);
	  pY= ((GLint)(pY * 10+ .5) / 10.0);
	  pZ= ((GLint)(pZ * 10 + .5) / 10.0);

	return Vector3(pX,pY,pZ);
}

void Scene::drawPlane(){
 int color=1;
 glPushMatrix();
	for(int i=-7;i<=7;i+=1){
		for(int j=-7;j<=7;j+=1){
			if(color == 1){
				glColor3ub(255,255,255);
				color=2;
			}else{
				glColor3ub(0,0,0);
				color=1;
			}
			glBegin(GL_QUADS);
			glVertex3d(j,0, i+1);
			glVertex3d(j,0, i);
			glVertex3d(j+1,0,i);
			glVertex3d(j+1,0,i+1);
			glEnd();
		}
	}
 glPopMatrix();
}

void Scene::drawAxes(double length){
    
	glDisable(GL_LIGHTING);
	
	glPushMatrix();
	glScaled(length, length, length);

	glLineWidth(2.f);
	glBegin(GL_LINES);

	// x red
	glColor3f(1.f, 0.f, 0.f);
	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(1.f, 0.f, 0.f);

	// y green
	glColor3f(0.f, 1.f, 0.f);
	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(0.f, 1.f, 0.f);

	// z blue
	glColor3f(0.f, 0.f, 1.f);
	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(0.f, 0.f, 1.f);

	glEnd();
	glLineWidth(1.f);
    glEnable(GL_LIGHTING);
	glPopMatrix();

}