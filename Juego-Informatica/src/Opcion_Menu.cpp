#include "Opcion_Menu.h"
#include "src\Opcion_Menu.h"

Opcion_Menu::Opcion_Menu()
{

}

Opcion_Menu::~Opcion_Menu()
{
}

void Opcion_Menu::Dibujar()
{
	glPushMatrix();
	for (int i = 0; i < 4; i++)
	{
		glTranslatef(EsquinasRecuadro.x, EsquinasRecuadro.y, 0.0f);
		glBegin(GL_QUAD_STRIP);

		glVertex3f(-largo, -alto, 0.0f);
		glVertex3f(largo, -alto, 0.0f);
		glVertex3f(-largo, alto, 0.0f);
		glVertex3f(largo, alto, 0.0f);

		glEnd();
	}
	glPopMatrix();
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
	EsquinasRecuadro.x = coord_x;
	EsquinasRecuadro.y = coord_y;
}

void Opcion_Menu::SetDimensiones(float l, float a)
{
	largo = l;
	alto = a;
}
