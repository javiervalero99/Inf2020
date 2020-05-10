#include "Artillero.h"

void Artillero::ataca(Personaje& p)
{
	float acc;
	if (DistanciaPlayer(p) < 20) {

		 Mortero* m =new Mortero ;
		
		 if (m->velocidad.x = m->velo0) {
			 m->disparo(DistanciaPlayer(p));
//solo se ejecute una vez
		 }

		 //cuando se ejecute elcolldner con el suelo
		 m->detona(p);
		 delete m;
	}
}
