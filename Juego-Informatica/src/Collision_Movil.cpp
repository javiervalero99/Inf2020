#include "Collision_Movil.h"
#include "glut.h"

Collision_Movil::Collision_Movil()
{
}

void Collision_Movil::Dibuja()
{
    glBegin(GL_POLYGON);
    glColor3f(10.0, 0.0, 5.0);
    glVertex3f(-tam.x / 2, -tam.y / 2, 0.0);
    glVertex3f(-tam.x / 2, tam.y / 2, 0.0);
    glVertex3f(tam.x / 2, tam.y / 2, 0.0);
    glVertex3f(tam.x / 2, -tam.y / 2, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glEnd();
}
