#pragma once
#include "Vector2D.h"

class Collision_Movil {
protected:
	Vector2D tam;
public:
	Collision_Movil();
	virtual ~Collision_Movil(){}
	void Dibuja();
	void setTam(float px, float py) { tam.x = px; tam.y = py; }
	friend class CollisionMundo;
};
