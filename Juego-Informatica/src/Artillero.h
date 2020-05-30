#pragma once
#include "Enemigo.h"
#include "Mortero.h"
class Artillero :
	public Enemigo
{
	Mortero* m;
	bool reload;

public:
	Artillero();
	bool ataca(Personaje& p);
};
