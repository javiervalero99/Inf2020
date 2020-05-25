#pragma once
#include "Enemigo.h"
#include "Mortero.h"
class Artillero :
	public Enemigo
{
	
public:

	void ataca(Personaje& p);
};

