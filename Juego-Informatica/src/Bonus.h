#include "ETSIDI.h"
#include <iostream>
#include <cmath>
#include <stdio.h>
#include "Enemigo.h"
#include "Collision_Movil.h"
#include "Personaje.h"
#include "glut.h"

using ETSIDI::SpriteSequence;

class Bonus : public ObjetoGeneral
{
public:
	Bonus();
	Bonus(float posx,float py);
	~Bonus();
	void Dibuja();
	void Mueve(float t);
	void Persigue(Personaje& p);
	bool ataca(Personaje& p) { return false; }
	void SetStatus() { impacto_personaje = true; }
	bool GetStatus() { return impacto_personaje; }
	bool GetPersonajeCurado() { return personaje_curado; }

	friend class Interaccion;
protected:
	SpriteSequence Pocion;
	bool personaje_curado;
	bool impacto_personaje;
};