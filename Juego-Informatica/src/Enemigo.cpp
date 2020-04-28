#include "Enemigo.h"
#pragma once

Enemigo::Enemigo()
{
	posicion.x = -20;
	posicion.y = 8+1.3/2;
	velocidad.x = 1;
}

Enemigo::~Enemigo()
{
}

void Enemigo::Dibuja()
{
	glPushMatrix();
	glTranslated(posicion.x, posicion.y, 0);
	glColor3ub(255, 0, 0);
	glutSolidCube(1.3f);
	glTranslated(-posicion.x, -posicion.y, 0);
	glPopMatrix();

}

void Enemigo::Mueve(float t)
{



	posicion.x += velocidad.x * 0.025 + (1 / 2) * aceleracion.x * pow(0.025, 2);
	velocidad.x -= aceleracion.x * 0.025;
	//salto
	velocidad.y -= aceleracion.y * 0.025;
	posicion.y += velocidad.y * 0.025 - (1 / 2) * aceleracion.y * pow(0.025, 2);

	if (cae == true) {
		aceleracion.y = 30;
		cae = false;
	}



}

Vector2D Enemigo::GetPosicion()
{
	Vector2D res = posicion;
	return res;
	
}

void Enemigo::Persigue(Personaje& p)
{
	// si no hay nada en medio(las disntacias  otra cosa no es mayor ) lo persigue
	float acc = 5;


	if (acc >= DistanciaPlayer(p))
	{
		// to do - preparar la matematica de pserseguir
		float mov = p.posicion.x - posicion.x;
		if (mov < 0)
		{
			velocidad.x = -2;
		}
		else
			velocidad.x = 2;


	}
	else  {//enemigo en modo default; puede implantarse lo que sea
		patrulla(19, 22);
	}

}

float Enemigo::DistanciaPlayer(Personaje& a)
{
	Vector2D dist;
	dist.x = fabsf(a.GetPosicion().x - posicion.x);
	dist.y = fabsf(a.GetPosicion().y - posicion.y);

	float res = dist.modulo();
	return res;



}

float Enemigo::DistanciaPared()
{
	return 0.0f;
}

void Enemigo::patrulla(ColliderMap& a, ColliderMap& b)
{
	//sacas la distancia y si colisionas contra a
	velocidad.x = 3;
	// si colisiona contra b
	velocidad.x = -3;

}

void Enemigo::patrulla(float x1, float x2)
{

		if (fabs(posicion.x) <= x1)
	velocidad.x = -3;
		if (fabs(posicion.x) >= x2)
		velocidad.x = 3;

}
