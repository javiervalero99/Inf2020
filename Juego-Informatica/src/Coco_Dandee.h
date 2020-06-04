#pragma once
#include "Patrullero.h"

class Croco : public Patrullero {
private: 
	SpriteSequence move;//sprite corriendo
	SpriteSequence Die;//sprite para muerte
	SpriteSequence Attack;//sprite catacando
public:
	Croco();
	Croco(int x, int y, int p1, int p2);
	void Dibuja();
	void Mueve(float t);
	void Persigue(Personaje& p);
	double delay;
};