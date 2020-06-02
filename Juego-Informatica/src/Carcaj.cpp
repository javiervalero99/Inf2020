#include "Carcaj.h"

Carcaj::Carcaj()
{
	max_elem = 5;
	numero = 0;
	for (int i = 0; i < 3; i++)
		flechas[i] = 0;
	impacto = false;
}

Carcaj::~Carcaj()
{
}

void Carcaj::destruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete flechas[i];
	numero = 0;
}

void Carcaj::Dibuja()
{
	for (int i = 0; i < numero; i++)
	flechas[i]->Dibuja();
}

void Carcaj::Mueve(float t)
{
	for (int i = 0; i < numero; i++)
	flechas[i]->Mueve(t);
}

void Carcaj::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete flechas[index];
	numero--;
	for (int i = index; i < numero; i++)
		flechas[i] = flechas[i + 1];

}

Flecha* Carcaj::operator[](int i)
{
	if (i >= numero)//si t pasas te deuelve la ultima
		i = numero - 1;
	if (i < 0) // si te paas por abajo
		i = 0;
	return flechas[i];
}

bool Carcaj::agregar (int x, int y, bool b)
{
	if (numero < 5)
	{

		flechas[numero++] = new Flecha(x,y,b);
		flechas[numero-1]->SetFlecha(x, y,b);
	}
	else
		return false;
	return true;
}
