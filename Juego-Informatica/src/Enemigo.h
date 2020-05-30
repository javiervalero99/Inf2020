#pragma once
#include "Vector2D.h"
#include "Personaje.h"
#include "ColliderMap.h"
#include "ObjetoGeneral.h"
#include <math.h>
#include "glut.h"
class Enemigo :public ObjetoGeneral {

public:


	Enemigo();
	~Enemigo();
	void Dibuja();
	virtual void Mueve(float t);

	void Persigue(Personaje& p);
	float DistanciaPlayer(Personaje& a);
	float DistanciaPared();
	void ataca(Personaje& p);


	friend class Interaccion;
};

