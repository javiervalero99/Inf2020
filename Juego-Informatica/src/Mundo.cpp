#include "Mundo.h"
#include "glut.h"
#include <math.h>

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
	gluLookAt(Hombre.GetPosicion().x, Hombre.GetPosicion().y, z_ojo,  // posicion del ojo
			Hombre.GetPosicion().x, Hombre.GetPosicion().y, 0.0, // hacia que punto mira  (donde este el personaje, quizas crear una clase camara) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	//dibujo del suelo
	glDisable(GL_LIGHTING);
	glTranslated(0, -1, 0);
	glBegin(GL_POLYGON);
		glColor3ub(255,0,0);
		glVertex3f(-5.0f,0,-5.0f);
		glVertex3f(-5.0f,0,5.0f);
		glColor3ub(255,255,0);
		glVertex3f(5.0f,0,5.0f);	
		glVertex3f(5.0f,0,-5.0f);
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

void Mundo::Mueve(float t)
{
	Hombre.Mueve(t);
	Goku.ActualizarPos(Hombre.posicion.x, Hombre.posicion.y);
	Goku.Actualizar40FPS();
	enemigo.Mueve(t);


	//enemigo
	enemigo.Persigue(Hombre);
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
}

void Mundo::TeclaUp(unsigned char key)
{
	Hombre.TeclaUp(key);
}
void Mundo::TeclaDown(unsigned char key)
{
	Hombre.TeclaDown(key);	
}
