#include <iostream>
#include <gl/glut.h>
#include <math.h>
#include <GL\vector3.h>
#include <GL\Geometry.h>
#include <GL\Scene.h>

int main(int argc, char** argv) 
{

	
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("3D DEMO - http://3dgraphicstutor.blogspot.it/");

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