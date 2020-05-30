#include "Mundo.h"
#include "glut.h"

#define route "\Data_Game/Game_Parameters.txt"
using namespace std;
Mundo::Mundo()
{
	x_ojo = y_ojo = z_ojo = 0;
}

Mundo::~Mundo()
{
}

void Mundo::RotarOjo()
{
	float dist = sqrt(x_ojo * x_ojo + z_ojo * z_ojo);
	float ang = atan2(z_ojo, x_ojo);
	ang += 0.05f;
	x_ojo = dist * cos(ang);
	z_ojo = dist * sin(ang);
}

void Mundo::Dibuja()
{

	glEnable(GL_LIGHTING);
	gluLookAt(Hombre.GetPosicion().x, Hombre.GetPosicion().y, z_ojo,  // posicion del ojo
		Hombre.GetPosicion().x, Hombre.GetPosicion().y, 0.0, // hacia que punto mira  (donde este el personaje, quizas crear una clase camara) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

//aqui es donde hay que poner el codigo de dibujo
//dibujo del suelo

	glColor3ub(255, 255, 0);
	glTranslated(0, 1, 0);
	Hombre.Dibuja();			//Dibuja el cuadrado que representa al hombre


	enemigo.Dibuja();

	glRotatef(180, 0, 1, 0);
	glTranslated(0, 0, 1);
	Mapa.Dibuja();
	glTranslated(0, 0, 1);
	glRotatef(-180, 0, 1, 0);
	glTranslated(0, 0, 70);

	glTranslated(0, 0, -70);

	//Para ver collider
	/*glRotatef(180, 0, 1, 0);
	glTranslated(0, 0, -4);
	Mapa.Dibuja();
	glTranslated(0, 0, 4);
	glRotatef(-180, 0, 1, 0);
	glTranslated(0, 0, 70);
	Fondo.Dibuja();
	glTranslated(0, 0, -70);
	Colliders.Dibuja();
	*/
	InteraccionListas::Collision(Hombre, Colliders);
	InteraccionListas::Collision(enemigo, Colliders);
	//bool valid9 = CollisionMundo::Collision(enemigo, Pared2);
	/*if (valid9 == false)
	{
		enemigo.cae = true;
		enemigo.j++;
	}*/


	hud.SetPos(Hombre);
	hud.Dibuja();


	artillero.Dibuja();
	if (fire);
	mortero.Dibuja();
}

void Mundo::Mueve(float t)
{
	Hombre.Mueve(t);

	enemigo.Mueve(t);
	enemigo.Persigue(Hombre);

	// 
	fire = artillero.ataca(Hombre);
	if(fire)
mortero.Mueve(t);
}


void Mundo::Inicializa()
{

	//---------------Spamear en cualquier parte del mapa--------------
	Hombre.posicion.x = -11;
	Hombre.posicion.y = 10.0;
	//--------------------------------------------------------
	x_ojo = Hombre.GetPosicion().x;
	y_ojo = 10 + Hombre.GetPosicion().y;
	z_ojo = -20;
	//---------------------Sprites---------------------------------

	Mapa.Inicializa("\Data_Game/Nivel1/Mapa.png", 69.3, 4.3, 140, 20);
	Fondo.Inicializa("\Data_Game/Nivel1/Fondo.png", -60, 4.3, 450, 90);
	//ETSIDI::playMusica("\Crimson_Nights_Track_02.mp3", true);
	//--------------------Colliders--------------------------------
	Leer_Fichero(route);


}

void Mundo::TeclaUp(unsigned char key)
{
	Hombre.TeclaUp(key);
}
void Mundo::TeclaDown(unsigned char key)
{
	//printf("%d\n", key);

	Hombre.TeclaDown(key);


	mortero.SetPos(artillero.GetPosicion());
}


void Mundo::Leer_Fichero(const char direction[])
{
	int m = 0;
	char file[100];
	fstream fichero(direction, ios::in);
	for (int i = 0; !fichero.eof(); i++) {
		fichero.getline(file, 100);
		if (!strcmp(file, "Begin_Collider")) {
			for (int j = 0; strcmp(file, "End_Collider"); j++) {

				fichero.getline(file, 100);
				if (strcmp(file, "End_Collider")) {
					ColliderMap* p = new ColliderMap();
					Leer_Collider(file, p);
					Colliders.AddCollider(p);
				}
			}
		}
	}
	fichero.close();
}

bool Mundo::Leer_Collider(char string[], ColliderMap* p)
{
	int parametro = 0;
	int numeros[7];
	int j = 0;
	int k = 0;
	int pointer = 0;
	bool negativo = false;
	bool decimales = false;
	int posicionpunto;

	float num_final;
	for (int i = 0; string[i] != '\0'; i++) {
		num_final = 0;
		pointer = i;
		if ((string[i] != ' ') && (string[i] != '-')) {
			for (j = i; (string[j] != ' ') && (string[j] != '\0'); j++) {
				if ((j - i) > 6) {
					break;
				}
				if (string[j] != '.')
					numeros[pointer - i] = (static_cast<int>(string[j]) - 48);
				else {
					decimales = true;
					posicionpunto = j;
					pointer--;
				}
				pointer++;
			}
			j--;
			pointer--;
			for (k = pointer; k > i - 1; k--)
				num_final += numeros[k - i] * pow(10, (pointer - i) - (k - i));

			if (decimales == true)
				num_final /= pow(10, j - posicionpunto);

			if (negativo == true)
				num_final = -num_final;

			switch (parametro) {
			case 0:
				p->Arriba.x = num_final;
				break;
			case 1:
				p->Arriba.y = num_final;
				break;
			case 2:
				p->Abajo.x = num_final;
				break;
			case 3:
				p->Abajo.y = num_final;
				break;
			}
			parametro++;
			i = j;
			j = 0;
			decimales = false;
			for (int m = 0; m < 3; m++) {
				numeros[m] = 0;
			}
			if (parametro == 4) {
				return true;
			}

		}
		if (string[i] == '-')
			negativo = true;
		else
			negativo = false;
	}
	return false;
}





