#include "Bezier.h"

Bezier::Bezier(int _degree, Point** _ctrlPoints)
{
	degree = _degree;
	coefficient = new float[degree + 1];
	ctrlPoints = new Point*[degree + 1];
	// copy the points
	for (int i = 0; i <= degree; i++) {
		ctrlPoints[i] = new Point(_ctrlPoints[i]);
	}
	calculateCoefficients();
}


Bezier::~Bezier()
{
	// Manage memory (no GC in C++)
	delete ctrlPoints;
}

void Bezier::calculateCoefficients() {
	for (int i = 0; i <= degree; i++) {
		coefficient[i] = combination(degree, i);
	}
}

int Bezier::factorial(int n) {
	if (n == 0) return 1;
	else return n * factorial(n - 1);
}

float Bezier::combination(int n, int i) {
	float nf = (float)factorial(n);
	return nf / (factorial(i)*factorial(n - i));
}

Point* Bezier::evaluateBezier(float t) {
	Point* p = new Point(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
	for (int i = 0; i <= degree; i++)
	{
		float c = pow(1 - t, degree - i)* pow(t, i);
		p = p->add(ctrlPoints[i]->multiplyByScalar(coefficient[i] * c));

	}
	return p;
}