#pragma once
#include "Mortero.h"

Mortero::Mortero()
{
	velo0 = 20;
	velocidad.x = velo0;
	velocidad.y = velo0;
}

Mortero::~Mortero()
{
	aceleracion.y = -9.8;
}

void Mortero::Dibuja()
{
	glPushMatrix();
	glTranslated(posicion.x, posicion.y, 0);
	glutSolidSphere(2,30,40);
	glTranslated(-posicion.x, -posicion.y, 0);
	glPopMatrix();
}


bool Mortero::disparo(float x) //crea la parabola y dice si se ha disparado
{
	angulo = (9.8 * x) / (velo0 * velo0);
	angulo = (asin(angulo) / 2);
	velocidad.x = velo0 * cos(angulo);
	velocidad.y = velo0 * sin(angulo);
	return true;

}

void Mortero::Mueve(float t)
{

	posicion.x += velocidad.x * 0.025 + (1 / 2) * aceleracion.x * pow(0.025, 2);
	velocidad.x -= aceleracion.x * 0.025;
	//salto
	velocidad.y -= aceleracion.y * 0.025;
	posicion.y += velocidad.y * 0.025 - (1 / 2) * aceleracion.y * pow(0.025, 2);
}

void Mortero::detona(Personaje& p)
{
	Vector2D explosion = p.posicion - posicion;
	if (explosion.modulo < 3.0);

	p.SetSalud = p.GetSalud - 2;
}


