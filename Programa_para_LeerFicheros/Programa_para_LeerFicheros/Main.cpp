#include <iostream>
#include <fstream>
#include <math.h>
#include "Collider.h"
#include "Enemigo.h"

#define route "\Data_Game/Game_Parameters.txt"

void Leer_Fichero(const char[]);
bool Leer_Collider(char[],Collider *p);
using namespace std;
void main() {
	Leer_Fichero(route);

}

void Leer_Fichero(const char direction[])
{
	char file[100];
	fstream fichero(direction, ios::in);
	for (int i = 0; !fichero.eof(); i++) {
		fichero.getline(file, 100);
		if (!strcmp(file,"Begin_Collider")){
			for (int j = 0; strcmp(file, "End_Collider"); j++) {
				fichero.getline(file, 100);
				Collider* p = new Collider;
				Leer_Collider(file, p);
				delete p;
			}
		}
	}
}

bool Leer_Collider(char string[], Collider *p)
{
	int parametro=0;
	int numeros[4];
	int j = 0;
	int k = 0;
	bool negativo = false;



	int num_final;
	for (int i = 0; string[i] != '\0'; i++) {
		num_final = 0;
		if ((string[i] != ' ')&&(string[i]!='-')) {
			for (j = i; (string[j] != ' ')&&(string[j]!='\0'); j++) {
				if ((j - i) > 3) {
					break;
				}
				numeros[j - i] = (static_cast<int>(string[j]) - 48);

			}
			j--;
			for (k = j; k > i - 1; k--) {
				num_final += numeros[k - i] * pow(10, (j-i)-(k-i));
			}
			if (negativo == true) {
				num_final = -num_final;
			}
			switch (parametro){
			case 0:
				p->Arriba.x =num_final;
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
