#include "ListaCollider.h"

ListaCollider::ListaCollider()
{
	for (int i = 0; i < MAX_COLLIDER_ELEM; i++) {
		lista[i] = NULL;
	}
	numero = 0;
}

bool ListaCollider::AddCollider(ColliderMap* c)
{
	if (numero < MAX_COLLIDER_ELEM) {
		lista[numero++] = c;
		return true;
	}else
	return false;
}

void ListaCollider::Dibuja()
{
	for (int i = 0; i < numero; i++) {
		lista[i]->Dibuja();
	}
}

void ListaCollider::DestruirContenido()
{
	for (int i = 0; i < numero; i++) {
		delete lista[i];
	}
	numero = 0;
}

void ListaCollider::Eliminar(int index)
{
	if ((index > MAX_COLLIDER_ELEM)||(index<0))
		return;
	else {
		delete lista[index];
		for (int i = index; i < numero; i++) {
			lista[i] = lista[i + 1];
		}
		numero--;
	}
}

void ListaCollider::Eliminar(ColliderMap* c)
{
	for (int i = 0; i < numero; i++) {
		if (lista[i] == c) {
			Eliminar(i);
			return;
		}
	}
}

ColliderMap* ListaCollider::operator[](int i)
{
	if (i < 0)
		return lista[0];
	else if ((i > MAX_COLLIDER_ELEM) || (i > numero))
		return lista[MAX_COLLIDER_ELEM - 1];
	else
		return lista[i];
	
}

/*void ListaCollider::Mueve(float t)
{
	for (int i = 0; i < numero; i++) {
		lista[i].
	}
}*/
