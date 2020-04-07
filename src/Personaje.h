#pragma once
#include "Vector2D.h"
class Personaje {
private:
	float altura;
	int salud;

public:
	bool valid_salto;
	int i=0;
	Personaje();
	virtual ~Personaje();
	void Mueve(float t);
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	void Dibuja();
	void Ataque_Basico();
	void Salto(unsigned char key);
	void TeclaDown(unsigned char key );
	void TeclaUp(unsigned char key );
};
