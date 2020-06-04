#pragma once
#include "Personaje.h"
#include "ColliderMap.h"
#include "ObjetoGeneral.h"
#include "Flecha.h"
#include "Mortero.h"
class CollisionMundo {
public:

	CollisionMundo();
	virtual ~CollisionMundo();
	static bool Collision(Personaje& per, ColliderMap pared);
	static bool Collision(ObjetoGeneral& per, ColliderMap pared);
	static bool Collision(ObjetoGeneral& obj, Personaje& per);
	static bool Collision(Mortero& mor, ColliderMap pared);
	static bool Collision(Mortero& obj, Personaje& per);
	static bool Collision(Flecha& f, ColliderMap pared);
	static bool Collision(ObjetoGeneral& obj, Flecha& f);
};