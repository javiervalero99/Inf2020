#include "ETSIDI.h"
#include <iostream>
#include <cmath>
#include <stdio.h>
#include "Enemigo.h"
#include "glut.h"

#pragma once

using ETSIDI::SpriteSequence;

class BossFinal : public Enemigo
{
private:
	bool EntrarModoDiablo;			//Flag de control del modo diablo. Sólo se activa una vez.
	bool ComienzaCombate;
	bool estoy_muriendo;
	bool estoy_ataque1;
	bool estoy_ataque2;
	bool estoy_ataque3;
	bool estoy_ataqueesp;
	bool estoy_statico;
	int estado_ataque1;
	int estado_ataque2;
	int estado_ataque3;
	int estado_ataque_esp;
	int estado_die;
	int estado_jump;
	int estado_statico;
	int contador_die;

	int DañoAtaque[4];
	int n;				//Número de veces que lanza el ataque 1 y el 3.
	int contador;
	float velo0;			//Modulo velocidad de salto
	float angulo;			//Angulo de salto
	double TiempoEjecucion;
	SpriteSequence Ataque;//bool ataque 1
	SpriteSequence Die;
	SpriteSequence Patada;//bool ataque 2
	SpriteSequence Patada2;
	SpriteSequence Puñetazo;//bool ataque 3
	SpriteSequence Run;
	SpriteSequence Statico;
	SpriteSequence Torbellino;//bool ataque esp
	SpriteSequence Jump;//bool

public:
	BossFinal(int x, int y);
	~BossFinal();
	bool ataca(Personaje &p);
	bool SetSalto(Personaje& p);
	void ModoDiablo();				//Estado en el que el boss recupera la salud y lanza ataques más fuertes. Sólo se activa una vez.
	void Dibuja();
	void Mueve(float t);
	void Persigue(Personaje &p);
	bool ComenzarCombate(Personaje &p);
	bool Endgame();
};

/*Cuando se vaya a hacer un ataque primero se debe debe asignar el valor de daño cirrespondiente en asignacion salud y luego 
se le pone la validacion de asignacion a true .
En ese orden*/