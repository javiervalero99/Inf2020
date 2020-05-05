#include "Mundo.h"
#include <math.h>
#include <stdio.h>
#include <string>
#include "glut.h"

Mundo::Mundo()
{
	x_ojo = y_ojo = z_ojo = 0;
	menuDestruido = false;
}

Mundo::~Mundo()
{
	menu.DestroyMenu();
}

void Mundo::RotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}

void Mundo::Dibuja()
{
	if (menuDestruido == false) {
		glDisable(GL_LIGHTING);
		menu.CreateMenu();
		glRasterPos3f(-0.08, 0, -0.25);
		char ButtonTitle[10] = "Jugar";
		for (int i = 0; ButtonTitle[i] != '\0'; i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ButtonTitle[i]);  // Updates the position
		}
		glEnable(GL_LIGHTING);
	}
	if (menuDestruido == true) {
		gluLookAt(Hombre.GetPosicion().x, Hombre.GetPosicion().y, z_ojo,  // posicion del ojo
			Hombre.GetPosicion().x, Hombre.GetPosicion().y, 0.0, // hacia que punto mira  (donde este el personaje, quizas crear una clase camara) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	//dibujo del suelo
		glDisable(GL_LIGHTING);
		glTranslated(0, -1, 0);
		glBegin(GL_POLYGON);
		glColor3ub(255, 0, 0);
		glVertex3f(-5.0f, 0, -5.0f);
		glVertex3f(-5.0f, 0, 5.0f);
		glColor3ub(255, 255, 0);
		glVertex3f(5.0f, 0, 5.0f);
		glVertex3f(5.0f, 0, -5.0f);
		glEnd();
		glEnable(GL_LIGHTING);
		glTranslated(0, 1, 0);
		Hombre.Dibuja();			//Dibuja el cuadrado que representa al hombre
		//Goku.Dibuja();

		enemigo.Dibuja();


		PutoSofrito.Dibuja();
		Principal.Dibuja();
		Pared1.Dibuja();
		PlataformaSalto.Dibuja();
		Pared2.Dibuja();
		SeccionMiniPlataforma1.Dibuja();
		SeccionMiniPlataforma2.Dibuja();
		SeccionMiniPlataforma3.Dibuja();
		SeccionPlataformaMediana1.Dibuja();
		
		bool valid2 = CollisionMundo::Collision(Hombre, Pared1);
		bool valid4 = CollisionMundo::Collision(Hombre, Pared2);
		float valid3 = CollisionMundo::Collision(Hombre, PlataformaSalto);
		bool valid1 = CollisionMundo::Collision(Hombre, Principal, PlataformaSalto);
		bool valid5 = CollisionMundo::Collision(Hombre, SeccionMiniPlataforma1);
		bool valid6 = CollisionMundo::Collision(Hombre, SeccionMiniPlataforma2);
		bool valid7 = CollisionMundo::Collision(Hombre, SeccionMiniPlataforma3);
		bool valid8 = CollisionMundo::Collision(Hombre, SeccionPlataformaMediana1);
		if ((valid2 == false) && (valid1 == false) && (valid4 == false) && (valid5 == false) && (valid6 == false) && (valid7 == false) && (valid8 == false) && (Hombre.j == 0)) {

			Hombre.cae = true;
			Hombre.j++;
		}

		//enemigo
		bool valid9 = CollisionMundo::Collision(enemigo, Pared2);
		if (valid9 == false)
		{
			enemigo.cae = true;
			enemigo.j++;
		}
	}

	hud.SetPos(Hombre);
	hud.Dibuja();

}

void Mundo::Mueve(float t)
{
	if (menuDestruido == true) {
		Hombre.Mueve(t);
		Goku.ActualizarPos(Hombre.posicion.x, Hombre.posicion.y);
		Goku.Actualizar40FPS();
		enemigo.Mueve(t);
		//enemigo
		enemigo.Persigue(Hombre);
	}
}


void Mundo::Inicializa()
{
	x_ojo = Hombre.GetPosicion().x;
	y_ojo = 10 + Hombre.GetPosicion().y;
	z_ojo = -20;
	Goku.Inicializa("\Sprites/GokuOndaVital.png", 8, 1, 0.1, true, Hombre.posicion.x, Hombre.posicion.y, 3, 4);
	PutoSofrito.Inicializa("\Sprites/PutoSofrito1.png", 0, 1, 3, 3);
	//ETSIDI::playMusica("\Crimson_Nights_Track_02.mp3", true);
	Principal.Inicializa(0, -0.65, -12.0, -5.0);
	Pared1.Inicializa(-12.0, 2.0, -15.0, -5.0);
	PlataformaSalto.Inicializa(-6, 5.5, -10, 5);
	Pared2.Inicializa(-15.0, 8, -30.0, -5.0);
	SeccionMiniPlataforma1.Inicializa(-32.0, 5, -34.0, 3);
	SeccionMiniPlataforma2.Inicializa(-36.5, 7, -38, 6);
	SeccionMiniPlataforma3.Inicializa(-40, 5, -42, 3);
	SeccionPlataformaMediana1.Inicializa(-45, 7, -52, 0);
	//------------------Menu--------------------------------------


Vector2D Arriba(0.2, -0.025);
Vector2D Abajo(0.1, -0.075);
	Opcion_Menu* op = new Opcion_Menu(Arriba,Abajo);
	op->SetColor(0, 155, 75);
	menu.AddOpcion(op);
	Vector2D Arriba1(-0.2, -0.025);
	Vector2D Abajo1(-0.1, -0.075);
	Opcion_Menu* op1 = new Opcion_Menu(Arriba1, Abajo1);
	op1->SetColor(0, 155, 75);
	menu.AddOpcion(op1);
	Vector2D Arriba2(-0.05, -0.125);
	Vector2D Abajo2(0.05, -0.15);
	Opcion_Menu* op2 = new Opcion_Menu(Arriba2, Abajo2);
	op2->SetColor(0, 155, 75);
	menu.AddOpcion(op2);

}

void Mundo::TeclaUp(unsigned char key)
{
	Hombre.TeclaUp(key);
}
void Mundo::TeclaDown(unsigned char key)
{
	printf("%d\n", key);
	if (key == 27) {
		menuDestruido = false;
	}
	else {
		Hombre.TeclaDown(key);
	}
}

void Mundo::ClickDch(int state, int x, int y)
{
	Vector2D boton_juego_Arriba(70, 340);
	Vector2D boton_juego_Abajo(235, 422);
	bool x_en_boton_juego = (x >= 70) && (x <= 340);
	bool y_en_boton_juego= (y <= 422) && (y >= 235);
	if ((x_en_boton_juego == true) && (y_en_boton_juego == true)) {
		menuDestruido = true;
	}
}
