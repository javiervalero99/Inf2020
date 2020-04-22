#include "ColliderMap.h"
#include <cmath>
#include "glut.h"

ColliderMap::ColliderMap()
{

}

void ColliderMap::Dibuja()
{
	float centroX = Arriba.x - Abajo.y;
	float centroY = Arriba.y - Abajo.y;
  //  glTranslatef(centroX, centroY, 0);

    glColor3f(5.0, 5.0, 5.0);
    glBegin(GL_POLYGON);
    glVertex3f(Arriba.x, Arriba.y, 0.0);
    glVertex3f(Arriba.x, Abajo.y, 0.0);
    glVertex3f(Abajo.x, Abajo.y, 0.0);
    glVertex3f(Abajo.x, Arriba.y, 0.0);
   
    
    glEnd();
    glFlush();
   // glTranslatef(-centroX,-centroY, 0);
}

