#pragma once
#include "Point.h"
class Bezier
{
public:

	//Point** is a pointer to an array
	Bezier(int _degree, Point** _ctrlPoints);
	~Bezier();

	void calculateCoefficients();
	int factorial(int n);
	float combination(int n, int i);
	Point* evaluateBezier(float t);


	int degree;
	Point** ctrlPoints;
	float* coefficient;
	
};

