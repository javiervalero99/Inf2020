#include "ImagenBucle.h"

void ImagenBucle::Inicializa(const char* texturePath,int columnas, int filas, bool repeticion, int fps, float x, float y, float ancho, float alto)
{
	strcpy_s(TexturePath, texturePath);
	Columnas = columnas;
	Filas = filas;
	frecuencia_actualizacion = fps;
	Repeticion = repeticion;
	PosX = x;
	PosY = y;
	Ancho = ancho;
	Alto = alto;
	Estado = 0;
}

void ImagenBucle::ActualizarPos(float x, float y) {
	PosX = x;
	PosY = y;
}

void ImagenBucle::Actualizar40FPS()	//Se realiza 40 veces por segundo
{	
	Estado = Estado + 1;		//Se varia el 1 para cambiar la velocidad
	if (Estado > (Filas * Columnas))
		Estado = 0;
}

void ImagenBucle::Dibuja()
{
	ETSIDI::SpriteSequence spritesecuence(TexturePath, Columnas, Filas, frecuencia_actualizacion, Repeticion, PosX, PosY, Ancho, Alto, Estado);
		spritesecuence.draw();
		spritesecuence.loop();
}