#include "Artillero.h"


Artillero::Artillero() : atack("\Data_Game/Enemigo_Mortero/shot.png", 3, 1, 100), die("\Data_Game/Enemigo_Mortero/death.png", 10, 1, 100), statico("\Data_Game/Enemigo_Mortero/static.png", 2, 1, 250)
{
	Collider.setTam(1, 1);

	ifArtillero = true;
	atack.setSize(2, 2);
	atack.setCenter(1, 1.4);
	die.setSize(2, 2);
	die.setCenter(1, 1.4);
	statico.setSize(2, 2);
	statico.setCenter(1, 1.4);
	estoy_disp = false;
	endgame = 0;
	contador_muerte = 0;
	me_muero = false;
	salud = 1;

}

Artillero::Artillero(int x, int y) : atack("\Data_Game/Enemigo_Mortero/shot.png", 3, 1, 100), die("\Data_Game/Enemigo_Mortero/death.png", 10, 1, 100), statico("\Data_Game/Enemigo_Mortero/static.png", 2, 1, 250)
{
	Collider.setTam(1, 1);
	posicion.x = x;
	posicion.y = y;
	ifArtillero = true;
	atack.setSize(2, 2);
	atack.setCenter(1, 1.2);
	die.setSize(2, 2);
	die.setCenter(1, 1.2);
	statico.setSize(2, 2);
	statico.setCenter(1, 1.2);
	estoy_disp = false;
	endgame = 0;
	contador_muerte = 0;
	me_muero = false;
	salud = 1;
}

bool Artillero::ataca(Personaje& p)
{
	if (me_muero == false) {
		float acc = 60;

		if (DistanciaPlayer(p) < acc) {
			double time = GetTickCount();
			double cooldown = time - reload;
			if (time - reload > 500)
				estoy_disp = false;

			if (cooldown > 4000) {
				atack.setState(0, false);
				estoy_disp = true;

				CajaMun.agregar(GetPosicion(), DistanciaPlayer(p));
				reload = GetTickCount();

			}
			return true;
		}
		else
			return false;


	}
}

void Artillero::Mueve(float t)
{
	estado_muerte = die.getState();
	if (estado_muerte == 9 && me_muero == true)
		endgame = true;

	if (salud <= 0 && contador_muerte == 0)
	{
		me_muero = true;
		die.setState(0, false);
		contador_muerte++;
		asignacionSalud = 0;

	}

	CajaMun.Mueve(t);
	CajaMun.destruirContenido();

	statico.loop();
	atack.loop();
	die.loop();
}

void Artillero::Dibuja()
{

	estado_atq = atack.getState();
	if (estado_atq == 9)
		estoy_disp = false;
	glPushMatrix();
	glTranslated(posicion.x, posicion.y, 0);
	//glColor3ub(255, 0, 0);
	//glutSolidCube(1.3f);
	//Collider.Dibuja();
	if (estoy_disp == false && me_muero == false)
		statico.draw();
	if (estoy_disp == true && me_muero == false)
		atack.draw();

	if (me_muero == true) {
		die.draw();
		velocidad.x = 0;
	}

	glTranslated(-posicion.x, -posicion.y, 0);


	glPopMatrix();

	CajaMun.Dibuja();
}

CajaMunicion& Artillero::Getcaja()
{
	return CajaMun;
}