#include "Coco_Dandee.h"

Croco::Croco():move("\Data_Game/Enemigo_Maza/move.png", 6, 1, 40), Attack("\Data_Game/Enemigo_Maza/move.png", 4, 1, 400), Die("\Data_Game/Enemigo_Maza/die.png", 7, 1, 40)
{
	
	velocidad.x = 1;
	cae = false;
	move.setSize(2, 2);
	move.setCenter(1, 0.7);
	Die.setSize(2, 2);
	Die.setCenter(1, 1);
	Attack.setSize(10, 10);
	Attack.setCenter(1, 2.5);
	salud = 4;
	patrulla1 = posicion.x +3;
	patrulla2 = posicion.x - 3;



	estoy_atacando = false;
	me_muero = false;
	rayos_y_centellas = false;
	endgame = false;
	contador_nuerte = 0;
}

Croco::Croco(int x, int y, int p1, int p2) : move("\Data_Game/Enemigo_Maza/move.png", 6, 1, 40), Attack("\Data_Game/Enemigo_Maza/attack.png", 4, 1, 100), Die("\Data_Game/Enemigo_Maza/die.png", 7, 1, 40)
{
	posicion.x = x;
	posicion.y = y;
	velocidad.x = 1;
	cae = false;
	move.setSize(4, 4);
	move.setCenter(2, 1.2);
	Die.setSize(4, 4);
	Die.setCenter(1, 1.2);
	Attack.setSize(4, 4);
	Attack.setCenter(1, 1.2);
	salud = 4;
	patrulla1 =p1;
	patrulla2 = p2;

	estoy_atacando = false;
	me_muero = false;
	rayos_y_centellas = false;
	endgame = false;
	contador_nuerte = 0;
	asignacionSalud = -1;
	
}

void Croco::Dibuja()
{
	estado_muerte = Die.getState();
	if (estado_muerte == 6 && me_muero == true)
		endgame = true;

	estado_ataque = Attack.getState();
	if (estado_ataque == 1 ) {
		validacionAsignacion = true;

	}
	if (estado_ataque == 3) {
		validacionAsignacion = false;
		estoy_atacando = false;
		
	}



	glPushMatrix();
	glTranslated(posicion.x, posicion.y, 0);

	

	if ((estoy_atacando == true) && me_muero == false) {
		Attack.draw();
	}

	if (velocidad.x > 0.01)
	{
		move.flip(false, false);
		Attack.flip(false, false);
		Die.flip(false, false);
	
	;
	}
	else if (velocidad.x < -0.01)
	{
		move.flip(true, false);
		Attack.flip(true, false);
		Die.flip(true, false);
	
	}
	//ZONA SPRITES
	if ((velocidad.x != 0) && estoy_atacando == false && me_muero == false)//ESTA CORRIENDO
	{
		move.draw();

	}
	if (me_muero == true) {
		Die.draw();
		velocidad.x = 0;
	}
	glTranslated(-posicion.x, -posicion.y, 0);
	glPopMatrix();
}

void Croco::Mueve(float t)
{
	if (salud <= 0 && contador_nuerte == 0)
	{
		me_muero = true;
		Die.setState(0, false);
		contador_nuerte++;
		asignacionSalud = 0;

	}


	posicion.x += velocidad.x * 0.025 + (1 / 2) * aceleracion.x * pow(0.025, 2);
	velocidad.x -= aceleracion.x * 0.025;
	//salto
	velocidad.y -= aceleracion.y * 0.025;
	posicion.y += velocidad.y * 0.025 - (1 / 2) * aceleracion.y * pow(0.025, 2);

	if (cae == true) {
		aceleracion.y = 30;
		cae = false;
	}
	move.loop();
	
	Die.loop();
	Attack.loop();
}
void Croco::Persigue(Personaje& p)
{


	// si no hay nada en medio(las disntacias  otra cosa no es mayor ) lo persigue
	float acc = 6;
	double cd = GetTickCount();

	if (acc >= DistanciaPlayer(p))
	{
		if (contador == 0) {
			rayos_y_centellas = true;
			
			contador++;
		}

		if (DistanciaPlayer(p) < 0.8 &&cd - delay > 2500) {
			if (contador_a == 0 ) {
				estoy_atacando = true;
				Attack.setState(0, false);
				contador_a++;
				

			}

		}
		if (DistanciaPlayer(p) > 0.4)
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
		patrulla(patrulla1, patrulla2);
	}

}