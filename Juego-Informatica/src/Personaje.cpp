#include "Personaje.h"
#include <cmath>
#include <stdio.h>
#include "glut.h"

#define SPACEBAR 32

Personaje::Personaje(): Run("\Data_Game/Pers_Ppal/run.png", 4, 1, 100), Die("\Data_Game/Pers_Ppal/death.png", 10, 1, 70), Static("\Data_Game/Pers_Ppal/static.png", 2, 1, 250), Basic("\Data_Game/Pers_Ppal/estocada.png", 4, 1, 70), Jump("\Data_Game/Pers_Ppal/jump.png", 5, 1, 80), Distance("\Data_Game/Pers_Ppal/ataque_distancia.png", 5, 1, 70)

{
	posicion.x = 0;
	posicion.y = 0;
	valid_salto = true;
	cae = false;
	salud = 3;

	collider.setTam(1, 2.25);

	Run.setSize(2, 3);
	Run.setCenter(1, 1);
	Die.setSize(1.5, 1.5);
	Die.setCenter(0.75, 0);
	Static.setSize(2, 3);
	Static.setCenter(1, 1.1);
	Basic.setSize(1, 2);
	Basic.setCenter(0.5, 0);
	Jump.setSize(3, 3);
	Jump.setCenter(0.75, 0);
	Distance.setSize(1.5, 1.5);
	Distance.setCenter(0.75, 0.75);
	


}

void Personaje::SetTiempo(float t)
{
	tiempo = t;
}


Personaje::~Personaje()
{
}

void Personaje::Mueve(float t)
{
 //Ecuaciones de movimiento
	//printf("r=%d y velocidad=%f\n", r, velocidad.x);
	posicion.x += velocidad.x * 0.025 + (1 / 2) * aceleracion.x * pow(0.025, 2);
	velocidad.x -= aceleracion.x * 0.025;
	//salto
	velocidad.y -= aceleracion.y * 0.025;
	posicion.y += velocidad.y * 0.025 - (1 / 2) * aceleracion.y * pow(0.025, 2);



	if (velocidad.x > 10)
		velocidad.x = 10;
	if (velocidad.x < -10)
		velocidad.x = -10;

	//compensacion de la acerlacion
	if (abs(velocidad.x) < 2 && aceleracion.x != 0)
	{
		velocidad.x = 0;
		aceleracion.x = 0;
	}
	// 
	//gestiom maquina de estados 
	if (estados[0] == estados[1]) {
		if (velocidad.x < 0)
			aceleracion.x = -20;
		if (velocidad.x > 0)
			aceleracion.x = 12;

	}
	if (cae == true) {
		aceleracion.y = 15;
		cae = false;
	}
	if (estados[0] == 1 && estados[1] == 0)
		velocidad.x = 10;
	if (estados[0] == 0 && estados[1] == 1)
		velocidad.x = -10;

	Run.loop();
	Static.loop();
}

void Personaje::Dibuja()
{
	glPushMatrix();
	glTranslated(posicion.x, posicion.y, 0);
	
	//	collider.Dibuja();


	if (velocidad.x < -0.01)
	{
		Run.flip(false, false);
		Static.flip(false, false);
		Jump.flip(false, false);
	}
	else if (velocidad.x > 0.01)
	{
		Run.flip(true, false);
		Static.flip(true, false);
		Jump.flip(true, false);
	}

	//ZONA SPRITES
	if ((velocidad.x != 0))//ESTA CORRIENDO
	{
		if (velocidad.y == 0)
			Run.draw();
	}
	if ((velocidad.x == 0) && (velocidad.y == 0))//ESTA QUIETO
	{
		Static.draw();
	}
	if ((velocidad.y != 0))
	{
		Jump.draw();
	}
	glTranslated(-posicion.x, -posicion.y, 0);
	glPopMatrix();

}


Vector2D Personaje::GetPosicion() {
	Vector2D pos;
	pos.x = posicion.x;
	pos.y = posicion.y;

	return pos;

}



void Personaje::Ataque_Basico() {

}

void Personaje::Salto(unsigned char key) {

}

void Personaje::TeclaDown(unsigned char f) { //esta va con OnKeyboardDown
	if (posicion.y == 0)
	{
		valid_salto = true;

	}

	if ((f == ' ') && (valid_salto == true))
	{
		velocidad.y = 10.5;
		q = 1;
		valid_salto = false;
	}
	if (f == 'a'  || f == 'A')
		estados[0] = 1;

	if (f == 'd' || f == 'D') {


		estados[1] = 1;
	}

};


void Personaje::TeclaUp(unsigned char f) { //esta va con glutKeyboardUpFunc
	if (f == 'a' || f == 'A')
		estados[0] = 0;
	if (f == 'd' || f == 'D')
		estados[1] = 0;

}
int Personaje::GetSalud()
{
	
	
	return salud;
}
void Personaje::SetSalud(int n)
{
	salud = n;
}

void Personaje::daño(float t)
{

}



