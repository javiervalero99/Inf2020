#include "Bonus.h"

Bonus::Bonus(): Pocion("\Data_Game/Objects/Pocion.png", 1,1, 100), ObjetoGeneral(-15.0f, 8+1.3/2, 0.0f, 0.0f, 1.0f, 1.0f, 1)
{
	validacionAsignacion = true;
	asignacionSalud = 4;
	Pocion.setSize(1, 1);
	Pocion.setCenter(0.5, 1);
	impacto_personaje = false;
	personaje_curado = false;
	endgame = 0;
	salud = 1;
}

Bonus::Bonus(float posx,float posy): Pocion("\Data_Game/Objects/Pocion.png", 1, 1, 100), ObjetoGeneral(-15.0f, 8 + 1.3 / 2, 0.0f, 0.0f, 1.0f, 1.0f, 1)
{
	validacionAsignacion = true;
	asignacionSalud = 4;
	posicion.x = posx;
	posicion.y = posy;
	velocidad.y = -5.0f;
	personaje_curado = false;
	impacto_personaje = false;
	endgame = 0;
	salud = 1;
	Pocion.setSize(1, 1);
	Pocion.setCenter(0.5, 0.5);
}

Bonus::~Bonus()
{
}

void Bonus::Dibuja()
{
	if (personaje_curado == false) {
		glPushMatrix();
		glTranslatef(posicion.x, posicion.y, 0.0f);
		Pocion.draw();
		glTranslatef(-posicion.x, -posicion.y, 0.0f);
		glPopMatrix();
	}
}

void Bonus::Mueve(float t)
{
	if (validacionAsignacion == false) {
		personaje_curado = true;
}
	else{
		validacionAsignacion = true;
		posicion.y += velocidad.y * 0.025 - (1 / 2) * aceleracion.y * pow(0.025, 2);
	}
	Pocion.loop();
}

void Bonus::Persigue(Personaje& p)
{
}


