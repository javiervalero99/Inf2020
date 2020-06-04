#include "HUD.h"
#include "glut.h"
#include "Vector2D.h"
#include "Personaje.h"


HUD::HUD() : full("\Data_Game/Objects/Heart.png", 1, 1, 100), half("\Data_Game/Objects/HearDañado.png", 1, 1, 100), none("\Data_Game/Objects/HearVacio.png", 1, 1, 100)
{
    full.setSize(1, 1);
    full.setCenter(0.5, 0);
    half.setSize(1, 1);
    half.setCenter(0.5, 0);
    none.setSize(1, 1);
    none.setCenter(0.5, 0);
    half.flip(true, false);
}

HUD::~HUD()
{
}

void HUD::Dibuja()
{

    switch (salud) {
    case 1:
        glPushMatrix();
        glTranslated(8 + local.x, 4 + local.y, -1);
        half.draw();
        glTranslated(-0.5, 0, 0);
       none.draw();
        glTranslated(-0.5, 0, 0);
        none.draw();
        glTranslated(-0.5, 0, 0);
        none.draw();
        glTranslated(-0.5, 0, 0);
        none.draw();
        glTranslated(-6 - local.x, -4 - local.y, -1);
        glPopMatrix();

        break;
    case 2:
        glPushMatrix();
        glTranslated(8 + local.x, 4 + local.y, -1);
        full.draw();
        glTranslated(-0.5, 0, 0);
        none.draw();
        glTranslated(-0.5, 0, 0);
        none.draw();
        glTranslated(-0.5, 0, 0);
        none.draw();
        glTranslated(-0.5, 0, 0);
        none.draw();
        glTranslated(-6 - local.x, -4 - local.y, -1);
        glPopMatrix();
        break;
        
    case 3:
        glPushMatrix();
        glTranslated(8 + local.x, 4 + local.y, -1);
        full.draw();
        glTranslated(-0.5, 0, 0);
        half.draw();
        glTranslated(-0.5, 0, 0);
        none.draw();
        glTranslated(-0.5, 0, 0);
        none.draw();
        glTranslated(-0.5, 0, 0);
        none.draw();
        glTranslated(-6 - local.x, -4 - local.y, -1);
        glPopMatrix();
        break;
    
    case 4:
        glPushMatrix();
        glTranslated(8 + local.x, 4 + local.y, -1);
        full.draw();
        glTranslated(-0.5, 0, 0);
        full.draw();
        glTranslated(-0.5, 0, 0);
        none.draw();
        glTranslated(-0.5, 0, 0);
        none.draw();
        glTranslated(-0.5, 0, 0);
        none.draw();
        glTranslated(-6 - local.x, -4 - local.y, -1);
        glPopMatrix();
        break;
       
    case 5:
        glPushMatrix();
        glTranslated(8 + local.x, 4 + local.y, -1);
        full.draw();
        glTranslated(-0.5, 0, 0);
        full.draw();
        glTranslated(-0.5, 0, 0);
        half.draw();
        glTranslated(-0.5, 0, 0);
        none.draw();
        glTranslated(-0.5, 0, 0);
        none.draw();
        glTranslated(-6 - local.x, -4 - local.y, -1);
        glPopMatrix();
        break;
       
    case 6:
        glPushMatrix();
        glTranslated(8 + local.x, 4 + local.y, -1);
        full.draw();
        glTranslated(-0.5, 0, 0);
        full.draw();
        glTranslated(-0.5, 0, 0);
        full.draw();
        glTranslated(-0.5, 0, 0);
        none.draw();
        glTranslated(-0.5, 0, 0);
        none.draw();
        glTranslated(-6 - local.x, -4 - local.y, -1);
        glPopMatrix();
       
        break;
    case 7:
        glPushMatrix();
        glTranslated(8 + local.x, 4 + local.y, -1);
        full.draw();
        glTranslated(-0.5, 0, 0);
        full.draw();
        glTranslated(-0.5, 0, 0);
        full.draw();
        glTranslated(-0.5, 0, 0);
        half.draw();
        glTranslated(-0.5, 0, 0);
        none.draw();
        glTranslated(-6 - local.x, -4 - local.y, -1);
        glPopMatrix();
       
        break;
    case 8:
        glPushMatrix();
        glTranslated(8 + local.x, 4 + local.y, -1);
        full.draw();
        glTranslated(-0.5, 0, 0);
        full.draw();
        glTranslated(-0.5, 0, 0);
        full.draw();
        glTranslated(-0.5, 0, 0);
        full.draw();
        glTranslated(-0.5, 0, 0);
        none.draw();
        glTranslated(-6 - local.x, -4 - local.y, -1);
        glPopMatrix();
       
        break;
    case 9:
        glPushMatrix();
        glTranslated(8 + local.x, 4 + local.y, -1);
        full.draw();
        glTranslated(-0.5, 0, 0);
        full.draw();
        glTranslated(-0.5, 0, 0);
        full.draw();
        glTranslated(-0.5, 0, 0);
        full.draw();
        glTranslated(-0.5, 0, 0);
        half.draw();
        glTranslated(-6 - local.x, -4 - local.y, -1);
        glPopMatrix();
        
        break;
    case 10:
        glPushMatrix();
        glTranslated( 10+ local.x, 5 + local.y,-1);
        full.draw();
        glTranslated(-0.5, 0, 0);
        full.draw();
        glTranslated(-0.5, 0, 0);
        full.draw();
        glTranslated(-0.5, 0, 0);
        full.draw();
        glTranslated(-0.5, 0, 0);
        full.draw();
        glTranslated(-12 -local.x, - 5-  local.y, -1);
        glPopMatrix();
        break;

    }
  
	/*glBegin(GL_QUADS);
    glVertex2f(4.0+local.x,3.0+local.y);
    glVertex2f(6.0+local.x, 3.0+local.y);
    glVertex2f(6.0+local.x, 5.0+local.y);
    glVertex2f(4.0+local.x, 5.0+local.y);
    glEnd();*/
}

void HUD::SetPos(Personaje& p)
{
    local = p.posicion;
}

void HUD::SetVida(Personaje& p)
{
   salud = p.GetSalud();

   
}





