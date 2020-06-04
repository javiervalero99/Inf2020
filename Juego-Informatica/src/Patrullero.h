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
	int estado_muerte;
	bool estoy_atacando;
	bool me_muero;
	bool rayos_y_centellas;
	int patrulla1, patrulla2;
	
public:
	Patrullero();
	Patrullero(int x, int y,int p1, int p2);
	void patrulla(float x1, float x2);
	void Persigue(Personaje& p);
	void Dibuja();
	void Mueve(float t);
	bool ataca(Personaje& p);
	int contador,contador_a ,contador_nuerte;


};