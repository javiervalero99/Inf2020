#pragma once
#include "ColliderMap.h"
#include <iostream>
#define MAX_COLLIDER_ELEM 200
class ListaCollider {
public:
	ListaCollider();
	virtual ~ListaCollider(){}
	//Metodos
	bool AddCollider(ColliderMap* c);
	void Dibuja();
	//void Mueve(float t);
	void DestruirContenido();
	void Eliminar(int index);
	void Eliminar(ColliderMap* c);
	int GetNumero() { return numero; }
	ColliderMap* operator[](int i);
private:
	ColliderMap* lista[MAX_COLLIDER_ELEM];
	int numero;
};
