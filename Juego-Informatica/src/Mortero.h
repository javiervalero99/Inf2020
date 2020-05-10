#pragma once
#include "Vector2D.h"
#include <math.h>
#include "Personaje.h"
#include "glut.h"
class Mortero {

public:
	Mortero();
	virtual ~Mortero();

	float angulo;
	float velo0;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;

	void Dibuja();
	bool disparo(float x);
	void Mueve(float t);
	void detona(Personaje& p);


};