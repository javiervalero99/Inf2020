#pragma once
#include "Vector2D.h"
class Personaje {
private:
	float altura;
	int salud;
	float tiempo;
public:
	float VelocNeg;
	bool valid_salto;
	int i = 0;
	Personaje();
	void SetTiempo(float t);
	virtual ~Personaje();
	void Mueve(float t);
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	void Dibuja();
	Vector2D GetPosicion();
	void Ataque_Basico();
	void Salto(unsigned char key);
	void TeclaDown(unsigned char key);
	void TeclaUp(unsigned char key);
};
