#pragma once
#include "Mortero.h"

Mortero::Mortero(): collider(0.5, 0.5)
{
	velo0 = 15;

	velocidad.x = velo0;
	velocidad.y = velo0;
	aceleracion.y = 9.8;
	disparo(posicion.x + 6);
	kabum = false;
}

Mortero::Mortero(Vector2D a, float range):collider(0.5, 0.5){
	posicion = a;
	velo0 = 15;
	velocidad.x = velo0;
	velocidad.y = velo0;
	aceleracion.y = 9.8;
	disparo(posicion.x + range);
	
	kabum = false;
}



Mortero::~Mortero()
{

}

void Mortero::Dibuja()
{
	glPushMatrix();
	glTranslated(posicion.x, posicion.y, 0);
	glutSolidSphere(0.5, 30, 40);
	glTranslated(-posicion.x, -posicion.y, 0);
	glPopMatrix();
}


bool Mortero::disparo(float x) //crea la parabola y dice si se ha disparado  // rango max 3
{
	angulo = (9.8 * (x - posicion.x)) / (velo0 * velo0);
	angulo = ((3.14 / 2) - (asin(angulo) / 2));
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

bool Mortero::detona()
{

	/*Vector2D explosion = p.posicion - posicion;
	if (explosion.modulo() < 3.0);

	p.SetSalud( p.GetSalud() - 2);
	*/
	return 0;
}

void Mortero::SetPos(Vector2D pos)
{
	posicion = pos;
}

Vector2D Mortero::GetPosicion()
{
	return posicion;
}

void Mortero::SetStatus()
{
	kabum = true;
}

bool Mortero::getStatus()
{
	return kabum;
}

// calculo para el artillero
/*
xmax = (Vo*Vo) *sen(2a)/g
h lim = (Vo*Vo) *sen(a)/g
se coge el angulo complementario para buscar parabolas altas, a altas velocidades. si es el angulo menor es como un cañonazo
*/