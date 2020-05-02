#include "Opcion_Menu.h"

Opcion_Menu::Opcion_Menu(Vector2D arr,Vector2D ab):Arriba(arr),Abajo(ab){
	red = green = blue = 255;
		Identificador = 0;
}

Opcion_Menu::~Opcion_Menu()
{
}

void Opcion_Menu::Dibujar()
{
	glPushMatrix();
	float z = -0.5f;
	
	glColor3ub(red, green, blue);
	glBegin(GL_POLYGON);
	glVertex3f(Arriba.x, Arriba.y, z);
	glVertex3f(Arriba.x, Abajo.y, z);
	glVertex3f(Abajo.x, Abajo.y, z);
	glVertex3f(Abajo.x, Arriba.y, z);
	glEnd();
	glFlush();
}

void Opcion_Menu::SetID(int ID)
{
	Identificador = ID;
}

void Opcion_Menu::SetColor(int rojo, int verde, int azul)
{
	red = rojo;
	green = verde;
	blue = azul;
}

void Opcion_Menu::SetEsquinas(float coord_x, float coord_y)
{
}

void Opcion_Menu::SetDimensiones(float l, float a)
{
	largo = l;
	alto = a;
}
