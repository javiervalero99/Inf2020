#include "Personaje.h"
#include <math.h>
#include <stdio.h>
#include "glut.h"

#define SPACEBAR 32

Personaje::Personaje()
{
	posicion.x = 0;
	posicion.y = 0;
	valid_salto = true;
}

void Personaje::SetTiempo(float t)
{
	tiempo = t;
}

Personaje::~Personaje()
{
}

void Personaje::Mueve(float t)
{/*
	posicion.x += velocidad.x * t + (1 / 2) * aceleracion.x * pow(t, 2);
	printf("x=%f\n", posicion.x);
	velocidad.x += aceleracion.x * t;
	posicion.y += velocidad.y * t + (1 / 2) * aceleracion.y * pow(t, 2);
	velocidad.y += aceleracion.y * t;*/
	posicion.x += velocidad.x * 0.025;

	velocidad.y -= aceleracion.y * 0.025;
	posicion.y += velocidad.y * 0.025 - (1 / 2) * aceleracion.y * pow(0.025, 2);;
	if (posicion.y <= 0) {
		velocidad.y = 0;
		aceleracion.y = 0;
	}

}

void Personaje::Dibuja()
{
	glPushMatrix();
	glTranslated(posicion.x, posicion.y, 0);
	glutSolidCube(1.3f);
	glTranslated(-posicion.x, -posicion.y, 0);
	glPopMatrix();
}


Vector2D Personaje::GetPosicion() {
	Vector2D pos;
	pos.x = posicion.x;
	pos.y = posicion.y;

	return pos;

}



void Personaje::Ataque_Basico() {

}

void Personaje::Salto(unsigned char key) {

}

void Personaje::TeclaDown(unsigned char f) { //esta va con OnKeyboardDown
	if (f == 'a') {
		velocidad.x = 10;
	}
	if (f == 'd') {
		velocidad.x = -10;
	}
	//printf("velocidad=%f\n", velocidad.x);
	//printf("Aceleracion=%f\n", aceleracion.x);
	if (f == ' ')
	{
		aceleracion.y = 20.0;
		velocidad.y = 10.0;
	}
};


void Personaje::TeclaUp(unsigned char f) { //esta va con glutKeyboardUpFunc
	if (f == 'a' || f == 'd') {
		velocidad.x = 0;
		aceleracion.x = 0;
	}



};
