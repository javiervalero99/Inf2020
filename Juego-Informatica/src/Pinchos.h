#pragma once
#include "ObjetoGeneral.h"
#include "glut.h"
class Pinchos :public ObjetoGeneral {
public:
	Pinchos(float px=0, float py=0, float tamx=0, float tamy=0) :ObjetoGeneral(px, py, 0, 0, tamx, tamy, 0, true) {
		salud = 40;
		asignacionSalud = -50;
		endgame = false;
	}
	~Pinchos(){}
	 void Dibuja() { 
		 /*glPushMatrix();
		 glTranslated(posicion.x, posicion.y, 1);
		 Collider.Dibuja();
		 glTranslated(-posicion.x, -posicion.y, -1);
		 glPopMatrix();*/
	 }
	void Mueve(float t) { validacionAsignacion = true; }
	void Persigue(Personaje& p){}
	bool ataca(Personaje& p) { return false; }
	
};