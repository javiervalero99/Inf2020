#pragma once
#include <stdlib.h>
#include "Mundo.h"
#include "ETSIDI.h"
#include "MenuPrincipal.h"
#include "Opcion_Menu.h"
#include "Vector2D.h"
#include "Personaje.h"

#include "glut.h"
class Coordinador_Juego {
public:
	Coordinador_Juego();
	~Coordinador_Juego();
	void Inicializa();
	void TeclaUp(unsigned char key);
	void TeclaDown(unsigned char key);
	void ClickDch(int state, int x, int y);
	void Mueve();
	void Dibuja();
protected:
	bool menuDestruido;
	MenuPrincipal menu;
	Mundo mundo;
	enum Estado { INICIO, CARGA, JUEGO, GAMEOVER, FIN, PAUSA,INSTRUCCIONES };
	Estado estado;
	friend class BossFinal;
};
