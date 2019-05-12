#pragma once

// Please don't change lines 9-31 (It helps me to grade)
#ifdef _APPLE_
// For XCode only: New C++ terminal project. Build phases->Compile with libraries: add OpenGL and GLUT
// Import this whole code into a new C++ file (main.cpp, for example). Then run.
// Reference: https://en.wikibooks.org/wiki/OpenGL_Programming/Installation/Mac
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#endif
#ifdef _WIN32
// For VS on Windows only: Download CG_Demo.zip. UNZIP FIRST. Double click on CG_Demo/CG_Demo.sln
// Run
#include "freeglut.h"
#endif
#ifdef _unix_
// For Linux users only: g++ CG_Demo.cpp -lglut -lGL -o CG_Demo
// ./CG_Demo
// Reference: https://www.linuxjournal.com/content/introduction-opengl-programming
#include "GL/freeglut.h"
#include "GL/gl.h"
#endif

#include "glm.h"

#include <stdio.h>
#include <math.h>

class Point
{
public:
	Point(float _x, float _y, float _z, float _r, float _g, float _b);
	Point(float _x, float _y, float _z, float _r, float _g, float _b, float _param, float _vel, int _priority, int _bezierNum);

	Point(Point* other);
	~Point();

	GLMmodel* sintel;
	float* dims;
	float* center;

	void draw();
	void update();
	Point* multiplyByScalar(float s);
	Point* add(Point* other);

	float x, y, z;
	float r, g, b;

	float param;
	float vel;
	int priority;
	int bezierNumber;

};

