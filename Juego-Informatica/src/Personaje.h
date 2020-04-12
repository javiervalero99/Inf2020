#pragma once
#include "Vector2D.h"
class Personaje {
private:
	float altura;
	int salud;
	float tiempo;
public:
	int r, q; //r otorga la validación para cada operacion de direccion
	//q cambia la sensibilidad de desplazamiento cuando saltas (permite movimientos más rapidos)
	float s, m; //s es el incremento cuando TeclaDown y m es el incremento cuando TeclaUp (contario a TeclaDown)
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
