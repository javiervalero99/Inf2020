#pragma once
#include "Flecha.h"

class Carcaj
{
private:
	Flecha* flechas[5];
	int numero;
	int max_elem;
	bool impacto;
public:
	Carcaj();
	virtual ~Carcaj();
	void destruirContenido();
	void Dibuja();
	void Mueve(float t);
	void eliminar(int index);
	Flecha* operator [](int i);

	bool agregar(int x , int y, bool b);
	inline  int getNumero() {
		return numero;
	}
};






