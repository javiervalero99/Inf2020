#include "Patrullero.h"
#pragma once


Patrullero::Patrullero() : Run("\Data_Game/Enem_Pat/Pat_jump.png", 7, 1, 40), Die("\Data_Game/Enem_Pat/Pat_die.png", 10, 2, 100), Attack("\Data_Game/Enem_Pat/Pat_attack.png", 7, 1, 80), Surprise("\Data_Game/Enem_Pat/Pat_surprise.png", 5, 1, 150)
{
	posicion.x = -20;
	posicion.y = 8 + 1.3 / 2;
	velocidad.x = 1;
	cae = false;
	Run.setSize(2, 2);
	Run.setCenter(1, 0.7);
	Die.setSize(2, 2);
	Die.setCenter(1, 0);
	Attack.setSize(2, 2);
	Attack.setCenter(1, 0);
	Surprise.setSize(2, 2);
	Surprise.setCenter(1, 1);

	estoy_atacando = false;
	me_muero = false;
	rayos_y_centellas = false;


}

void Patrullero::patrulla(float x1, float x2)
{
	if (fabs(posicion.x) <= x1)
		velocidad.x = -3;
	if (fabs(posicion.x) >= x2)
		velocidad.x = 3;
}
void Patrullero::Persigue(Personaje& p)
{
	
	// si no hay nada en medio(las disntacias  otra cosa no es mayor ) lo persigue
	float acc = 5;


	if (acc >= DistanciaPlayer(p))
	{
		if (contador == 0) {
			rayos_y_centellas = true;
			Surprise.setState(0, false);
			contador++;
		}
		
		if ( DistanciaPlayer(p) < 0.6) {
			if (contador_a == 0) {
				estoy_atacando = true;
				Attack.setState(0, false);
				contador_a++;
			}
			
		}
		if (DistanciaPlayer(p) >0.6)
			contador_a = 0;
			


		float mov = p.posicion.x - posicion.x;
		if (mov < 0)
		{
			velocidad.x = -2;
		}
		else
			velocidad.x = 2;


	}
	else {//enemigo en modo default; puede implantarse lo que sea
		contador = 0;
		patrulla(19, 22);
	}

}

void Patrullero::Dibuja()
{
	estado_ay_caramba = Surprise.getState();
	if (estado_ay_caramba == 4) {
		rayos_y_centellas = false;
		
	}
	estado_ataque = Attack.getState();
	if (estado_ataque == 3 ) {
		validacionAsignacion = true;

	}
	if (estado_ataque == 6) {
		validacionAsignacion = false;
		estoy_atacando = false;

	}



	glPushMatrix();
	glTranslated(posicion.x, posicion.y, 0);

	if (rayos_y_centellas == true && estoy_atacando == false) {
		Surprise.draw();
	}

	if ((estoy_atacando == true) &&(rayos_y_centellas == false)) {
		Attack.draw();
	}

	if (velocidad.x > 0.01)
	{
		Run.flip(false, false);
		Attack.flip(false, false);
		Die.flip(false, false);
		Surprise.flip(false, false);
	}
	else if (velocidad.x < -0.01)
	{
		Run.flip(true, false);
		Attack.flip(true, false);
		Die.flip(true, false);
		Surprise.flip(true, false);
	}
	//ZONA SPRITES
	if ((velocidad.x != 0) && rayos_y_centellas == false && estoy_atacando ==false)//ESTA CORRIENDO
	{
		Run.draw();

	}

	glTranslated(-posicion.x, -posicion.y, 0);
	glPopMatrix();
}

void Patrullero::Mueve(float t)
{

	posicion.x += velocidad.x * 0.025 + (1 / 2) * aceleracion.x * pow(0.025, 2);
	velocidad.x -= aceleracion.x * 0.025;
	//salto
	velocidad.y -= aceleracion.y * 0.025;
	posicion.y += velocidad.y * 0.025 - (1 / 2) * aceleracion.y * pow(0.025, 2);

	if (cae == true) {
		aceleracion.y = 30;
		cae = false;
	}
	Run.loop();
	Surprise.loop();
	Die.loop();
	Attack.loop();

}

bool Patrullero::ataca(Personaje& p)
{
	return 0;
}
