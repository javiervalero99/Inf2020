#include "ListaEnemObj.h"

ListaEnemObj::ListaEnemObj()
{
	int n = 0;
	for (int i = 0; i < MAX_NUM_ELEM; i++)
		lista[i] = NULL;
}

ListaEnemObj::~ListaEnemObj()
{
	for (int i = 0; i < MAX_NUM_ELEM; i++) {
		delete lista[i];
	}
}

ListaEnemObj::ListaEnemObj(const ListaEnemObj& L)
{
	n = L.n;
	for (int i = 0; i < n; i++)
		lista[i] = L.lista[i];

}

bool ListaEnemObj::AddElem(ObjetoGeneral* m)
{
	if (n < MAX_NUM_ELEM) {
		lista[n] = m;
		n++;
		return true;
	}
	else {
		return false;
	}

}

bool ListaEnemObj::DeleteElem(ObjetoGeneral* m)
{
	for (int i = 0; i < n; i++) {
		if (lista[i] == m) {
			DeleteElem(i);
			return true;
		}
	}
	return false;
}

bool ListaEnemObj::DeleteElem(int index)
{
	if (n < index) {
		for (int i = index; i < n; i++)
			lista[i] = lista[i + 1];
		n--;
		return true;
	}
	else {
		return false;
	}
}

bool ListaEnemObj::clear()
{
	int n = 0;
	for (int i = 0; i < MAX_NUM_ELEM; i++)
		lista[i] = NULL;
	return true;
}

ObjetoGeneral& ListaEnemObj::operator[](int index)
{
	return *lista[index];
}

void ListaEnemObj::operator=(const ListaEnemObj& L)
{
	n = L.n;
	for (int i = 0; i < n; i++)
		lista[i] = L.lista[i];
}

void ListaEnemObj::Dibuja()
{
	for (int i = 0; i < n; i++)
		lista[i]->Dibuja();
}

void ListaEnemObj::Mueve(float t)
{
	for (int i = 0; i < n; i++)
		lista[i]->Mueve(t);
}

void ListaEnemObj::Persigue(Personaje& p)
{

	for (int i = 0; i < n; i++)
		lista[i]->Persigue(p);
}

bool ListaEnemObj::ataca(Personaje& p)
{
	for (int i = 0; i < n; i++)
		lista[i]->ataca( p);
	return true;
}
