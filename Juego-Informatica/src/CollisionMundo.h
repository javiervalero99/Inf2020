#pragma once
#include "Personaje.h"
#include "ColliderMap.h"
class CollisionMundo {
public:

	CollisionMundo();
	virtual ~CollisionMundo();
	static bool Collision(Personaje& per, ColliderMap pared);
	static bool Collision(Personaje& per, ColliderMap pared,ColliderMap paredEncima);
};
