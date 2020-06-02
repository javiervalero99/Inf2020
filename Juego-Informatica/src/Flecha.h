#pragma once
#include "ETSIDI.h"
#include "Vector2D.h"
#include <math.h>
#include "Collision_Movil.h"
#include "glut.h"


using ETSIDI::SpriteSequence;

class Flecha
{
private:

	Vector2D velocidad;
	Vector2D posicion;
	float radio = 0.025; //tamaño de la flecha que usaremos para el collider
	SpriteSequence arrow;//lo pongo en ingles para no confundir
	bool dir;
public:
	Collision_Movil ImpactoFlecha;
	Flecha();
	Flecha(float posx, float posy, bool direccion_derecha); //cada vez que se llame a la función sera para disparar una flecha, se le pasa posición del hombre
	virtual ~Flecha();
	void SetFlecha(int posx, int posy, bool direccion_derecha);
	void Dibuja();
	void Mueve(float t);
	Vector2D& GetPosicion() { return posicion; }

	friend class CollisionMundo;
};