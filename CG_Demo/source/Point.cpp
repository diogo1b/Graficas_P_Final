#include "Point.h"

Point::Point(float _x, float _y, float _z, float _r, float _g, float _b)
{
	x = _x; y = _y; z = _z;
	r = _r; g = _g; b = _b;

	param = 0.1;
	vel = 0.1;
	priority = 1;
	bezierNumber = 3;
}

Point::Point(float _x, float _y, float _z, float _r, float _g, float _b, float _param, float _vel, int _priority, int _bezierNum)
{
	x = _x; y = _y; z = _z;
	r = _r; g = _g; b = _b;

	param = _param;
	vel = _vel;
	priority = _priority;
	bezierNumber = _bezierNum;
}

Point::Point(Point* other)
{
	x = other->x;
	y = other->y;
	z = other->z;
	r = other->r;
	g = other->g;
	b = other->b;
}

Point::~Point()
{
}

Point* Point::multiplyByScalar(float s) {
	Point* p = new Point(this);
	p->x *= s;
	p->y *= s;
	p->z *= s;

	return p;
}

Point* Point::add(Point* other) {
	Point* p = new Point(this);
	p->x += other->x;
	p->y += other->y;
	p->z += other->z;
	return p;
}

void Point::draw() {
	glPushMatrix();
	{
		glTranslatef(x, y, z);
		glColor3f(r, g, b);
		glutSolidSphere(0.02f, 10, 10);
	}
	glPopMatrix();
}

void Point::update() {

}
