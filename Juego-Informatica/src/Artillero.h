#pragma once
#include "Enemigo.h"
#include "Mortero.h"
#include "CajaMunicion.h"
class Artillero :
	public Enemigo
{
	CajaMunicion CajaMun;
	double reload;

public:
	Artillero();
	bool ataca(Personaje& p);
	void Mueve(float t);
	void Dibuja();
	 CajaMunicion& Getcaja();
};
