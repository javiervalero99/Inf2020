#pragma once
#include "Personaje.h"
#include "ColliderMap.h"
#include "ObjetoGeneral.h"
class CollisionMundo {
public:

	CollisionMundo();
	virtual ~CollisionMundo();
	static bool Collision(Personaje& per, ColliderMap pared);
	static bool Collision(ObjetoGeneral& per, ColliderMap pared);

};
