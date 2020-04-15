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
	//Hombre.Dibuja();			//Dibuja el cuadrado que representa al hombre
	Goku.Dibuja();
	PutoSofrito.Dibuja();
}

void Mundo::Mueve(float t)
{
	Hombre.Mueve(t);
	Goku.ActualizarPos(Hombre.posicion.x, Hombre.posicion.y);
	Goku.ActualizarEstado();
}

void Mundo::Inicializa()
{
	x_ojo=Hombre.GetPosicion().x;
	y_ojo=10 + Hombre.GetPosicion().y;
	z_ojo=-20;
	Goku.Inicializa("D:/@Descargas/GokuOndaVital.png", 8, 1, 1, true, Hombre.posicion.x, Hombre.posicion.y, 3, 4);
	PutoSofrito.Inicializa("D:/@Descargas/PutoSofrito1.png", 0, 1, 3, 3);
}

void Mundo::TeclaUp(unsigned char key)
{
	Hombre.TeclaUp(key);
}
void Mundo::TeclaDown(unsigned char key)
{

	Hombre.TeclaDown(key);	
}
//Asi lo tengo yo para la práctica 4 y me funciona. Lo único es que cuando sueltas la tecla sigue moviendose a la izquierda
/*void Mundo::TeclaEspecial(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		Hombre.setVel(-5.0f, 0.0f);
		break;
	case GLUT_KEY_RIGHT:
		Hombre.setVel(5.0f, 0.0f);
		break;
	}
}
*/
/*void Mundo::Leer_teclado(unsigned char key)
{
	float i;
	tamaños
	if (key == '+')
		a.SetX1(a.GetX1()+0.25);
	if (key == '-')
		a.SetX1(a.GetX1() - 0.25);
	//movimientos
	if (key == 'w')
		a.SetX3 (a.GetX3() + 0.25);
	if (key == 's')
		a.SetX3 (a.GetX3() - 0.25);*/
