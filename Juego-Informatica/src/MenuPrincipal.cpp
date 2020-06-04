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
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("Data_Game/Nivel1/PantallaInicio.png").id);
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
