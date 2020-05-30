#include "Artillero.h"

Artillero::Artillero()
{
	m = NULL;

}

bool Artillero::ataca(Personaje& p)
{
	float acc;

	if (DistanciaPlayer(p) < 3) {
		return true;
	}
	else
		return false;



}
