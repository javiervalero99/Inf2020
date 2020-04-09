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
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
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
	hombre.Dibuja();
}


void Mundo::Mueve(float t)
{
	hombre.Mueve(t);
}

void Mundo::Inicializa()
{
	x_ojo=0;
	y_ojo=10;
	z_ojo=-20;
}

void Mundo::TeclaUp(unsigned char key)
{

	hombre.TeclaUp(key);
	
}
void Mundo::TeclaDown(unsigned char key)
{

	hombre.TeclaDown(key);	
}
//Asi lo tengo yo para la práctica 4 y me funciona. Lo único es que cuando sueltas la tecla sigue moviendose a la izquierda
/*void Mundo::TeclaEspecial(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		hombre.setVel(-5.0f, 0.0f);
		break;
	case GLUT_KEY_RIGHT:
		hombre.setVel(5.0f, 0.0f);
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
