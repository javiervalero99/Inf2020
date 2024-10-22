#pragma once
#include "ETSIDI.h"
#include "Vector2D.h"
#include "Collision_Movil.h"

#include "Carcaj.h"

using ETSIDI::SpriteSequence;
class Personaje {
private:

	SpriteSequence Run;//sprite corriendo
	SpriteSequence Die;//sprite para muerte
	SpriteSequence Static;//sprite para personaje quieto
	SpriteSequence Basic;//sprite para ataque mele b�sico
	SpriteSequence Jump;//sprite para salto
	SpriteSequence Distance; //sprite para ataque a distancia

	Carcaj carcaj;

	float altura;
	int salud;
	float tiempo;
	int estado_flecha;
	bool MiraDerecha;
	bool estoy_disp;
	bool estoy_atacando;
	int estado_basico;
	int estado_muerte;
	bool muerte;
	int contador_muerte;
	double cd;
public:
	bool endgame;
	int Da�oataque; //= a asignacionVida de Objeto General
	bool validacionAsignacion;
	bool cae;
	int r, q, j; //r otorga la validaci�n para cada operacion de direccion
	//q cambia la sensibilidad de desplazamiento cuando saltas (permite movimientos m�s rapidos)
	float s, m; //s es el incremento cuando TeclaDown y m es el incremento cuando TeclaUp (contario a TeclaDown)
	int estados[3] = { 0 ,0 ,0}; //maquina de estados para a y d
	bool valid_salto;
	int i = 0;

	Personaje();
	virtual ~Personaje();
	void SetTiempo(float t);
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
	float GetSalud() { return salud; }
	void SetSalud(float s) { salud = s; }
	void AddSalud(float s) { 
		salud += s;
		if (salud > 10) {
			salud = 10;
		}

	}
	Carcaj& GetCarcaj() { return carcaj; }
	bool Muerte();
	//
	Collision_Movil collider;
	void da�o(float t);
};