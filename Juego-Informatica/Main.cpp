#include "glut.h"
//Hola
void Dibujar() {

	glFlush();
}

int main(int argc, char* args[]) {
	glutInit(&argc, args);

	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(800, 60);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Trabajo de informatica.");	

	glutDisplayFunc(Dibujar);
	glutMainLoop();

	return 0;
}