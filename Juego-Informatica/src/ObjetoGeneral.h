#pragma once
#include "Vector2D.h"
#include "Collision_Movil.h"
#include "Personaje.h"
class ObjetoGeneral {
protected:
	float altura;
	float salud;


public:
	int asignacionSalud; //Cuanto dañan o aportan al personaje, Daño<0, Vida>0
	bool validacionAsignacion; //Indica cuando debe hacerse el daño o la vida por defecto false
	int tipo;
	Collision_Movil Collider;
	bool cae;
	int j, q;
	bool CollisionPersonaje;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	ObjetoGeneral(float px = 0, float py = 0, float vx = 0, float vy = 0, float tamx = 0, float tamy = 0, int tipo = 0, bool valid = false) :posicion(px, py), velocidad(vx, vy), cae(false), Collider(tamx, tamy), CollisionPersonaje(false), tipo(tipo), validacionAsignacion(valid) {}
	virtual void Dibuja() = 0;
	virtual void Mueve(float t) = 0;
	virtual void Persigue(Personaje& p) = 0;
	Vector2D GetPosicion() { return posicion; }
	void SetPosicion(Vector2D& pos) { posicion = pos; }
	void SetPosicion(float posx, float posy) { posicion.x = posx; posicion.y = posy; }
	float GetSalud() { return salud; }
	void SetSalud(float s) { salud = s; }
	void AddSalud(float s) { salud += s; }
	virtual bool ataca(Personaje& p) = 0;
};