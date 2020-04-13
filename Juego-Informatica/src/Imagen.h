#pragma once
#include "ETSIDI.h"
#include "Personaje.h"
#include <string.h>
#include <iostream>
#include "glut.h"

class Imagen {
	friend class Personaje;
private:
	char TexturePath[100];
	float PosX;
	float PosY;
	float Ancho;
	float Alto;
public:
	void Inicializa(const char* texturePath, float x, float y, float ancho, float alto);
	void ActualizarPos(float x, float y);
	void Dibuja();
};