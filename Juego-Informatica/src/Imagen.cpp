#include "Imagen.h"

void Imagen::Inicializa(const char* texturePath, float x, float y, float ancho, float alto)
{
	strcpy_s(TexturePath, texturePath);
	PosX = x;
	PosY = y;
	Ancho = ancho;
	Alto = alto;
}

void Imagen::ActualizarPos(float x, float y){
	PosX = x;
	PosY = y;
}

void Imagen::Dibuja()
{	
	ETSIDI::Sprite sprite(TexturePath, PosX, PosY,Ancho, Alto);
	sprite.draw();
	sprite.loop();
}