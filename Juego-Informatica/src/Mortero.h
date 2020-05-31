#pragma once
#include "Collision_Movil.h"
#include "Vector2D.h"
#include <math.h>
#include "Personaje.h"
#include "glut.h"

class Mortero {
	bool kabum;
public:
	Mortero();
	Mortero(Vector2D a, float range);
	virtual ~Mortero();

	float angulo;
	float velo0;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;

	void Dibuja();
	bool disparo(float x);
	void Mueve(float t);
	bool detona();
	void SetPos(Vector2D pos);
	Vector2D GetPosicion();
	Collision_Movil collider;
	void SetStatus( );
	bool getStatus();
};