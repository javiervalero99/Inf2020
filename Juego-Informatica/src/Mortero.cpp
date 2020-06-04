#pragma once
#include "Mortero.h"

Mortero::Mortero(): collider(0.5, 0.5) , forma("\Data_Game/Enemigo_Mortero/disparo.png", 1, 1, 1000)
{

	forma.setSize(1 ,1 );
	forma.setCenter(1, 0);
	velo0 = 33;

	validacionAsignacion = 1;
	velocidad.x = velo0;
	velocidad.y = velo0;
	aceleracion.y = 9.8;
	disparo(posicion.x + 6);
	kabum = false;
	asignacionSalud = -2;
}

Mortero::Mortero(Vector2D a, float range):collider(0.5, 0.5) , forma("\Data_Game/Enemigo_Mortero/disparo.png", 1, 1, 1000) {
	forma.setSize(2, 2);
	forma.setCenter(1, 0);

	posicion = a;
	velo0 = 15;
	velocidad.x = velo0;
	velocidad.y = velo0;
	aceleracion.y = 9.8;
	disparo(posicion.x + range);

	validacionAsignacion = 1;
	kabum = false;
	asignacionSalud = -2;
}



Mortero::~Mortero()
{

}

void Mortero::Dibuja()
{
	if (velocidad.y > 0.01)
		forma.flip(false, false);

	if (velocidad.y < -0.01)
		forma.flip(false, true);

	glPushMatrix();
	glTranslated(posicion.x, posicion.y, 0);
	//glutSolidSphere(0.5, 30, 40);
	if(kabum ==false)
	forma.draw();
	glTranslated(-posicion.x, -posicion.y, 0);
	glPopMatrix();

}


bool Mortero::disparo(float x) //crea la parabola y dice si se ha disparado  // rango max 3
{
	angulo = (9.8 * (x - posicion.x)) / (velo0 * velo0);
	angulo = ((3.14 / 2) - (asin(angulo) / 2));
	velocidad.x = velo0 * cos(angulo);
	velocidad.y = velo0 * sin(angulo);
	return true;

	
}

void Mortero::Mueve(float t)
{
	
	posicion.x += velocidad.x * 0.025 + (1 / 2) * aceleracion.x * pow(0.025, 2);
	velocidad.x -= aceleracion.x * 0.025;
	//salto
	velocidad.y -= aceleracion.y * 0.025;
	posicion.y += velocidad.y * 0.025 - (1 / 2) * aceleracion.y * pow(0.025, 2);
}

bool Mortero::detona()
{


	return 0;
}

void Mortero::SetPos(Vector2D pos)
{
	posicion = pos;
}

Vector2D Mortero::GetPosicion()
{
	return posicion;
}

void Mortero::SetStatus()
{
	kabum = true;
}

bool Mortero::getStatus()
{
	return kabum;
}

// calculo para el artillero
/*
xmax = (Vo*Vo) *sen(2a)/g
h lim = (Vo*Vo) *sen(a)/g
se coge el angulo complementario para buscar parabolas altas, a altas velocidades. si es el angulo menor es como un cañonazo
*/