#pragma once
#include "Enemigo.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;

class Patrullero : public Enemigo {
private:
	SpriteSequence Run;//sprite corriendo
	SpriteSequence Die;//sprite para muerte
	SpriteSequence Attack;//sprite catacando
	SpriteSequence Surprise;//sprite sorpednido 
	

	int estado_ataque;
	int estado_die;
	int estado_ay_caramba;
	bool estoy_atacando;
	bool me_muero;
	bool rayos_y_centellas;
public:
	Patrullero();
	void patrulla(float x1, float x2);
	void Persigue(Personaje& p);
	void Dibuja();
	void Mueve(float t);
	bool ataca(Personaje& p);
	int contador,contador_a ;


};