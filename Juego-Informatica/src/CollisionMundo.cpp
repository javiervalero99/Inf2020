#include "CollisionMundo.h"
#include <stdio.h>
bool CollisionMundo::Collision(Personaje& per, ColliderMap pared)
{
	//printf("velx=%f y vely=%f\n", per.velocidad.x, per.velocidad.y);
	//printf("%d\n", per.valid_salto);
	float tamy = per.collider.tam.y / 2;
	float tamx = per.collider.tam.x / 2;
	bool In_collider = (per.GetPosicion().x - tamx <= pared.Arriba.x) && (per.GetPosicion().x + tamx >= pared.Abajo.x);//Estas en las X
	bool Under_collider = (per.GetPosicion().y + tamy <= pared.Arriba.y) && (per.GetPosicion().y - tamy <= pared.Abajo.y);// || (per.GetPosicion().y + tamy <= pared.Arriba.y) && (per.GetPosicion().y - tamy >= pared.Abajo.y);
	bool Up_collider = (per.GetPosicion().y - tamy - 0.01 <= pared.Arriba.y) && (per.GetPosicion().y - tamy - 0.01 >= pared.Abajo.y) && (per.GetPosicion().y + tamy >= pared.Arriba.y);
	bool FrontLateral_collider = (per.GetPosicion().x - tamx <= pared.Arriba.x) && (per.GetPosicion().x - tamx >= pared.Abajo.x) && (per.GetPosicion().y <= pared.Arriba.y) && (per.velocidad.x < 0);//choque frontal
	bool BackLateral_collider = (per.GetPosicion().x + tamx >= pared.Abajo.x) && (per.GetPosicion().x + tamx <= pared.Arriba.x) && (per.GetPosicion().y <= pared.Arriba.y) && (per.velocidad.x > 0);//choque trasero
	bool Collision_under_Collider = ((per.GetPosicion().y + tamy + 0.01 <= pared.Arriba.y) && (per.GetPosicion().y + tamy + 0.01 >= pared.Abajo.y) && (per.GetPosicion().y - tamy <= pared.Abajo.y));
	/*if (((Under_collider==false)&&((FrontLateral_collider == true)||(BackLateral_collider==true)))||((Under_collider == true)&& (per.GetPosicion().y + 0.65 <= pared.Arriba.y) && (per.GetPosicion().y - 0.65 >= pared.Abajo.y)&& ((FrontLateral_collider == true) || (BackLateral_collider == true)))){
		per.velocidad.x = 0;
		per.aceleracion.x = 0;
		if (FrontLateral_collider == true)
			per.posicion.x = pared.Arriba.x+0.65;
		if ((BackLateral_collider == true)) {
			per.posicion.x = pared.Abajo.x-0.65;
		}
		//bool BackLateral_collider = (per.GetPosicion().x + tamx >= pared.Abajo.x) && (per.GetPosicion().x + tamx <= pared.Arriba.x) && (per.GetPosicion().y <= pared.Arriba.y) && (per.velocidad.x > 0);//choque trasero

	}*/
	if ((Under_collider == false) && ((FrontLateral_collider == true) || (BackLateral_collider == true))) {
		per.velocidad.x = 0;
		per.aceleracion.x = 0;
		if (FrontLateral_collider == true)
			per.posicion.x = pared.Arriba.x + tamx;
		if ((BackLateral_collider == true)) {
			per.posicion.x = pared.Abajo.x - tamx;
		}
		//bool BackLateral_collider = (per.GetPosicion().x + tamx >= pared.Abajo.x) && (per.GetPosicion().x + tamx <= pared.Arriba.x) && (per.GetPosicion().y <= pared.Arriba.y) && (per.velocidad.x > 0);//choque trasero

	}
	if ((Collision_under_Collider == true) && (In_collider == true)) {
		per.velocidad.y = 0;
		per.posicion.y = pared.Abajo.y - tamy - 0.01;
	}
	if ((In_collider == true) && (Under_collider == false)) {


		//printf("Aire=%d, Suelo=%d\n", In_air,Up_collider);
		if ((Up_collider == true) && (per.velocidad.y < 0)) {
			//per.posicion.y = pared.Arriba.y + 0.64;
			per.velocidad.y = 0;
			per.aceleracion.y = 0;
			per.posicion.y = pared.Arriba.y + tamy;
			per.q = 0;
			per.valid_salto = true;
			per.j = 0;
		}

	}
	return Up_collider && In_collider;
}


bool CollisionMundo::Collision(ObjetoGeneral& per, ColliderMap pared)
{
	//printf("velx=%f y vely=%f\n", per.velocidad.x, per.velocidad.y);
//printf("%d\n", per.valid_salto);
	float tamy = per.Collider.tam.y / 2;
	float tamx = per.Collider.tam.x / 2;
	bool In_collider = (per.GetPosicion().x - tamx <= pared.Arriba.x) && (per.GetPosicion().x + tamx >= pared.Abajo.x);//Estas en las X
	bool Under_collider = (per.GetPosicion().y + tamy <= pared.Arriba.y) && (per.GetPosicion().y - tamy <= pared.Abajo.y);// || (per.GetPosicion().y + tamy <= pared.Arriba.y) && (per.GetPosicion().y - tamy >= pared.Abajo.y);
	bool Up_collider = (per.GetPosicion().y - tamy - 0.01 <= pared.Arriba.y) && (per.GetPosicion().y - tamy - 0.01 >= pared.Abajo.y) && (per.GetPosicion().y + tamy >= pared.Arriba.y);
	bool FrontLateral_collider = (per.GetPosicion().x - tamx <= pared.Arriba.x) && (per.GetPosicion().x - tamx >= pared.Abajo.x) && (per.GetPosicion().y <= pared.Arriba.y) && (per.velocidad.x < 0);//choque frontal
	bool BackLateral_collider = (per.GetPosicion().x + tamx >= pared.Abajo.x) && (per.GetPosicion().x + tamx <= pared.Arriba.x) && (per.GetPosicion().y <= pared.Arriba.y) && (per.velocidad.x > 0);//choque trasero
	bool Collision_under_Collider = ((per.GetPosicion().y + tamy + 0.01 <= pared.Arriba.y) && (per.GetPosicion().y + tamy + 0.01 >= pared.Abajo.y) && (per.GetPosicion().y - tamy <= pared.Abajo.y));

	if ((Under_collider == false) && ((FrontLateral_collider == true) || (BackLateral_collider == true))) {
		per.velocidad.x = 0;
		per.aceleracion.x = 0;
		if (FrontLateral_collider == true)
			per.posicion.x = pared.Arriba.x + tamx;
		if ((BackLateral_collider == true)) {
			per.posicion.x = pared.Abajo.x - tamx;
		}
		//bool BackLateral_collider = (per.GetPosicion().x + tamx >= pared.Abajo.x) && (per.GetPosicion().x + tamx <= pared.Arriba.x) && (per.GetPosicion().y <= pared.Arriba.y) && (per.velocidad.x > 0);//choque trasero

	}
	if ((Collision_under_Collider == true) && (In_collider == true)) {
		per.velocidad.y = 0;
		per.posicion.y = pared.Abajo.y - tamy - 0.01;
	}
	if ((In_collider == true) && (Under_collider == false)) {


		//printf("Aire=%d, Suelo=%d\n", In_air,Up_collider);
		if ((Up_collider == true) && (per.velocidad.y < 0)) {
			//per.posicion.y = pared.Arriba.y + 0.64;
			per.velocidad.y = 0;
			per.aceleracion.y = 0;
			per.posicion.y = pared.Arriba.y + tamy;
			per.q = 0;
			per.j = 0;
		}

	}
	return Up_collider && In_collider;
}