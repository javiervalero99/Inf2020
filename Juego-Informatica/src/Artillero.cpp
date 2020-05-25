#include "Artillero.h"

void Artillero::ataca(Personaje& p)
{
	float acc;
	if (DistanciaPlayer(p) < 3) {

		 Mortero* m =new Mortero ;
		//de fde mortero
		 m->Dibuja();
		 m->Mueve(0.025);
		 m->SetPos(posicion);

		 if (m->velocidad.x = m->velo0) {
			 m->disparo(4); // DistanciaPlayer(p)
//solo se ejecute una vez
		 }

		 //cuando se ejecute elcolldner con el suelo
		 m->detona(p);
		 delete m;
	}
}
