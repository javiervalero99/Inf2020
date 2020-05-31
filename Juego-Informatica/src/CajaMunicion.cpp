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
	for (int i = 0; i < usados; i++) {
		if (CajaMun[i]->getStatus() == true)
	delete CajaMun[i];
		
	}
}

bool CajaMunicion::agregar(Vector2D art, float range)
{
	if (usados < MAX_MORTEROS)
	{

		CajaMun[usados++] = new Mortero(art, range);
	}
	else
		return false;
	return true;
}

void CajaMunicion::Dibuja()
{
	for (int i = 0; i < usados; i++)
		CajaMun[i]->Dibuja();
}

void CajaMunicion::Mueve(float t)
{
	for (int i = 0; i < usados; i++)
		CajaMun[i]->Mueve(t);
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

int CajaMunicion::getelem()
{
	return usados;
}
