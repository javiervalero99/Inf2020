#include "Enemigo.h"
#pragma once

Enemigo::Enemigo() :ObjetoGeneral(-20, 8 + 1.3 / 2, 1, 0, 1.3, 1.3, 0)
{
	validacionAsignacion = true;
	asignacionSalud = -1;
}

Enemigo::~Enemigo()
{
}

void Enemigo::Dibuja()
{
	glPushMatrix();
	glTranslated(posicion.x, posicion.y, 0);
	glColor3ub(255, 0, 0);
	Collider.Dibuja();
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


void Enemigo::Persigue(Personaje& p)
{
	// si no hay nada en medio(las disntacias  otra cosa no es mayor ) lo persigue
	float acc = 15;


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

bool Enemigo::ataca(Personaje& p)
{
	float acc = 2;
	if (DistanciaPlayer(p) < acc) {
		// to-do meterla animacion
		p.SetSalud(p.GetSalud() - 1);
		return true;

	}
}

