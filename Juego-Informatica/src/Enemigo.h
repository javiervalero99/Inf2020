#pragma once
#include "Vector2D.h"
#include "Personaje.h"
#include "ColliderMap.h"
#include <math.h>
#include "glut.h"
class Enemigo {
public:
	float altura;
	float salud;
	bool cae;
	int j, q;

public:
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;

	Enemigo();
	~Enemigo();
	virtual void Dibuja();
	void Mueve(float t);
	Vector2D GetPosicion();
	void Persigue(Personaje& p);
	float DistanciaPlayer(Personaje& a);
	float DistanciaPared();
	void ataca(Personaje& p);
	

	friend class Interaccion;
};
