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
	if (estado == INSTRUCCIONES) {
		if (key == ' ') {
			estado = INICIO;
		}
	}
	else if (estado == INICIO) {
		if (key == 's') {
			exit(0);
		}
	}
	else if (estado == JUEGO) {
		mundo.TeclaDown(key);
		if (key == 27)
			estado = PAUSA;
	}
	else if (estado == GAMEOVER) {
		if (key == ' ') {
			exit(1);
		}
	}
	else if (estado == FIN) {
		if (key == ' ') {
			exit(1);
		}
	}
	else if (estado == PAUSA) {
		if (key == ' ')
			estado = JUEGO;
	}
}

void Coordinador_Juego::ClickDch(int state, int x, int y)
{
	if (estado == INICIO) {
		Vector2D boton_juego_Arriba(70, 340);
		Vector2D boton_juego_Abajo(235, 422);
		printf("x:%d  y:%d\n", x, y);
		bool x_en_boton_juego = (x >= 374) && (x <= 459);
		bool y_en_boton_juego = (y >= 413) && (y <= 455);
		if ((x_en_boton_juego == true) && (y_en_boton_juego == true)) {
			mundo.Inicializa();
			estado = CARGA;
		}
			bool x_en_boton_juego1 = (x >= 730) && (x <= 878);
			bool y_en_boton_juego1= (y >= 412) && (y <= 457);
			if ((x_en_boton_juego1 == true) && (y_en_boton_juego1 == true)) {
				estado = INSTRUCCIONES;
			}
	}
}

void Coordinador_Juego::Mueve()
{
	if (estado == JUEGO) {
		mundo.Mueve(0.025);
	}
}

void Coordinador_Juego::Dibuja()
{
	if (estado == JUEGO && mundo.Hombre.Muerte()==true)
		estado = GAMEOVER;
	if (estado == INICIO) {
		gluLookAt(0, 0, 7.5,
			0.0, 0.0, 0.0,
			0.0, 1.0, 0.0);
		glDisable(GL_LIGHTING);
		menu.CreateMenu();
		ETSIDI::setTextColor(50, 150, 50);
		ETSIDI::setFont("Data_Game/fuentes/Venatto.ttf", 30);
		ETSIDI::printxy("C Y N T H I A  Y  E L  L A D R O N  D E  L U Z ", -2, 1);
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("Data_Game/fuentes/Venatto.ttf", 18);
		ETSIDI::printxy("J U G A R", -2, -1);
		ETSIDI::printxy("C O M O  J U G A R ", 1, -1);
	}
	else if (estado == CARGA) {
		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("Data_Game/Nivel1/PantallaCarga.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 0); glVertex3f(2.1, 1.1, -3.0);//4,3
		glTexCoord2d(1, 0); glVertex3f(2.1, -1.1, -3.0);//4 -3
		glTexCoord2d(1, 1); glVertex3f(-2.1, -1.1, -3.0);//-4 -3
		glTexCoord2d(0, 1); glVertex3f(-2.1, 1.1, -3.0);//-4 3
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
			estado = JUEGO;
	}
	else if (estado == JUEGO) {
		ETSIDI::playMusica("Data_Game/SONG.mp3", true);
		mundo.Dibuja();
		if (mundo.Enemigos[0].Endgame())
			estado = FIN;
	}
	else if (estado == GAMEOVER) {
		gluLookAt(0, 0, 7.5,
			0.0, 0.0, 0.0,
			0.0, 1.0, 0.0);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("Data_Game/Nivel1/Game_Over.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 0); glVertex3f(7.5, 3.8, -3.0);//4,3
		glTexCoord2d(1, 0); glVertex3f(7.5, -3.8, -3.0);//4 -3
		glTexCoord2d(1, 1); glVertex3f(-7.5, -3.8, -3.0);//-4 -3
		glTexCoord2d(0, 1); glVertex3f(-7.5, 3.8, -3.0);//-4 3
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		ETSIDI::setTextColor(50, 150, 50);
		ETSIDI::setFont("Data_Game/fuentes/Venatto.ttf", 30);
		ETSIDI::printxy("H A S  M U E R T O ,   P U L S A   E S P A C I O   P A R A   C O N T I N U A R", -2, 2);
		mundo.~Mundo();
	}
	else if (estado == FIN) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("Data_Game/Nivel1/FIN.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 0); glVertex3f(2.1, 1.1, -3.0);//4,3
		glTexCoord2d(1, 0); glVertex3f(2.1, -1.1, -3.0);//4 -3
		glTexCoord2d(1, 1); glVertex3f(-2.1, -1.1, -3.0);//-4 -3
		glTexCoord2d(0, 1); glVertex3f(-2.1, 1.1, -3.0);//-4 3
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		mundo.~Mundo();
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
	else if (estado == INSTRUCCIONES) {
		gluLookAt(0, 0, 7.5,
			0.0, 0.0, 0.0,
			0.0, 1.0, 0.0);
		glDisable(GL_LIGHTING);
		menu.CreateMenu();
		ETSIDI::setTextColor(50, 150, 50);
		ETSIDI::setFont("Data_Game/fuentes/Venatto.ttf", 20);
		ETSIDI::printxy("I N S T R U C C I O N E S :", -2, 1);
		ETSIDI::printxy("'A'   M O V I M I E N T O  I Z Q U I E R D A             'D'   M O V I M I E N T O  D E R E C H A ", -2, 0);
		ETSIDI::printxy(" 'Q'   A R C O                                         'E'  A T A Q U E  B A S I C O", -2, -1);
		ETSIDI::printxy("E S P A C I O   S A L T O       P U L S A L O   P A R A   C O N T I N U A R", -2, -2);
		ETSIDI::playMusica("C:/Users/rengarete/Downloads/SONG.mp3", true);
	}
}

