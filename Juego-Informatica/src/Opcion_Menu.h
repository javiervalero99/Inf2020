#pragma once
#include "Vector2D.h"
#include "glut.h"

class Opcion_Menu
{
public:
	Opcion_Menu();
	~Opcion_Menu();
	void Dibujar();
	void SetID(int ID);
	void SetColor(int rojo, int verde, int azul);
	void SetEsquinas(float coord_x, float coord_y);		//Esta función establece la esquina principal de un recuadro, que es la superior izquierda.
	void SetDimensiones(float l, float a);				//Establecer largo y alto del recuadro.
														
private:
	int Identificador;
	unsigned int red, green, blue;		//Color de la opcion.
	float largo, alto;
	Vector2D EsquinasRecuadro;		//Esquinas del recuadro.
};

