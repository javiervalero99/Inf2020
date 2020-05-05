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
    glVertex2f(4.0+local.x,5.0+local.y);
    glVertex2f(6.0+local.x, 5.0+local.y);
    glVertex2f(6.0+local.x, 7.0+local.y);
    glVertex2f(4.0+local.x, 7.0+local.y);
    glEnd();
}

void HUD::SetPos(Personaje& p)
{
    local = p.posicion;
}





