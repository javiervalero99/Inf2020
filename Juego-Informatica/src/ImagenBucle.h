#include "ETSIDI.h"
#include "Personaje.h"
#include <string.h>
#include <iostream>
#include "glut.h"

class ImagenBucle {
	friend class Personaje;
private:
	char TexturePath[100];
	int Columnas;
	int Filas;
	float FPS;
	bool Repeticion;
	float PosX;
	float PosY;
	float Ancho;
	float Alto;
	float Estado;
public:
	void Inicializa(const char* texturePath, int columnas, int filas, bool repeticion, int fps, float x, float y, float ancho, float alto);
	void ActualizarPos(float x, float y);
	void ActualizarEstado();
	void Dibuja();
};