#pragma once
#include "Personaje.h"
#include "Enemigo.h"
#include "ColliderMap.h"
class CollisionMundo {
public:

	CollisionMundo();
	virtual ~CollisionMundo();
	static bool Collision(Personaje& per, ColliderMap pared);
	//static bool Collision(Personaje& per, ColliderMap pared,ColliderMap paredEncima);
	static bool Collision(Enemigo& per, ColliderMap pared);
};
