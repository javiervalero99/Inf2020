#include "Personaje.h"
#include "Imagen.h"
#include "ImagenBucle.h"
#include "ETSIDI.h"
#include "ColliderMap.h"
#include "CollisionMundo.h"
#include "Enemigo.h"
#include "MenuPrincipal.h"
#include "Opcion_Menu.h"

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

	float x_ojo;
	float y_ojo;
	float z_ojo;
	bool menuDestruido;
	ImagenBucle Goku;
	Imagen PutoSofrito;
	Personaje Hombre;
	ColliderMap Principal;
	ColliderMap Pared1;
	ColliderMap PlataformaSalto;
	ColliderMap Pared2;
	ColliderMap SeccionMiniPlataforma1;
	ColliderMap SeccionMiniPlataforma2;
	ColliderMap SeccionMiniPlataforma3;
	ColliderMap SeccionPlataformaMediana1; //con arbol
	Enemigo enemigo;
	MenuPrincipal menu;
};
