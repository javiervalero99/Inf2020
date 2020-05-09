#include "InteraccionListas.h"

bool InteraccionListas::Collision(Personaje& h, ListaCollider lista)
{
	bool InCollider = false;
	bool valid = false;
	for (int i = 0; i < lista.GetNumero(); i++) {
		if(lista[i]->Encima==NULL)
		valid=CollisionMundo::Collision(h, (*lista[i]));
		else {
			valid = CollisionMundo::Collision(h, *lista[i], *lista[i]->Encima);
		}
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
