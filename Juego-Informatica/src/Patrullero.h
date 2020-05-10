#pragma once
#include "Enemigo.h"

class Patrullero : public Enemigo {

public: 
	void patrulla(float x1, float x2);
	void Persigue(Personaje& p);
};