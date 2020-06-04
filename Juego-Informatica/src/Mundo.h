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
#include "Bonus.h"
#include "BossFinal.h"
#include "Pinchos.h"
#include "Coco_Dandee.h"

class Mundo
{
public:
	Mundo();
	virtual ~Mundo();
	void Inicializa();
	void RotarOjo();
	void Mueve(float t);
	void Dibuja();
	void TeclaUp(unsigned char key);
	void TeclaDown(unsigned char key);
	void Leer_Fichero(const char[]);
	bool Leer_Collider(char[], ColliderMap* p);
	float x_ojo;
	float y_ojo;
	float z_ojo;
	bool FIN = false;
	Imagen Mapa;
	Imagen Fondo;
	Imagen FondoCueva;
	Personaje Hombre;
	ListaCollider Colliders;


	HUD hud;
	int contador_boss;
	ListaEnemObj Enemigos;
	// variables de juego

};
