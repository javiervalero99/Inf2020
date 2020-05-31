#pragma once
#include "Mortero.h"

#define MAX_MORTEROS 10
class CajaMunicion {  //esta clase no coge los moretors, cuenta los que ya ha usado
private:
	Mortero* CajaMun[MAX_MORTEROS];
	int usados;
	int max_elem;
public:
	CajaMunicion();
	virtual ~CajaMunicion();
	void destruirContenido();
	bool agregar(Vector2D art, float range);
	void Dibuja();
	void Mueve(float t);
	void eliminar(int index);
	Mortero* operator [](int i);
	int getelem();
};