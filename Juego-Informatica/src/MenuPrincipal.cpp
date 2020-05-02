#include "MenuPrincipal.h"
#define GLUT_DISABLE_ATEXIT_HACK

MenuPrincipal::MenuPrincipal(){
	Ancho = Largo = NumeroOpciones = 0;
}

MenuPrincipal::~MenuPrincipal()
{
}

void MenuPrincipal::SetDimensiones(float ancho, float largo)
{
	Ancho = ancho;
	Largo = largo;
}

void MenuPrincipal::SetNumeroOpciones(unsigned int x)
{
	NumeroOpciones = x;
}

bool MenuPrincipal::AddOpcion(Opcion_Menu* Opcion)
{
	for (int i = 0; i < NumeroOpciones; i++) {
		if ((lista[i] == Opcion)||(NumeroOpciones>=NUMERO_MAX_OPCIONES))
			return false;
	}
	lista[NumeroOpciones] = Opcion;
	NumeroOpciones++;
}

void MenuPrincipal::CreateMenu()
{
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3ub(125, 0, 25);
	glVertex3f(400, 300, -3.0);
	glVertex3f(400, -300, -3.0);
	glVertex3f(-400, -300, -3.0);
	glVertex3f(-400, 300, -3.0);
	glEnd();
	glPopMatrix;
	for (int i = 0; i < NumeroOpciones; i++) {
		lista[i]->Dibujar();
	}
}

bool MenuPrincipal::DestroyMenu()
{
	for (int i = 0; i < NumeroOpciones; i++) {
		delete lista[i];
	}
	NumeroOpciones = 0;
	return true;
}


void MenuPrincipal::Seleccionar_Opcion(unsigned char key, int x, int y){ 

}

void MenuPrincipal::SetOpciones()
{
	for (int i = 0; i < NumeroOpciones; i++)
	{
		
	}
}
