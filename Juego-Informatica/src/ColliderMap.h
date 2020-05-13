#pragma once
#include "vector2D.h"
#include <iostream>
class ColliderMap {
public:
	ColliderMap();
	ColliderMap(float Arribax, float Arribay, float Abajox, float Abajoy);
	virtual ~ColliderMap(){}
	void Inicializa(float arribax, float arribay, float abajox, float abajoy){
		Arriba.x = arribax; //Arrba y izq
		Arriba.y = arribay;
		Abajo.x = abajox; //Abajo y dch
		Abajo.y = abajoy;
	}
	void Dibuja();
	Vector2D Arriba;
	Vector2D Abajo;
	friend class CollisionMundo;
};