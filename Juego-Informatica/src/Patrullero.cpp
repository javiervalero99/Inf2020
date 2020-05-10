#include "Patrullero.h"
#pragma once

void Patrullero::patrulla(float x1, float x2)
{
	if (fabs(posicion.x) <= x1)
		velocidad.x = -3;
	if (fabs(posicion.x) >= x2)
		velocidad.x = 3;
}
void Patrullero::Persigue(Personaje& p)
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
	else {//enemigo en modo default; puede implantarse lo que sea
		patrulla(19, 22);
	}

}
