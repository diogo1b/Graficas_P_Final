/*
	A01334970| Diogo Miguel Burnay Rojas
	A01336176| Manuel Avalos Tovar
	A01334482| Dara Scarlett Arriaga Ventura
	A01334386| Alan Saúl Cabello Almazán

	Computer Graphics. TC3022.
*/

#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
	#include <GLUT/glut.h>
#else
	#include "freeglut.h"
#endif

#include <stdio.h>
#include <math.h>
#include "Plane.h"
#include "Pedestrian.h"
#include "Player.h"
#include "Camera.h"
#include "CDTC_Building.h"
#include "Legorreta_Building.h"

Plane* Lego_CDTC_Plane;
Pedestrian* Student;
Player* P1;
Camera* mainCam;
CDTC_Building* CDTC;
Legorreta_Building* Lego;


GLfloat* global_ambient;
GLfloat* Ia; 
GLfloat* Id; 
GLfloat* Is; 
GLfloat* Ip; 

void display( void )
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	
	//Set the camera
	mainCam->setView();

	// Set Plane and buildings
	Lego_CDTC_Plane->draw();
	CDTC->draw();
	Lego->draw();
	
	// Set the pedestrians
	Student->draw();

	//Set the player
	P1->draw();
	
	glutSwapBuffers();
}

void idle( void )
{
	// Updates the moveble or interactable objects
	mainCam->update();
	Student->update();
	P1->update();
	glutPostRedisplay();
}

void reshape( int w, int h )
{
	glViewport( 0, 0, w, h );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	gluPerspective( 60.0, w / h * 1.0, 0.01, 1024.0 );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
}

void playerMovement(unsigned char key, int x, int y) {
	P1->move(key);
}

void cameraMovement(int key, int x, int y) {
	mainCam->move(key, P1->pos);
}

void init( void )
{
	// Inicialization of the objects
	mainCam = new Camera();	
	Lego_CDTC_Plane = new Plane();
	CDTC = new CDTC_Building(-0.7,-0.3,0);
	Lego = new Legorreta_Building(0.43,0.023,0);
	Student = new Pedestrian();
	P1 = new Player(0,0,0);

	global_ambient = new GLfloat[4];
	global_ambient[0] = 0.3f;
	global_ambient[1] = 0.3f;
	global_ambient[2] = 0.3f;
	global_ambient[3] = 1.0f;
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

    glEnable( GL_DEPTH_TEST );
	glEnable( GL_TEXTURE_2D );
	glClearColor( 0.0, 0.0, 0.0, 0.0 );
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main( int argc, char* argv[] )
{
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
	glutInitWindowSize( 800, 800 );
	glutInitWindowPosition( 100, 100 );
	glutCreateWindow( "Final Project" );
	glutReshapeFunc( reshape );
	init();
	glutKeyboardFunc(playerMovement);
	glutSpecialFunc(cameraMovement);
	glutDisplayFunc( display );
	glutIdleFunc( idle );
	glutMainLoop();
	return 0;
}

