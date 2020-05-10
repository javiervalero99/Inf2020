#include "Personaje.h"
#include <cmath>
#include <stdio.h>
#include "glut.h"

#define SPACEBAR 32

Personaje::Personaje()
{
	posicion.x = 0;
	posicion.y = 0;
	valid_salto = true;
	cae = false;
	salud = 3;
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


	//printf("r=%d y velocidad=%f\n", r, velocidad.x);
	posicion.x += velocidad.x * 0.025 + (1 / 2) * aceleracion.x * pow(0.025, 2);
	velocidad.x -= aceleracion.x * 0.025;
	//salto
	velocidad.y -= aceleracion.y * 0.025;
	posicion.y += velocidad.y * 0.025 - (1 / 2) * aceleracion.y * pow(0.025, 2);

	/*if (posicion.y <= 0) {
		velocidad.y = 0;
		aceleracion.y = 0;
		q = 0;
		valid_salto = true;
	}*/

	if (velocidad.x > 10)
		velocidad.x = 10;
	if (velocidad.x < -10)
		velocidad.x = -10;

	//compensacion de la acerlacion
	if (abs(velocidad.x) < 2 && aceleracion.x != 0)
	{
		velocidad.x = 0;
		aceleracion.x = 0;
	}
	// 
	//gestiom maquina de estados 
	if (estados[0] == estados[1]) {
		if (velocidad.x < 0)
			aceleracion.x = -20;
		if (velocidad.x > 0)
			aceleracion.x = 12;

	}
	if (cae == true) {
		aceleracion.y = 30;
		cae = false;
	}
	else if (estados[0] == 1 && estados[1] == 0)
		velocidad.x = 10;
	else if (estados[0] == 0 && estados[1] == 1)
		velocidad.x = -10;
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
	if (posicion.y == 0)
	{
		valid_salto = true;

	}

	if ((f == ' ') && (valid_salto == true))
	{
		aceleracion.y = 20.0;
		velocidad.y = 12.5;
		q = 1;
		valid_salto = false;
	}
	if (f == 'a'  || f == 'A')
		estados[0] = 1;

	if (f == 'd' || f == 'D') {


		estados[1] = 1;
	}

};


void Personaje::TeclaUp(unsigned char f) { //esta va con glutKeyboardUpFunc
	if (f == 'a' || f == 'A')
		estados[0] = 0;
	if (f == 'd' || f == 'D')
		estados[1] = 0;

}
int Personaje::GetSalud()
{
	
	int	s = salud;
	return s;
}
void Personaje::SetSalud(int n)
{
	salud = n;
}


