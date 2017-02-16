#include <gl/glut.h>
#include "vector3.h"
#ifndef SCENE_H
#define SCENE_H

class Scene {


	public:

		/* Name : mouseClick() 
		   Description : Handles when a mouse button is pressed / released
		   Parameters : mouse button pressed, mouse state, mouse x,y
		*/
		static void mouseClick(int button, int state, int x, int y); 

		/* Name : mouseMotion()
		   Description : Handle any necessary mouse movements through the trackball
		   Parameters : mouse x and y 
		*/
		static void mouseMotion(int x, int y);

		/* Name : reshape()
		   Description : 
		   Parameters : 
		*/
		static void reshape(int width, int height);

		/* Name : draw()
		   Description : 
		   Parameters : 
		*/
		static void draw(); 

		/* Name : animation()
		   Description : 
		   Parameters :
		*/
		static void animation(int t);

		/* Name : initGL()
		   Description : 
		   Parameters :
		*/
		static void initGL();

		/* Name : setWindowSize()
		   Description : Set the window size
		   Parameters : width and height of the window
		*/
		static void setWindowSize(int width,int height);

		/* Name : keyboardDown()
		   Description : 
		   Parameters : 
		*/
       static void keyboardDown(unsigned char key, int x, int y);
	   
	   /* Name : keyboardUp()
		   Description : 
		   Parameters : 
		*/
       static void keyboardUp(unsigned char key, int x, int y); 

	   static GLint FPS;
		
	   /*Lamp Current rotation key :a-s d-f g-h*/
	   static unsigned char keyPressed;
	
    private :

		/*Keep track of the last mouse position,in spherical coordinates*/
		static Vector3 lastPoint;
	    
		/*Mouse 2D in window coordinates*/  
		static Vector3 mouse2D;

		/*Mouse unproject*/
		static Vector3 mouse3D;

		enum MovementType { ROTATE, ZOOM, NONE };
	    
		/*Left-mouse = ROTATE, Right-mouse = ZOOM*/
		static MovementType Movement;    

		/* Used for the trackball implementation*/
		static double M_ROTSCALE;
		static double M_ZOOMSCALE;
		static float fitFactor;

		/*Default lighting*/
		static GLfloat light_diffuse_0[4];
		static GLfloat light_positio_0[4];

		/* size of the window */
		static int windowSizeX;
		static int windowSizeY;

        /*Lamp Arm3 angle*/
		static float arm3Angle;
		/*Lamp Arm2 angle*/
		static float arm2Angle;
		/*Lamp Arm1 angle */
		static float arm1Angle;
		
		/*Name : trackBallMapping()
		  Description : Utility routine to calculate the 3D position of a 
					  projected unit vector onto the xy-plane. Given any
					  point on the xy-plane, we can think of it as the projection
					  from a sphere down onto the plane. The inverse is what we are after.  
		  Parameters :  x and y position (mouse)
		*/
		static Vector3 trackBallMapping(int x, int y);
        
		/*Name: mouseUnProject()
		  Description:
		  Parameters:
		*/
		static Vector3 mouseUnProject();

		/* Name : drawPlane()
		   Description : 
		   Parameters :
		*/
		static void drawPlane();

		/* Name : drawAxes()
		   Description : 
		   Parameters :
		*/
		static void drawAxes(double length);
};

#endif