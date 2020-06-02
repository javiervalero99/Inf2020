#include "InteraccionListas.h"

bool InteraccionListas::Collision(Personaje& h, ListaCollider lista)
{
	bool InCollider = false;
	bool valid = false;
	for (int i = 0; i < lista.GetNumero(); i++) {
		valid = CollisionMundo::Collision(h, (*lista[i]));
		if (valid == true)
			InCollider = true;
	}
	if (InCollider == false) {
		h.cae = true;
		h.j++;
		return false;
	}
	else
		return true;
}
bool InteraccionListas::Collision(ObjetoGeneral& p, ListaCollider lista)
{
	bool InCollider = false;
	bool valid = false;
	for (int i = 0; i < lista.GetNumero(); i++) {
		valid = CollisionMundo::Collision(p, (*lista[i]));
		if (valid == true)
			InCollider = true;
	}
	if (InCollider == false) {
		p.cae = true;
		p.j++;
		return false;
	}
	else
		return true;
}

bool InteraccionListas::Collision(ListaEnemObj& l, ListaCollider lista)
{
	for (int i = 0; i < l.GetNumElem(); i++) {
		Collision(l[i], lista);
		if (l[i].ifArtillero)
			Collision(l[i].Getcaja(), lista);
	}
	return true;
}

bool InteraccionListas::Collision(ListaEnemObj& l, Personaje& h)
{
	double Actual = GetTickCount();

	for (int i = 0; i < l.GetNumElem(); i++) {
		if (l[i].ifArtillero)
			Collision(l[i].Getcaja(), h);
		bool choque = false;
		choque = CollisionMundo::Collision(l[i], h);
		if (choque) {

			if ((h.validacionAsignacion) && (l[i].tipo == 0)) {//Ataque personaje enemigo
				l[i].AddSalud(h.Dañoataque);
				h.validacionAsignacion = false;
			}
			 else if (l[i].validacionAsignacion) { //Interaccion ObjetoGeneral con salud del personaje
				h.AddSalud(l[i].asignacionSalud);
				l[i].validacionAsignacion = false;

			}
		}
	}
	return true;
}

bool InteraccionListas::Collision(CajaMunicion& l, ListaCollider lista)
{
	if (l.getelem() != 0)
	{
		for (int i = 0; i < MAX_MORTEROS; i++)

		{
			for (int j = 0; j < lista.GetNumero(); j++)
				CollisionMundo::Collision(*l[i], *lista[j]);
		}
	}
	return 0;
}

bool InteraccionListas::Collision(CajaMunicion& l, Personaje& h)
{
	double Actual = GetTickCount();

	for (int i = 0; i < l.getelem(); i++) {
		bool choque = false;
		choque = CollisionMundo::Collision(*l[i], h);
		if (choque) {

			if (l[i]->validacionAsignacion) { //Interaccion ObjetoGeneral con salud del personaje
				h.AddSalud(l[i]->asignacionSalud);
				l[i]->validacionAsignacion = false;
			}
		}
	}
	return true;
}

bool InteraccionListas::Collision(ListaEnemObj& l, Carcaj& c)
{
	for (int i = 0; i < c.getNumero(); i++) {
		for (int j = 0; j < l.GetNumElem(); j++) {
			//CollisionMundo::Collision(*c[i], *l[i]);
		}
	}
	return false;
}

bool InteraccionListas::Collision(ListaCollider& l, Carcaj& c)
{
	for (int i = 0; i < c.getNumero(); i++) {
		for (int j = 0; j < l.GetNumero(); j++) {
			CollisionMundo::Collision(*c[i], *l[i]);
		}
	}
	return false;
}
