#pragma once
#define NUMERO_MAX_OPCIONES 5
#include "Opcion_Menu.h"
#include "glut.h"

class MenuPrincipal
{
public:
	MenuPrincipal();
	~MenuPrincipal();
	void SetDimensiones(float ancho, float largo);						//Establece las dimensiones de la ventana donde se vana dibujar el resto de opciones.
	void SetNumeroOpciones(unsigned int x);
	void DibujarMenu();
	void Seleccionar_Opcion(unsigned char key, int x, int y);
	void SetOpciones();
private:
	Opcion_Menu Options[NUMERO_MAX_OPCIONES];
	int NumeroOpciones;
	float Ancho, Largo;
};

