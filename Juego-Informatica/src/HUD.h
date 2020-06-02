#pragma once
#include "Vector2D.h"
#include "Personaje.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;
class HUD{
public:
	HUD();
	virtual ~HUD();
private:
	int salud;
	Vector2D local;
//	SpriteSequence mostrar;

public:
	 void Dibuja();
	
	 //meter funcion de los archivos de imagen
	 void SetPos(Personaje& p);
	 //consutla arturo
	 void SetVida(Personaje& p);

};