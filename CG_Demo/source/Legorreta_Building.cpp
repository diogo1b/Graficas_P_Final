#include "Legorreta_Building.h"

Legorreta_Building::Legorreta_Building(float _x, float _y, float _z)
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	Id = new float[4];
	Id[0] = 1.0f;
	Id[1] = 1.0f;
	Id[2] = 1.0f;
	Id[3] = 1.0f;

	Ia = new float[4];
	Ia[0] = 1.0f;
	Ia[1] = 1.0f;
	Ia[2] = 1.0f;
	Ia[3] = 1.0f;

	Is = new float[4];
	Is[0] = 1.0f;
	Is[1] = 1.0f;
	Is[2] = 1.0f;
	Is[3] = 1.0f;

	Ip = new float[4];
	Ip[0] = 2.0f;
	Ip[1] = 0.5f;
	Ip[2] = 1.0f;
	Ip[3] = 1.0f;

	glLightfv(GL_LIGHT0, GL_AMBIENT, Ia);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, Id);
	glLightfv(GL_LIGHT0, GL_SPECULAR, Is);
	glLightfv(GL_LIGHT0, GL_POSITION, Ip);

	pos = new float[3];
	dims = new float[3];

	pos[0] = _x;
	pos[1] = _y;
	pos[2] = _z;

	/*
	building = glmReadOBJ("assets/Lego_Building/Legorreta_textures.obj");
	glmUnitize(building);
	glmScale(building, 0.58f);
	//glmFacetNormals(building);
	glmDimensions(building, dims);
	center = new float[3];
	center[0] = pos[0] + dims[0] / 2.0f;
	center[1] = pos[1] + dims[1] / 2.0f;
	center[2] = pos[2] + dims[2] / 2.0f;
	*/
}


Legorreta_Building::~Legorreta_Building()
{
}

void Legorreta_Building::draw() {
	glPushMatrix();
	{
		glTranslatef(pos[0], pos[1], pos[2]);
		glRotatef(90, 1, 0, 0);
		//glmDraw(building, GLM_SMOOTH | GLM_TEXTURE);
		
	}
	glPopMatrix();
}