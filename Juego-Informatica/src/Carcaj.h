#pragma once
#include "Flecha.h"
#define MAX_FLECHAS_NUM 5
class Carcaj
{
private:
	Flecha* flechas[MAX_FLECHAS_NUM];
	int numero;
	int max_elem;
	bool impacto;
public:
	Carcaj();
	virtual ~Carcaj();
	void destruirContenido();
	void Dibuja();
	void Mueve(float t);
	void DeleteElem(int index);
	bool eliminar(Flecha* f);
	Flecha* operator [](int i);

	bool agregar(int x, int y, bool b);
	inline  int getNumero() {
		return numero;
	}
};





