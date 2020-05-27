#include "Mundo.h"
#include <stdio.h>
#include <iostream>

Mundo mundo;
float t;
float tiempo_juego = 0;
int i = 0;



//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void OnKeyboardUp(unsigned char key, int x, int y);
void MouseFunc(int button, int state, int x, int y);

int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutKeyboardUpFunc(OnKeyboardUp);
	glutMouseFunc(MouseFunc);
	mundo.Inicializa();

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}

void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	mundo.Dibuja();

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{

	//poner aqui el código de teclado
	mundo.TeclaDown(key);

	glutPostRedisplay();
}
void OnKeyboardUp(unsigned char key, int x_t, int y_t) {
	t = 0;
	mundo.TeclaUp(key);

	glutPostRedisplay();
}
void MouseFunc(int button, int state, int x, int y)
{
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) {
		mundo.ClickDch(state, x, y);
		printf("x=%d, y=%d\n", x, y);

	}
}
void glutKeyboardUpFunc(unsigned char key, int x_t, int y_t)
{
	mundo.TeclaUp(key);
	glutPostRedisplay();
}

void OnTimer(int value)
{
	//poner aqui el código de animacion
	mundo.Mueve(t);
	//temp
	

	if (tiempo_juego > 10) {
		i++;
		 float millis = tiempo_juego - 0.025*i;
		
		 float x = Tiempo::contaje(tiempo_juego, 5, millis);
	//if(	x == true)
		//std::cout << "ueeeeeeeeeeeeeee"<< std::endl;
	}
	tiempo_juego += 0.025;


	// se consigue lo mismo haciendo 0.025*i y cuando llegue a 5 sales 
	
	//no borrar eZtas lineas
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}