#pragma once
#include "ListaCollider.h"
#include "Personaje.h"
#include "Enemigo.h"
#include "CollisionMundo.h"
class InteraccionListas {
public:
	static bool Collision(Personaje& h, ListaCollider lista);
	static bool Collision(Enemigo& h, ListaCollider lista);
};