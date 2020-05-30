#include "CajaMunicion.h"

CajaMunicion::CajaMunicion()
{
	usados = 0;
	for (int i = 0; i < MAX_MORTEROS; i++)
		CajaMun[i] = 0;
}

CajaMunicion::~CajaMunicion()
{
}

void CajaMunicion::destruirContenido()
{
	for (int i = 0; i <usados; i++)
		delete CajaMun[i];
	usados = 0;
}

void CajaMunicion::Dibuja()
{
	CajaMun[usados]->Dibuja();
}

void CajaMunicion::Mueve(float t)
{
	CajaMun[usados]->Mueve(t);
}

void CajaMunicion::eliminar(int index)
{
}

Mortero* CajaMunicion::operator[](int i)
{
	if (i >= usados)//si t pasas te deuelve la ultima
		i = usados - 1;
	if (i < 0) // si te paas por abajo
		i = 0;
	return CajaMun[i];
}
