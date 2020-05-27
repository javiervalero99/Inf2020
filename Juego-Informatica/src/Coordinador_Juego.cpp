#include "Coordinador_Juego.h"
#include "ETSIDI.h"
Coordinador_Juego::Coordinador_Juego()
{
	estado = INICIO;
}

Coordinador_Juego::~Coordinador_Juego()
{
	menu.DestroyMenu();
}

void Coordinador_Juego::Inicializa()
{
	//------------------Menu--------------------------------------
	Vector2D Arriba(2.75, -0.5);
	Vector2D Abajo(0.75, -1.5);
	Opcion_Menu* op = new Opcion_Menu(Arriba, Abajo);
	op->SetColor(0, 155, 75);
	menu.AddOpcion(op);
	Vector2D Arriba1(-2.75, -0.5);
	Vector2D Abajo1(-0.75, -1.5);
	Opcion_Menu* op1 = new Opcion_Menu(Arriba1, Abajo1);
	op1->SetColor(0, 155, 75);
	menu.AddOpcion(op1);
	Vector2D Arriba2(-2.25, -2);
	Vector2D Abajo2(2.25, -2.5);
	Opcion_Menu* op2 = new Opcion_Menu(Arriba2, Abajo2);
	op2->SetColor(0, 155, 75);
	menu.AddOpcion(op2);
}

void Coordinador_Juego::TeclaUp(unsigned char key)
{
	if (estado == JUEGO)
		mundo.TeclaUp(key);
}

void Coordinador_Juego::TeclaDown(unsigned char key)
{
	
	if (estado == INICIO) {
		if (key == 's') {
			exit(0);
		}
	}
	else if (estado == JUEGO){
		mundo.TeclaDown(key);
		if (key == 27)
			estado = PAUSA;
	}
	else if (estado == GAMEOVER) {

		if (key == 'c') {
			estado = INICIO;
		}
	}
	else if (estado == FIN) {
		if (key == 'c') {
			estado = INICIO;
		}
	}
	else if (estado == PAUSA) {
		if (key == 'c')
			estado = JUEGO;
	}
}

void Coordinador_Juego::ClickDch(int state, int x, int y)
{
	Vector2D boton_juego_Arriba(70, 340);
	Vector2D boton_juego_Abajo(235, 422);
	printf("x:%d  y:%d\n", x, y);
	bool x_en_boton_juego = (x >= 117) && (x <= 325);
	bool y_en_boton_juego = (y >= 352) && (y <= 455);
	if ((x_en_boton_juego == true) && (y_en_boton_juego == true)) {
		estado = JUEGO;
		mundo.Inicializa();
	}
}

void Coordinador_Juego::Mueve()
{
	if (estado == JUEGO) {
		mundo.Mueve(0.025);
		if (mundo.FIN == 0) {
			/*if (!mundo.cargarNivel())
				estado = FIN;
		}*/
		//To-do añadir mecanica muerte
		/*if (mundo.GetImpaco()) {
			estado = GAMEOVER;
		}*/
		}
	}
}

void Coordinador_Juego::Dibuja()
{
	if (estado == INICIO) {
		gluLookAt(0, 0,7.5,
			0.0, 0.0, 0.0,
			0.0, 1.0, 0.0);
			glDisable(GL_LIGHTING);
			menu.CreateMenu();
			ETSIDI::setTextColor(0, 0.5, 1);
			ETSIDI::setFont("Data_Game/fuentes/Bitwise.ttf", 16);
			ETSIDI::printxy("FREYA Y EL LADRON DE LUZ", -2, 2);
			ETSIDI::setTextColor(1, 0, 0);
			ETSIDI::setFont("Data_Game/fuentes/Bitwise.ttf", 12);
			ETSIDI::printxy("JUGAR", -2, -1);
			ETSIDI::printxy("COMO JUGAR", 1, -1);
	}
		
	else if (estado == JUEGO) {
		mundo.Dibuja();
	}
	else if (estado == GAMEOVER) {
		mundo.Dibuja();
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("GAMEOVER: Has perdido", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 5);
	}
	else if (estado == FIN) {
		mundo.Dibuja();
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("ENHORABUENA, ¡Has triunfado!", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 9);
	}
	else if (estado == PAUSA) {
		//mundo.Dibuja();
		menu.CreateMenu();
		ETSIDI::setTextColor(0, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
		ETSIDI::printxy("MENU DE PAUSA", -5, 10);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 5);
	}
}

