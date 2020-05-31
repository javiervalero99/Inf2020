#include "Artillero.h"

Artillero::Artillero()
{
	ifArtillero = true;

}

bool Artillero::ataca(Personaje& p)
{
	float acc = 8;

	if (DistanciaPlayer(p) < acc) {
		double time = GetTickCount();
		double cooldown = time - reload;
		if (cooldown > 4000) {
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
}

void Artillero::Dibuja()
{
	glPushMatrix();
	glTranslated(posicion.x, posicion.y, 0);
	glColor3ub(255, 0, 0);
	glutSolidCube(1.3f);
	glTranslated(-posicion.x, -posicion.y, 0);
	glPopMatrix();

	CajaMun.Dibuja();
}

CajaMunicion& Artillero::Getcaja()
{
	return CajaMun;
}
