#pragma once
#include "ListaCollider.h"
#include "Personaje.h"
#include "Enemigo.h"
#include "CollisionMundo.h"
#include "ListaEnemObj.h"
class InteraccionListas {
public:
	static bool Collision(Personaje& h, ListaCollider lista);
	static bool Collision(ObjetoGeneral& h, ListaCollider lista);
	static bool Collision(ListaEnemObj& l, ListaCollider lista);
	static bool Collision(ListaEnemObj& l, Personaje& h);
};