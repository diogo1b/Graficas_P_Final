#include "Pedestrian.h"

Pedestrian::Pedestrian()
{
	srand(time(0));

	frames = 0;
	dir = 1.0f;
	param = 0;
	aux = 0;

	for (int i = 0; i < TRAVELERS; i++) {
		travelers[i] = new Point(0, 0, 0, 0, 1, 0, 0, 0.0001, i, 3);
	}
	
	createBeziers();
	
}

Pedestrian::~Pedestrian()
{
}

void Pedestrian::draw() {
	//printf("%d\n", aux);
	for (int i = 0; i < aux; i++) {

		travelers[i]->draw();
	}
}

void Pedestrian::update() {
	frames++;

	if (frames%120 == 0 && aux < TRAVELERS-1) {
		aux++;
	}

	for (int i = 0; i < aux; i++) {
		if (travelers[i]->param > 1 || travelers[i]->param < 0) dir = -dir;
		float aux2 = travelers[i]->param;
		travelers[i] = beziers[i]->evaluateBezier(aux2 + dir * 0.0001);
		travelers[i]->param = aux2 + dir * 0.0001;
		
		printf("%d\n", i);
		//printf("%f\n", travelers[i]->param);
		//printf("%f\n", travelers[i]->vel);
		printf("%d\n", travelers[i]->priority);
		//printf("%f\n", travelers[i]->bezierNumber);


		/*
		printf("%d\n", i);
		printf("%f\n", travelers[i]->x);
		printf("%f\n", travelers[i]->y);
		printf("%f\n", travelers[i]->z);
		*/	
	}
}

void Pedestrian::init() {

}

void Pedestrian::createBeziers() {

	for (int i = 0; i < CTRL_POINTS; i++)
	{
		ctrl[i] = new Point(0, 0, 0, 1, 0, 0);		// Se inicializan los puntos
	}

	for (int i = 0; i < TRAVELERS - 1; i++) {
		ctrl[0]->x = 0.3; 
		ctrl[0]->y = 0.2;
		ctrl[1]->x = -0.574 * 2;
		ctrl[1]->y = 0.087 * 2;
		ctrl[2]->x = -0.278 * 2;
		ctrl[2]->y = -1.482 * 2;
		ctrl[3]->x = 0.195 * 2;
		ctrl[3]->y = 1.97 * 2;
		ctrl[4]->x = -0.026 * 2;
		ctrl[4]->y = -0.16 * 2 ;
		ctrl[5]->x = 0.273 * 2 ;
		ctrl[5]->y = -2.246 * 2;
		ctrl[6]->x = -0.408 * 2;
		ctrl[6]->y = 1.506 * 2;
		ctrl[7]->x = -0.0240 * 2;
		ctrl[7]->y = -0.35 * 2;
		ctrl[8]->x = 0.243;
		ctrl[8]->y = -0.067 ;
		ctrl[9]->x = 0.3; 
		ctrl[9]->y = 0.2;

		beziers[i] = new Bezier(CTRL_POINTS - 1, ctrl);
	}
	
}

