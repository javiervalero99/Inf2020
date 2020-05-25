#include "HUD.h"
#include "glut.h"
#include "Vector2D.h"
#include "Personaje.h"


HUD::HUD()
{
}

HUD::~HUD()
{
}

void HUD::Dibuja()
{
	glBegin(GL_QUADS);
    glVertex2f(4.0+local.x,3.0+local.y);
    glVertex2f(6.0+local.x, 3.0+local.y);
    glVertex2f(6.0+local.x, 5.0+local.y);
    glVertex2f(4.0+local.x, 5.0+local.y);
    glEnd();
}

void HUD::SetPos(Personaje& p)
{
    local = p.posicion;
}

void HUD::SetVida(Personaje& p)
{
   salud = p.GetSalud();
   switch (salud)
   {
   case 1: //1 de vida

       break;
   case 2:  //2 de vida

       break;
   case 3:  //3 de vida

       break;
   }
}





