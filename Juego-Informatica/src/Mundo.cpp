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
	Enemigos.clear();
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
	float limx = Hombre.GetPosicion().x;
	float limy = Hombre.GetPosicion().y;
	if (limy < 0)
		limy = 0;
	if (limx > 1)
		limx = 1;

	glEnable(GL_LIGHTING);
	gluLookAt(limx, limy, z_ojo,  // posicion del ojo
		limx, limy, 0.0, // hacia que punto mira  (donde este el personaje, quizas crear una clase camara) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)

//aqui es donde hay que poner el codigo de dibujo


	glColor3ub(255, 255, 0);
	glTranslated(0, 1, 0);
	Hombre.Dibuja();			//Dibuja el cuadrado que representa al hombre


	Enemigos.Dibuja();

	
	glRotatef(180, 0, 1, 0);
	glTranslated(0, 0, 0.0051);
	Mapa.Dibuja();
	glTranslated(0, 0, -0.0051);
	glTranslated(0, 0, -1);
	Fondo.Dibuja();
	glTranslated(0, 0, 1);
	glTranslated(0, 0, -0.5);
	FondoCueva.Dibuja();
	glTranslated(0, 0, 0.5);
	glRotatef(-180, 0, 1, 0);
	glTranslated(0, 0, 70);

	glTranslated(0, 0, -70);
	
	//Para ver collider
	/*
	glRotatef(180, 0, 1, 0);
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
	InteraccionListas::Collision(Enemigos, Colliders),
		InteraccionListas::Collision(Enemigos, Hombre);
	InteraccionListas::Collision(Colliders, Hombre.GetCarcaj());
	InteraccionListas::Collision(Enemigos, Hombre.GetCarcaj());
	InteraccionListas::DemasiadoLejos(Hombre, Hombre.GetCarcaj());


	hud.SetPos(Hombre);
	hud.SetVida(Hombre);
	hud.Dibuja();





}

void Mundo::Mueve(float t)
{
	Hombre.Mueve(t);

	Enemigos.Mueve(t);
	Enemigos.Persigue(Hombre);

	Enemigos.ataca(Hombre);
	Enemigos.Muerte();
	if (Enemigos[0].GetSalud() <= 3 && contador_boss == 0) {
		Enemigos.AddElem(new Bonus(-266.4, 14));
		Enemigos.AddElem(new Bonus(-284.6, 14));
		contador_boss += 1;
	}

}

void Mundo::Inicializa()
{
	//---------------Inicializamos lista de objetos y enemigos-------
	Enemigos.AddElem(new BossFinal(-275, 15));
	Enemigos.AddElem(new Patrullero(-20, 12, -17, -26));                //    -16.4    10.4 - 28.3 - 5
	Enemigos.AddElem(new Bonus(-60, 14));                            //    -57      12.2 - 68.7 - 5
	Enemigos.AddElem(new Artillero(-100, 13));                        //-80.8    12.2 - 106.7 - 5
	Enemigos.AddElem(new Patrullero(-125, 12, -124, -128));            //  -123     10.2 - 141 - 5
	Enemigos.AddElem(new Croco(-133, 12, -129, -137));
	Enemigos.AddElem(new Bonus(-145, 22));                        //    -140.7   20.8 - 154 - 5
	Enemigos.AddElem(new Artillero(-177, 22));                    //    - 169.5   20.8 - 179.5 - 5
	Enemigos.AddElem(new Artillero(-233, 9));       //    -230     7.8 - 297 - 5
	Enemigos.AddElem(new Pinchos(-88.63, 12.8, 3, 2));
	Enemigos.AddElem(new Pinchos(-126, 0, 212, 4));
	Enemigos.AddElem(new Pinchos(10, 5, 2, 30));
	Enemigos.AddElem(new Pinchos(7.5, -10, 10, 2));
	//---------------Hombre y variables--------------
	Hombre.posicion.x = 0;
	Hombre.posicion.y = 0;
	Hombre.SetSalud(10);
	Hombre.endgame = false;
	contador_boss = 0;
	//--------------------------------------------------------
	x_ojo = Hombre.GetPosicion().x;
	y_ojo = 10 + Hombre.GetPosicion().y;
	z_ojo = -20;
	//---------------------Sprites---------------------------------
	Mapa.Inicializa("\Data_Game/Nivel1/Mapa.png", 148, 0.5, 344, 87.5);
	Fondo.Inicializa("\Data_Game/Nivel1/Fondo.png", 148, 0.5, 344, 87.5);
	FondoCueva.Inicializa("\Data_Game/Nivel1/FondoCueva.png", 148, 0.5, 344, 87.5);
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


	Hombre.TeclaDown(key);



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