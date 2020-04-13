#include "Personaje.h"
#include "Imagen.h"

class Mundo
{
public: 
	void Tecla(unsigned char key);
	void Inicializa();
	void RotarOjo();
	void Mueve(float t);
	void Dibuja();
	void TeclaUp(unsigned char key);
	void TeclaDown(unsigned char key);

	float x_ojo;
	float y_ojo;
	float z_ojo;
	Personaje Hombre;
	Imagen Goku;
	Imagen PutoSofrito;
};
