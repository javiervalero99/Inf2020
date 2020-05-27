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


public: 
	Patrullero();
	void patrulla(float x1, float x2);
	void Persigue(Personaje& p);
	void Dibuja();
	void Mueve(float t);



};