#include "Artillero.h"


Artillero::Artillero() : atack("\Data_Game/Enemigo_Mortero/shot.png",3,1, 100), die("\Data_Game/Enemigo_Mortero/death.png", 10, 1, 100), statico("\Data_Game/Enemigo_Mortero/static.png", 2, 1, 250)
{

	ifArtillero = true;
	atack.setSize(2, 2);
	atack.setCenter(1, 0);
	die.setSize(2, 2);
	die.setCenter(1, 0);
	statico.setSize(2, 2);
	statico.setCenter(1, 0);
	estoy_disp = false;

}

bool Artillero::ataca(Personaje& p)
{
	float acc = 8;

	if (DistanciaPlayer(p) < acc) {
		double time = GetTickCount();
		double cooldown = time - reload;
		if( time- reload > 500)
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

void Artillero::Mueve(float t)
{
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
	if (estoy_disp == false)
		statico.draw();
	if (estoy_disp == true)
		atack.draw();



	glTranslated(-posicion.x, -posicion.y, 0);


	glPopMatrix();

	CajaMun.Dibuja();
}

CajaMunicion& Artillero::Getcaja()
{
	return CajaMun;
}
