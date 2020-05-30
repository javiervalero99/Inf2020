#include <iostream>
#include <fstream>
#include <math.h>
#include <stdio.h>
#include <string>


#include "Personaje.h"
#include "Imagen.h"
#include "ImagenBucle.h"
#include "ETSIDI.h"
#include "ColliderMap.h"
#include "CollisionMundo.h"
#include "Enemigo.h"
#include "HUD.h"
#include "ListaCollider.h"
#include "InteraccionListas.h"
#include "ListaEnemObj.h"
#include "Patrullero.h"
#include "Artillero.h"
#include "Tiempo.h"
#include "Mortero.h"
class Mundo
{
public:
	Mundo();
	virtual ~Mundo();
	void Tecla(unsigned char key);
	void Inicializa();
	void RotarOjo();
	void Mueve(float t);
	void Dibuja();
	void TeclaUp(unsigned char key);
	void TeclaDown(unsigned char key);
	void ClickDch(int state, int x, int y);
	void Leer_Fichero(const char[]);
	bool Leer_Collider(char[], ColliderMap* p);
	float x_ojo;
	float y_ojo;
	float z_ojo;
	bool FIN = false;
	//	ImagenBucle Goku;
	Imagen Mapa;
	Imagen Fondo;
	Personaje Hombre;
	ListaCollider Colliders;


	HUD hud;
	//Patrullero enemigo;
	Artillero artillero;
	Mortero mortero;
	ListaEnemObj Enemigos;
	bool fire;
	// variables de juego

};
