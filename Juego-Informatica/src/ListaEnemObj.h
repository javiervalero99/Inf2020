#pragma once
#include "Vector2D.h"
#include "ObjetoGeneral.h"
#include "Personaje.h"
#include <stdlib.h>
#define MAX_NUM_ELEM 200
class ListaEnemObj {
private:
	ObjetoGeneral* lista[MAX_NUM_ELEM];
	int n;
public:
	ListaEnemObj();
	~ListaEnemObj();
	ListaEnemObj(const ListaEnemObj& L);
	bool AddElem(ObjetoGeneral* m);
	bool DeleteElem(ObjetoGeneral* m);
	bool DeleteElem(int idex);
	ObjetoGeneral& GetElem(int index)const { return *lista[index]; }
	int GetNumElem() { return n; }
	bool clear();
	ObjetoGeneral& operator[](int index);
	void operator=(const ListaEnemObj& L);
	void Dibuja();
	void Mueve(float t);
	void Persigue(Personaje& p);

};
