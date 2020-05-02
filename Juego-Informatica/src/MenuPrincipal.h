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
	bool AddOpcion(Opcion_Menu *Opcion);
	void DibujarMenu();
	void Seleccionar_Opcion(unsigned char key, int x, int y);
	void SetOpciones();
	void CreateMenu();
	bool DestroyMenu();
	void menu(int num);
private:
	int value = 1;
	static int submenu_id;
	Opcion_Menu *lista[NUMERO_MAX_OPCIONES];
	int NumeroOpciones;
	float Ancho, Largo;
};

