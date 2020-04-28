#include "CollisionMundo.h"
#include <stdio.h>
bool CollisionMundo::Collision(Personaje& per, ColliderMap pared)
{
	//printf("velx=%f y vely=%f\n", per.velocidad.x, per.velocidad.y);
	//printf("%d\n", per.valid_salto);
	bool In_collider = (per.GetPosicion().x-0.65 <= pared.Arriba.x) && (per.GetPosicion().x+0.65 >= pared.Abajo.x);
	bool Under_collider= (per.GetPosicion().y + 0.65 <= pared.Arriba.y) && (per.GetPosicion().y - 0.65 <= pared.Abajo.y)|| (per.GetPosicion().y + 0.65 <= pared.Arriba.y) && (per.GetPosicion().y -0.65 >= pared.Abajo.y);
	bool FrontLateral_collider = (per.GetPosicion().x - 0.65 <= pared.Arriba.x)&& (per.GetPosicion().x - 0.65 >= pared.Abajo.x) && (per.GetPosicion().y <= pared.Arriba.y) && (per.velocidad.x < 0);//choque frontal
	bool BackLateral_collider = (per.GetPosicion().x + 0.65 >= pared.Abajo.x)&&(per.GetPosicion().x + 0.65 <= pared.Arriba.x) && (per.GetPosicion().y <= pared.Arriba.y) && (per.velocidad.x > 0);//choque trasero
	// PlatformFrontalLateral_collider=(per.GetPosicion().x - 0.65 <= pared.Arriba.x)&& ((per.GetPosicion().y+0.65 >= pared.Arriba.y)&& (per.GetPosicion().y -0.65 <= pared.Arriba.y)&& (per.GetPosicion().y - 0.65 <= pared.Abajo.y) || (per.GetPosicion().y + 0.65 <= pared.Arriba.y)&& (per.GetPosicion().y - 0.65 <= pared.Abajo.y)) &&(per.velocidad.x < 0);
	if (((Under_collider==false)&&((FrontLateral_collider == true)||(BackLateral_collider==true)))||((Under_collider == true)&& (per.GetPosicion().y + 0.65 <= pared.Arriba.y) && (per.GetPosicion().y - 0.65 >= pared.Abajo.y)&& ((FrontLateral_collider == true) || (BackLateral_collider == true)))){//||(PlatformFrontalLateral_collider==true))) {
		per.velocidad.x = 0;
		per.aceleracion.x = 0;
		if (FrontLateral_collider == true)
			per.posicion.x = pared.Arriba.x+0.65;
		if ((BackLateral_collider == true)) {
			per.posicion.x = pared.Abajo.x-0.65;
		}
		return true;
	}
	if((In_collider==true)&&(Under_collider==false)){
	bool Up_collider = (per.GetPosicion().y - 0.66 <= pared.Arriba.y)&& (per.GetPosicion().y - 0.66 >= pared.Abajo.y);
	bool In_air =  (Up_collider==false);

	//printf("Aire=%d, Suelo=%d\n", In_air,Up_collider);
	if ((Up_collider == true)&&(per.velocidad.y<0)) {
		//per.posicion.y = pared.Arriba.y + 0.64;
		per.velocidad.y = 0;
		per.aceleracion.y = 0;
		per.posicion.y = pared.Arriba.y + 0.65;
		per.q = 0;
		per.valid_salto = true;
		per.j = 0;
	}
	if ((Up_collider == false) && (In_air == true) && (per.valid_salto == true)&&(per.j==0)) {
		//Border = (per.GetPosicion().x + 0.5 > pared.Abajo.x) && (per.GetPosicion().x - 0.5 > pared.Abajo.x);
		per.cae = true;
		per.j++;
	}


	return true;
}
	return false;
}

bool CollisionMundo::Collision(Personaje& per, ColliderMap pared, ColliderMap paredEncima)
{
	//printf("velx=%f y vely=%f\n", per.velocidad.x, per.velocidad.y);
	//printf("%d\n", per.valid_salto);
	bool In_collider = (per.GetPosicion().x+0 <= pared.Arriba.x) && (per.GetPosicion().x+0.5 >= pared.Abajo.x);
	bool Under_collider = (per.GetPosicion().y + 0.65 <= pared.Arriba.y) && (per.GetPosicion().y + 0.65 <= pared.Abajo.y);
	bool Under_colliderEncima = (per.GetPosicion().x <= paredEncima.Arriba.x) && (per.GetPosicion().x >= paredEncima.Abajo.x);
	bool Above_colliderEncima =  Under_colliderEncima && (per.GetPosicion().y >= paredEncima.Arriba.y);
	bool FrontLateral_collider = (per.GetPosicion().x - 0.65 <= pared.Arriba.x) && (per.GetPosicion().x - 0.65 >= pared.Abajo.x) && (per.GetPosicion().y <= pared.Arriba.y) && (per.velocidad.x < 0);//choque frontal
	bool BackLateral_collider = (per.GetPosicion().x + 0.65 >= pared.Abajo.x) && (per.GetPosicion().x + 0.65 <= pared.Arriba.x) && (per.GetPosicion().y <= pared.Arriba.y) && (per.velocidad.x > 0);//choque trasero
	// PlatformFrontalLateral_collider=(per.GetPosicion().x - 0.65 <= pared.Arriba.x)&& ((per.GetPosicion().y+0.65 >= pared.Arriba.y)&& (per.GetPosicion().y -0.65 <= pared.Arriba.y)&& (per.GetPosicion().y - 0.65 <= pared.Abajo.y) || (per.GetPosicion().y + 0.65 <= pared.Arriba.y)&& (per.GetPosicion().y - 0.65 <= pared.Abajo.y)) &&(per.velocidad.x < 0);
	if (((Under_collider == false) && ((FrontLateral_collider == true) || (BackLateral_collider == true))) || ((Under_collider == true) && (per.GetPosicion().y + 0.65 <= pared.Arriba.y) && (per.GetPosicion().y - 0.65 >= pared.Abajo.y) && ((FrontLateral_collider == true) || (BackLateral_collider == true)))) {//||(PlatformFrontalLateral_collider==true))) {
		per.velocidad.x = 0;
		per.aceleracion.x = 0;
		if (FrontLateral_collider == true)
			per.posicion.x = pared.Arriba.x + 0.65;
		if ((BackLateral_collider == true)) {
			per.posicion.x = pared.Abajo.x - 0.65;
		}
		return true;
	}
	if ((In_collider == true) && (Under_collider == false)&&(Above_colliderEncima==false)) {
		bool Up_collider = (per.GetPosicion().y - 0.66<= pared.Arriba.y) && (per.GetPosicion().y - 0.66 >= pared.Abajo.y);
		bool In_air = (Up_collider == false);
		//bool Border = (per.GetPosicion().x + 0.5 > pared.Abajo.x) && (per.GetPosicion().x - 0.5 < pared.Abajo.x);
		//printf("Aire=%d, Suelo=%d\n", In_air,Up_collider);
		if ((Up_collider == true) && (per.velocidad.y < 0)) {
			//per.posicion.y = pared.Arriba.y + 0.64;
			per.velocidad.y = 0;
			per.aceleracion.y = 0;
			per.posicion.y = pared.Arriba.y + 0.65;
			per.q = 0;
			per.valid_salto = true;
			per.j = 0;
		}
		if ((Up_collider == false) && (In_air == true) && (per.valid_salto == true)&&(per.j==0)) {
			//Border = (per.GetPosicion().x + 0.5 > pared.Abajo.x) && (per.GetPosicion().x - 0.5 > pared.Abajo.x);
			per.cae = true;
			per.j++;
		}
		bool choqueArriba = Under_colliderEncima && (per.velocidad.y > 0) && (per.valid_salto == false) && (per.GetPosicion().y + 0.65 >= paredEncima.Abajo.y);
		if (choqueArriba) {
			per.velocidad.y = 0;
		}
		bool Latera_collider = (per.GetPosicion().x - 0.65 <= pared.Arriba.x) && (per.GetPosicion().y <= pared.Arriba.y) && (per.velocidad.x < 0);
		if (Latera_collider == true) {

			per.velocidad.x = 0;
			per.aceleracion.x = 0;
			return true;
		}

	
	}
	if (In_collider == true) {
		return true;
	}
	return false;
}

bool CollisionMundo::Collision(Enemigo& per, ColliderMap pared)
{
	//printf("velx=%f y vely=%f\n", per.velocidad.x, per.velocidad.y);
	//printf("%d\n", per.valid_salto);
	bool In_collider = (per.GetPosicion().x - 0.65 <= pared.Arriba.x) && (per.GetPosicion().x + 0.65 >= pared.Abajo.x);
	bool Under_collider = (per.GetPosicion().y + 0.65 <= pared.Arriba.y) && (per.GetPosicion().y - 0.65 <= pared.Abajo.y) || (per.GetPosicion().y + 0.65 <= pared.Arriba.y) && (per.GetPosicion().y - 0.65 >= pared.Abajo.y);
	bool FrontLateral_collider = (per.GetPosicion().x - 0.65 <= pared.Arriba.x) && (per.GetPosicion().x - 0.65 >= pared.Abajo.x) && (per.GetPosicion().y <= pared.Arriba.y) && (per.velocidad.x < 0);//choque frontal
	bool BackLateral_collider = (per.GetPosicion().x + 0.65 >= pared.Abajo.x) && (per.GetPosicion().x + 0.65 <= pared.Arriba.x) && (per.GetPosicion().y <= pared.Arriba.y) && (per.velocidad.x > 0);//choque trasero
	// PlatformFrontalLateral_collider=(per.GetPosicion().x - 0.65 <= pared.Arriba.x)&& ((per.GetPosicion().y+0.65 >= pared.Arriba.y)&& (per.GetPosicion().y -0.65 <= pared.Arriba.y)&& (per.GetPosicion().y - 0.65 <= pared.Abajo.y) || (per.GetPosicion().y + 0.65 <= pared.Arriba.y)&& (per.GetPosicion().y - 0.65 <= pared.Abajo.y)) &&(per.velocidad.x < 0);
	if (((Under_collider == false) && ((FrontLateral_collider == true) || (BackLateral_collider == true))) || ((Under_collider == true) && (per.GetPosicion().y + 0.65 <= pared.Arriba.y) && (per.GetPosicion().y - 0.65 >= pared.Abajo.y) && ((FrontLateral_collider == true) || (BackLateral_collider == true)))) {//||(PlatformFrontalLateral_collider==true))) {
		per.velocidad.x = 0;
		per.aceleracion.x = 0;
		if (FrontLateral_collider == true)
			per.posicion.x = pared.Arriba.x + 0.65;
		if ((BackLateral_collider == true)) {
			per.posicion.x = pared.Abajo.x - 0.65;
		}
		return true;
	}
	if ((In_collider == true) && (Under_collider == false)) {
		bool Up_collider = (per.GetPosicion().y - 0.66 <= pared.Arriba.y) && (per.GetPosicion().y - 0.66 >= pared.Abajo.y);
		bool In_air = (Up_collider == false);

		//printf("Aire=%d, Suelo=%d\n", In_air,Up_collider);
		if ((Up_collider == true) && (per.velocidad.y < 0)) {
			//per.posicion.y = pared.Arriba.y + 0.64;
			per.velocidad.y = 0;
			per.aceleracion.y = 0;
			per.posicion.y = pared.Arriba.y + 0.65;
			per.q = 0;
		
			per.j = 0;
		}
		if ((Up_collider == false) && (In_air == true)  && (per.j == 0)) {
			//Border = (per.GetPosicion().x + 0.5 > pared.Abajo.x) && (per.GetPosicion().x - 0.5 > pared.Abajo.x);
			per.cae = true;
			per.j++;
		}


		return true;
	}
	return false;
}