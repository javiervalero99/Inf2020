#include "Personaje.h"
#include <math.h>
#include "glut.h"

#define SPACEBAR 32

Personaje::Personaje()
{
	posicion.x = 0;
	posicion.y = 0;
	valid_salto = true;
}

Personaje::~Personaje()
{
}

void Personaje::Mueve(float t)
{
	posicion.x += velocidad.x * t + (1 / 2) * aceleracion.x * pow(t, 2);
	velocidad.x += aceleracion.x * t;
	posicion.y += velocidad.y * t + (1 / 2) * aceleracion.y * pow(t, 2);
	velocidad.y += aceleracion.y * t;
}

void Personaje::Dibuja()
{
	glPushMatrix();
	glTranslated(posicion.x, posicion.y, 0);
	glutSolidCube(1.3f);
	glTranslated(-posicion.x, -posicion.y, 0);
	glPopMatrix();
}

void Personaje::Ataque_Basico(){

}

void Personaje::Salto(unsigned char key){
	if ((posicion.y == 0) || (i == 1))
		i = 0;

	if((key==' ')&&(i==0)){
		i = 1;
		velocidad.y = 20;
	}
}

void Personaje::TeclaDown(unsigned char f) { //esta va con OnKeyboardDown
	if(f == 'a'){
		velocidad.x = 0.1;
	}
		if(f == 'd'){
		velocidad.x = -0.1;
	}
		if(f == SPACEBAR)
		{
			Ataque_Basico();
		}
};


void Personaje::TeclaUp(unsigned char f) { //esta va con glutKeyboardUpFunc
	if( f == 'a' || f == 'd'){
		velocidad.x = 0;
	}


};

/*
if( f == 'a' || f == 'd')
{
if(f == 'a')
    {
		velocidad.x = 0.1;
	}
if(f == 'd')
    {
		velocidad.x = -0.1;
	}
}
else
velocidad.x=0.0;
*/