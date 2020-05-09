#pragma once
#include "ListaCollider.h"
#include "Personaje.h"
#include "CollisionMundo.h"
class InteraccionListas {
public:
	static bool Collision(Personaje& h, ListaCollider lista);
};