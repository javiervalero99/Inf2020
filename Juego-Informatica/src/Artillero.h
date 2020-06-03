#pragma once
#include "ETSIDI.h"
#include "Enemigo.h"
#include "Mortero.h"
#include "CajaMunicion.h"

using ETSIDI::SpriteSequence;

class Artillero :
	public Enemigo
{
	CajaMunicion CajaMun;
	double reload;

	//sprites
	SpriteSequence statico;
	SpriteSequence atack;
	SpriteSequence die;
	int estado_atq;
	bool estoy_disp;
	int estado_muerte;
	bool me_muero;
	int contador_muerte;
	

public:
	Artillero();
	bool ataca(Personaje& p);
	void Mueve(float t);
	void Dibuja();
	 CajaMunicion& Getcaja();
};
