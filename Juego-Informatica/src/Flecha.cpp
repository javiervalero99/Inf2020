#include "Flecha.h"

Flecha::Flecha() : arrow("\Data_Game/Objects/flecha.png", 1, 1, 100), ImpactoFlecha(2, 0.5)//, ImpactoFlecha(0.1, 0.1)///revisar
{
	posicion.x = -100;
	posicion.y = -100;
	arrow.setSize(2, 2);
	arrow.setCenter(1.8, 1.1);
	validacionAsignacion = true;
	Dañoataque = -1;
}

Flecha::Flecha(float posx, float posy, bool direccion_derecha) : arrow("\Data_Game/Objects/flecha.png", 1, 1, 100), ImpactoFlecha(2, 0.5)
{
	posicion.x = -100;
	posicion.y = -100;
	arrow.setSize(2, 2);
	arrow.setCenter(1.8, 1.1);
	SetFlecha(posx, posy, direccion_derecha);
	validacionAsignacion = true;
	Dañoataque = -1;
}

Flecha::~Flecha()
{
}

void Flecha::SetFlecha(int posx, int posy, bool direccion_derecha)
{
	posicion.x = posx;
	posicion.y = posy;
	if (direccion_derecha == true)//indica que el personaje mira a la derecha
	{
		velocidad.x = 10;
		arrow.flip(false, false);
	}
	else if (direccion_derecha == false)//indica que el personaje mira a la izquierda
	{
		velocidad.x = -10;
		arrow.flip(true, false);

	}
}

void Flecha::Dibuja()
{
	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	//ImpactoFlecha.Dibuja();
	//ImpactoFlecha.Dibuja();
	arrow.draw();
	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();
}

void Flecha::Mueve(float t)
{
	posicion.x = posicion.x + velocidad.x * t;
	posicion.y = posicion.y + (0.5f * t * t) * (-7.5);//acelereacion negativa cte para caida
}