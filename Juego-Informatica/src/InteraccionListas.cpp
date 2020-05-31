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
	}
	return true;
}

bool InteraccionListas::Collision(ListaEnemObj& l, Personaje& h)
{
	double Actual = GetTickCount();

	for (int i = 0; i < l.GetNumElem(); i++) {
		bool choque = false;
		choque = CollisionMundo::Collision(l[i], h);
		if (choque) {

			if ((h.validacionAsignacion) && (l[i].tipo == 0)) {//Ataque personaje enemigo
				l[i].AddSalud(h.Dañoataque);
				h.validacionAsignacion = false;
			}
			if (l[i].validacionAsignacion) { //Interaccion ObjetoGeneral con salud del personaje
				h.AddSalud(l[i].asignacionSalud);
				l[i].validacionAsignacion = false;
			}
		}
	}
	return true;
}

