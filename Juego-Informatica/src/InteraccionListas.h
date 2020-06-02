#pragma once
#include "ListaCollider.h"
#include "Personaje.h"
#include "Enemigo.h"
#include "CollisionMundo.h"
#include "ListaEnemObj.h"
#include "CajaMunicion.h"
class InteraccionListas {
public:
	static bool Collision(Personaje& h, ListaCollider lista);
	static bool Collision(ObjetoGeneral& h, ListaCollider lista);
	static bool Collision(ListaEnemObj& l, ListaCollider lista);
	static bool Collision(ListaEnemObj& l, Personaje& h);
	static bool Collision(CajaMunicion& l, ListaCollider lista);
	static bool Collision(CajaMunicion& l, Personaje& per);

};
