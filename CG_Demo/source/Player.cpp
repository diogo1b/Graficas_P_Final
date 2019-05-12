#include "Player.h"



Player::Player(float _x, float _y, float _z)
{
	pos = new float[3];
	dims = new float[3];

	pos[0] = _x;
	pos[1] = _y;
	pos[2] = _z;

	speed = 0.008f;

	sintel = glmReadOBJ("assets/Student/Monigote_TGA.obj");
	glmUnitize(sintel);
	glmScale(sintel, 0.05f);
	//glmFacetNormals(building);
	center = new float[3];
	center[0] = pos[0] + dims[0] / 2.0f;
	center[1] = pos[1] + dims[1] / 2.0f;
	center[2] = pos[2] + dims[2] / 2.0f;
}


Player::Player(float _x, float _y, float _z, float _s)
{
	pos = new float[3];
	pos[0] = _x;
	pos[1] = _y;
	pos[2] = _z;

	speed = _s;
}

void Player::draw() {
	glPushMatrix();
	{
		glTranslatef(pos[0], pos[1], pos[2]);
		glRotatef(90, 1, 0, 0);
		glmDraw(sintel, GLM_SMOOTH | GLM_TEXTURE);
	}
	glPopMatrix();
}

void Player::move(unsigned char key) {
	//printf("%c \n", key);
	
	switch (key) {
	case 'w':
		pos[1] += speed;
		break;
	case 's':
		pos[1] -= speed;
		break;
	case 'd':
		pos[0] += speed;
		break;
	case 'a':
		pos[0] -= speed;
		break;
	}
}

void Player::update() {
	glPushMatrix();
	{
		glTranslatef(pos[0], pos[1], pos[2]);
	}
	glPopMatrix();
}
