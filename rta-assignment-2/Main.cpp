#include <iostream>
#include <gl/glut.h>
#include <math.h>

#include "headers\vector3.h"
#include "headers\Geometry.h"
#include "headers\Scene.h"

int main(int argc, char** argv) 
{

	
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000, 1200);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Hand Hierarchy");

	glutMouseFunc(Scene::mouseClick);
	glutMotionFunc(Scene::mouseMotion);
	glutReshapeFunc(Scene::reshape);
	glutDisplayFunc(Scene::draw);  
	glutKeyboardFunc(Scene::keyboardDown);
	glutKeyboardUpFunc(Scene::keyboardUp);
	glutTimerFunc((int) 1000/Scene::FPS, Scene::animation, 0);
	
	glutIgnoreKeyRepeat(false); // process keys held down

	Scene::initGL();
	
	glutMainLoop();
	return 0;
}