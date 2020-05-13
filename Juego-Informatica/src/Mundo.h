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
#include "MenuPrincipal.h"
#include "Opcion_Menu.h"
#include "HUD.h"
#include "ListaCollider.h"
#include "InteraccionListas.h"
#include "Patrullero.h"
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
	bool menuDestruido;
	ImagenBucle Goku;
	Imagen Mapa;
	Imagen Fondo;
	Personaje Hombre;
	ListaCollider Colliders;
	//Enemigo enemigo;
	MenuPrincipal menu;
	HUD hud;
	Patrullero enemigo;
};

