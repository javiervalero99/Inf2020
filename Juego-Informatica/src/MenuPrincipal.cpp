#include "MenuPrincipal.h"


MenuPrincipal::MenuPrincipal(){}

MenuPrincipal::~MenuPrincipal()
{
}

void MenuPrincipal::SetDimensiones(float ancho, float largo)
{
	Ancho = ancho;
	Largo = largo;
}

void MenuPrincipal::SetNumeroOpciones(unsigned int x)
{
	NumeroOpciones = x;
}

void MenuPrincipal::DibujarMenu()
{
	for (int i = 0; i < NumeroOpciones; i++)
	{
		Options[i].Dibujar();
	}
}

void MenuPrincipal::Seleccionar_Opcion(unsigned char key, int x, int y)
{
}

void MenuPrincipal::SetOpciones()
{
	for (int i = 0; i < NumeroOpciones; i++)
	{
		
	}
}
