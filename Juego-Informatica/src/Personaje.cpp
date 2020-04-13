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
 //Ecuaciones de movimiento
	posicion.x += velocidad.x * t + (1 / 2) * aceleracion.x * pow(t, 2);
	printf("x=%f\n", posicion.x);
	velocidad.x += aceleracion.x * t;
	posicion.y += velocidad.y * t + (1 / 2) * aceleracion.y * pow(t, 2);
	velocidad.y += aceleracion.y * t;*/
	//
	if ((r == 1) && (velocidad.x <= 10.0))
		velocidad.x += s;
	if ((r == 2) && (velocidad.x > 0))
		velocidad.x -= m;
	if ((r == 3) && (velocidad.x >= -10.0))
		velocidad.x -= s;
	if ((r == 4) && (velocidad.x < 0))
		velocidad.x += m;
	if (((r == 2) && (velocidad.x <= 0)) || ((r == 4) && (velocidad.x >= 0))) {
		velocidad.x = 0;
		r = 0;
	}
	//printf("r=%d y velocidad=%f\n", r, velocidad.x);
	posicion.x += velocidad.x * 0.025;
	//salto
	velocidad.y -= aceleracion.y * 0.025;
	posicion.y += velocidad.y * 0.025 - (1 / 2) * aceleracion.y * pow(0.025, 2);

	if (posicion.y <= 0) {
		velocidad.y = 0;
		aceleracion.y = 0;
		q = 0;
		valid_salto = true;
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

	if ((f == ' ') && (valid_salto == true))
	{
		aceleracion.y = 20.0;
		velocidad.y = 10.0;
		q = 1;
		valid_salto = false;
	}
	if (f == 'a') {
		r = 1;

	}
	if (f == 'd') {
		r = 3;

	}
	if (q != 0) {
		s = 2.6;
		m = 3;
	}
	if (q == 0) {
		if ((f == 'a') || (f == 'd')) {
			s = 0.6;
			m = 1.0;
		}

	}
	if (f == 'k') {
		while (1) {
		}
	}
};


void Personaje::TeclaUp(unsigned char f) { //esta va con glutKeyboardUpFunc
	if (f == 'a') {
		r = 2;
	}
	if (f == 'd') {
		r = 4;
	}



};
