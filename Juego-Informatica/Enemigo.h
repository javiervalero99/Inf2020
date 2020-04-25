#pragma once
#include "Vector2D.h"
#include "Personaje.h"
#include "glut.h"
#include "ColliderMap.h"
#include <math.h>
class Enemigo {
public:
	float altura;
	float salud;



public:
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;

	Enemigo();
	~Enemigo();
	void Dibuja();
	void Mueve(float t);
	void Persigue(Personaje& p);
	float DistanciaPlayer(Personaje& a);
	float DistanciaPared();
	void patrulla(ColliderMap& a, ColliderMap& b);

	friend class Interaccion;
};
