#include "CollisionMundo.h"
#include <stdio.h>
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
		per.posicion.y = pared.Abajo.y - tamy;
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

bool CollisionMundo::Collision(ObjetoGeneral& obj, Personaje& per)
{
	float tamxPer = per.collider.tam.x / 2;
	float tamxObj = obj.Collider.tam.x / 2;
	float tamyPer = per.collider.tam.y / 2;
	float tamyObj = obj.Collider.tam.y / 2;
	float partDelantePersonaje = per.GetPosicion().x + tamxPer;
	float partTraseraPersonaje = per.GetPosicion().x - tamxPer;
	float partArribaPersonaje = per.GetPosicion().y + tamyPer;
	float partAbajoPersonaje = per.GetPosicion().y - tamyPer;
	float partDelanteObj = obj.GetPosicion().x + tamxObj;
	float partTraseraObj = obj.GetPosicion().x - tamxObj;
	float partArribaObj = obj.GetPosicion().y + tamyObj;
	float partAbajoObj = obj.GetPosicion().y - tamyObj;


	bool CollisionX = ((partDelantePersonaje + 0.01 >= partTraseraObj) && (partTraseraPersonaje + 0.01 <= partDelanteObj));
	bool CollisionY = ((partArribaPersonaje + 0.01 >= partAbajoObj) && (partAbajoPersonaje + 0.01 <= partArribaObj));
	return CollisionX && CollisionY;
}

bool CollisionMundo::Collision(Mortero& per, ColliderMap pared)
{
	//printf("velx=%f y vely=%f\n", per.velocidad.x, per.velocidad.y);
//printf("%d\n", per.valid_salto);
	float tamy = per.collider.tam.y / 2;
	float tamx = per.collider.tam.x / 2;
	bool In_collider = (per.GetPosicion().x - tamx <= pared.Arriba.x) && (per.GetPosicion().x + tamx >= pared.Abajo.x);//Estas en las X
	bool Under_collider = (per.GetPosicion().y + tamy <= pared.Arriba.y) && (per.GetPosicion().y - tamy <= pared.Abajo.y);// || (per.GetPosicion().y + tamy <= pared.Arriba.y) && (per.GetPosicion().y - tamy >= pared.Abajo.y);
	bool Up_collider = (per.GetPosicion().y - tamy - 0.01 <= pared.Arriba.y) && (per.GetPosicion().y - tamy - 0.01 >= pared.Abajo.y) && (per.GetPosicion().y + tamy >= pared.Arriba.y);


	if ((In_collider == true) && (Under_collider == false)) {


		//printf("Aire=%d, Suelo=%d\n", In_air,Up_collider);
		if ((Up_collider == true) && (per.velocidad.y < 0)) {
			//per.posicion.y = pared.Arriba.y + 0.64;
			per.velocidad.x = 0;
			per.velocidad.y = 0;
			per.aceleracion.y = 0;
			per.posicion.y = pared.Arriba.y + tamy;
			per.SetStatus();
		}

	}
	return Up_collider && In_collider;
}

bool CollisionMundo::Collision(Mortero& obj, Personaje& per)
{
	float tamxPer = per.collider.tam.x / 2;
	float tamxObj = obj.collider.tam.x / 2;
	float tamyPer = per.collider.tam.y / 2;
	float tamyObj = obj.collider.tam.y / 2;
	float partDelantePersonaje = per.GetPosicion().x + tamxPer;
	float partTraseraPersonaje = per.GetPosicion().x - tamxPer;
	float partArribaPersonaje = per.GetPosicion().y + tamyPer;
	float partAbajoPersonaje = per.GetPosicion().y - tamyPer;
	float partDelanteObj = obj.GetPosicion().x + tamxObj;
	float partTraseraObj = obj.GetPosicion().x - tamxObj;
	float partArribaObj = obj.GetPosicion().y + tamyObj;
	float partAbajoObj = obj.GetPosicion().y - tamyObj;


	bool CollisionX = ((partDelantePersonaje + 0.01 >= partTraseraObj) && (partTraseraPersonaje + 0.01 <= partDelanteObj));
	bool CollisionY = ((partArribaPersonaje + 0.01 >= partAbajoObj) && (partAbajoPersonaje + 0.01 <= partArribaObj));
	return CollisionX && CollisionY;
}

bool CollisionMundo::Collision(Flecha& per, ColliderMap pared)
{
	//printf("%d\n", per.valid_salto);
	float tamy = per.ImpactoFlecha.tam.y / 2;
	float tamx = per.ImpactoFlecha.tam.x / 2;
	float partDelantePersonaje = per.GetPosicion().x - tamx;
	float partTraseraPersonaje = per.GetPosicion().x + tamx;
	float partArribaPersonaje = per.GetPosicion().y + tamy;
	float partAbajoPersonaje = per.GetPosicion().y - tamy;
	bool Under_collider = (per.GetPosicion().y + tamy <= pared.Arriba.y) && (per.GetPosicion().y - tamy <= pared.Abajo.y);// || (per.GetPosicion().y + tamy <= pared.Arriba.y) && (per.GetPosicion().y - tamy >= pared.Abajo.y);
	bool FrontLateral_collider = (partDelantePersonaje <= pared.Arriba.x) && (partDelantePersonaje + 0.5 >= pared.Arriba.x) && (partDelantePersonaje >= pared.Abajo.x) && (partTraseraPersonaje > pared.Arriba.x) && (partArribaPersonaje >= pared.Abajo.y) && (partAbajoPersonaje <= pared.Arriba.y) && (per.velocidad.x < 0);//choque frontal
	bool BackLateral_collider = (partTraseraPersonaje >= pared.Abajo.x) && (partTraseraPersonaje <= pared.Arriba.x) && (partDelantePersonaje < pared.Abajo.x) && (partArribaPersonaje >= pared.Abajo.y) && (partAbajoPersonaje <= pared.Arriba.y) && (per.velocidad.x > 0);//choque trasero

	if ((Under_collider == false) && ((FrontLateral_collider == true) || (BackLateral_collider == true))) {
		bool FrontLateral_collider = (partDelantePersonaje <= pared.Arriba.x) && (partDelantePersonaje >= pared.Abajo.x) && (partTraseraPersonaje > pared.Arriba.x) && (partArribaPersonaje >= pared.Abajo.y) && (partAbajoPersonaje <= pared.Arriba.y) && (per.velocidad.x < 0);//choque frontal

		per.velocidad.x = 0;
		//per.aceleracion.x = 0;
		if (FrontLateral_collider == true)
			per.posicion.x = pared.Arriba.x + tamx;

		if ((BackLateral_collider == true)) {
			per.posicion.x = pared.Abajo.x - tamx;
		}
		//bool BackLateral_collider = (per.GetPosicion().x + tamx >= pared.Abajo.x) && (per.GetPosicion().x + tamx <= pared.Arriba.x) && (per.GetPosicion().y <= pared.Arriba.y) && (per.velocidad.x > 0);//choque trasero

		return FrontLateral_collider;
	}
}

bool CollisionMundo::Collision(ObjetoGeneral& obj, Flecha& f)
{
	float tamxPer = f.ImpactoFlecha.tam.x / 2;
	float tamxObj = obj.Collider.tam.x / 2;
	float tamyPer = f.ImpactoFlecha.tam.y / 2;
	float tamyObj = obj.Collider.tam.y / 2;
	float partDelantePersonaje = f.GetPosicion().x + tamxPer;
	float partTraseraPersonaje = f.GetPosicion().x - tamxPer;
	float partArribaPersonaje = f.GetPosicion().y + tamyPer;
	float partAbajoPersonaje = f.GetPosicion().y - tamyPer;
	float partDelanteObj = obj.GetPosicion().x + tamxObj;
	float partTraseraObj = obj.GetPosicion().x - tamxObj;
	float partArribaObj = obj.GetPosicion().y + tamyObj;
	float partAbajoObj = obj.GetPosicion().y - tamyObj;


	bool CollisionX = ((partDelantePersonaje + 0.01 >= partTraseraObj) && (partTraseraPersonaje + 0.01 <= partDelanteObj));
	bool CollisionY = ((partArribaPersonaje + 0.01 >= partAbajoObj) && (partAbajoPersonaje + 0.01 <= partArribaObj));
	return CollisionX && CollisionY;
}



bool CollisionMundo::Collision(Personaje& per, ColliderMap pared)
{
	//printf("velx=%f y vely=%f\n", per.velocidad.x, per.velocidad.y);
	//printf("%d\n", per.valid_salto);
	float tamy = per.collider.tam.y / 2;
	float tamx = per.collider.tam.x / 2;
	float partDelantePersonaje = per.GetPosicion().x - tamx;
	float partTraseraPersonaje = per.GetPosicion().x + tamx;
	float partArribaPersonaje = per.GetPosicion().y + tamy;
	float partAbajoPersonaje = per.GetPosicion().y - tamy;
	bool In_collider = (partDelantePersonaje + 0.01 <= pared.Arriba.x) && (partTraseraPersonaje - 0.01 >= pared.Abajo.x);//Estas en las X
	bool Under_collider = (per.GetPosicion().y + tamy <= pared.Arriba.y) && (per.GetPosicion().y - tamy <= pared.Abajo.y);// || (per.GetPosicion().y + tamy <= pared.Arriba.y) && (per.GetPosicion().y - tamy >= pared.Abajo.y);
	bool Up_collider = (partAbajoPersonaje - 0.01 <= pared.Arriba.y) && (partAbajoPersonaje + 0.5 >= pared.Arriba.y) && (partAbajoPersonaje - 0.01 >= pared.Abajo.y) && (partArribaPersonaje >= pared.Arriba.y);

	bool FrontLateral_collider = (partDelantePersonaje <= pared.Arriba.x) && (partDelantePersonaje + 0.5 >= pared.Arriba.x) && (partDelantePersonaje >= pared.Abajo.x) && (partTraseraPersonaje > pared.Arriba.x) && (partArribaPersonaje >= pared.Abajo.y) && (partAbajoPersonaje <= pared.Arriba.y) && (per.velocidad.x < 0);//choque frontal
	bool BackLateral_collider = (partTraseraPersonaje >= pared.Abajo.x) && (partTraseraPersonaje <= pared.Arriba.x) && (partTraseraPersonaje - 0.5 <= pared.Abajo.x) && (partDelantePersonaje < pared.Abajo.x) && (partArribaPersonaje >= pared.Abajo.y) && (partAbajoPersonaje <= pared.Arriba.y) && (per.velocidad.x > 0);//choque trasero
	bool Collision_under_Collider = ((per.GetPosicion().y + tamy + 0.01 <= pared.Arriba.y) && (per.GetPosicion().y + tamy + 0.01 >= pared.Abajo.y) && (per.GetPosicion().y - tamy <= pared.Abajo.y));

	if ((Under_collider == false) && ((FrontLateral_collider == true) || (BackLateral_collider == true))) {
		bool FrontLateral_collider = (partDelantePersonaje <= pared.Arriba.x) && (partDelantePersonaje >= pared.Abajo.x) && (partTraseraPersonaje > pared.Arriba.x) && (partArribaPersonaje >= pared.Abajo.y) && (partAbajoPersonaje <= pared.Arriba.y) && (per.velocidad.x < 0);//choque frontal

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
		if ((Up_collider == true) && (FrontLateral_collider == false) && (BackLateral_collider == false) && (per.velocidad.y < 0)) {
			//per.posicion.y = pared.Arriba.y + 0.64;
			if (per.velocidad.y <= -20)
				per.SetSalud(0);
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
