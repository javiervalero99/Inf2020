
#pragma once
#include "Enemigo.h"
#include "Personaje.h"
#include "Mortero.h"
class Artillero :
	public Enemigo
{
	Mortero* m;
	bool reload;

public:
	Artillero();
	bool ataca(Personaje& p);
	void Mueve(float t) {}

	void Persigue(Personaje& p) {}
};