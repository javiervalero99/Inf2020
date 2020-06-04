#include "BossFinal.h"

BossFinal::BossFinal(): Ataque("\Data_Game/Enemigo_Boss/ataque.png", 7, 1, 100), Die("\Data_Game/Enemigo_Boss/die.png", 7, 2, 100), Patada("\Data_Game/Enemigo_Boss/patada.png", 6, 1, 100), Patada2("\Data_Game/Enemigo_Boss/patada2.png", 6, 1, 100), Puñetazo("\Data_Game/Enemigo_Boss/puñetazo.png", 5, 1, 100), Run("\Data_Game/Enemigo_Boss/run.png", 6, 1, 100), Statico("\Data_Game/Enemigo_Boss/statico.png", 2, 1, 250), Torbellino("\Data_Game/Enemigo_Boss/torbellino.png", 4, 1, 200), Jump("\Data_Game/Enemigo_Boss/jump.png", 3, 1, 100)
{
	Ataque.setSize(4, 4);
	Ataque.setCenter(2, 1);
	Die.setSize(4, 4);
	Die.setCenter(2, 1);
	Patada.setSize(4, 4);
	Patada.setCenter(2, 1);
	Patada2.setSize(4, 4);
	Patada2.setCenter(2, 1);
	Puñetazo.setSize(4, 4);
	Puñetazo.setCenter(2, 1);
	Run.setSize(4, 4);
	Run.setCenter(2, 1);
	Statico.setSize(4, 4);
	Statico.setCenter(2, 1);
	Torbellino.setSize(4, 4);
	Torbellino.setCenter(2, 1);
	Jump.setSize(6,6);
	Jump.setCenter(3, 2);
	//Control del movimiento.
	posicion.x = -25.0f;
	posicion.y = 8+1.3/2;
	salud = 10;
	//Control de estados.
	estoy_statico = true;
	EntrarModoDiablo = false;
	estoy_muriendo=false;
	estoy_ataque1=false;
	estoy_ataque2=false;
	estoy_ataque3=false;
	estoy_ataqueesp=false;
	contador = 0;
	n = 0;
	//Setear Daño de ataques.
	for (int i = 1; i < 4; i++)		//Daño ataques 1, 2, 3.
	{
		DañoAtaque[i] = -i;
	}
	DañoAtaque[0] = -4;				//Daño ataque especial.
}

BossFinal::~BossFinal()
{

}

bool BossFinal::ataca(Personaje &p)
{
	int valor;				//Valor para lanzar cada ataque.
	double TiempoRetardo=GetTickCount();

	if (salud > 0 && ComenzarCombate(p)==true)
	{
		if ((TiempoRetardo-TiempoEjecucion) > 1000)
		{	
				switch (valor = ETSIDI::lanzaDado(4, 1))
				{
					case 1:
					{
						if (((TiempoRetardo - TiempoEjecucion) > 2000) && (estoy_ataque2==false) && (estoy_ataque3==false) && (estoy_ataqueesp==false))
						{
							estoy_ataque1 = true;
							Ataque.setState(0, false);
							n++;
							TiempoEjecucion = GetTickCount();
						}
						break;
					}
					case 2:
					{
						if (((TiempoRetardo - TiempoEjecucion) > 2000) && (estoy_ataque1 == false) && (estoy_ataque3 == false) && (estoy_ataqueesp == false))
						{
							estoy_ataque2 = true;
							Patada.setState(0, false);
							TiempoEjecucion = GetTickCount();
						}

						break;
					}
					case 3:
					{
						if (((TiempoRetardo - TiempoEjecucion) > 2000) && (estoy_ataque2 == false) && (estoy_ataque2 == false) && (estoy_ataqueesp == false))
						{
							estoy_ataque3 = true;
							Puñetazo.setState(0, false);
							n++;
							TiempoEjecucion = GetTickCount();
						}
						break;
					}
					default:
						break;
				}
				
				if (n>=10)
				{
					estoy_ataqueesp = true;
					Torbellino.setState(0, false);
					validacionAsignacion = true;
					n = 0;
					std::cout << "Se ha lanzado el ataque especial" << std::endl;
					TiempoEjecucion = GetTickCount();
				}
				
		}
		
	}
	return true;
}

bool BossFinal::SetSalto(Personaje& p)
{
	if (((p.GetPosicion().y - posicion.y) > 3) && DistanciaPlayer(p) > 5)
	{

		velocidad.y = 20;
		return true;
	}
	return false;
}

void BossFinal::ModoDiablo()
{
	if (GetSalud() == 3 && !EntrarModoDiablo)
	{
		salud = 10;
		for (int i = 0; i < 4; i++)
		{
			DañoAtaque[i] *= 2;
		}
		velocidad.x *= 2;
		EntrarModoDiablo = true;
	}
}

void BossFinal::Dibuja()
{
	estado_ataque1 = Ataque.getState();
	estado_ataque2 = Patada.getState();
	estado_ataque3 = Puñetazo.getState();
	estado_ataque_esp = Torbellino.getState();
	estado_jump = Jump.getState();
	estado_die = Die.getState();

	if (estado_ataque1 == 2 && estoy_ataque1 == true)
	{
		validacionAsignacion = true;

	}
	if (estado_ataque1 == 5 && estoy_ataque1 == true)
	{
		validacionAsignacion = false;

	}
	if (estado_ataque2 == 2 && estoy_ataque2 == true)
	{
		validacionAsignacion = true;
	}
	if (estado_ataque2 == 4 && estoy_ataque2 == true)
	{
		validacionAsignacion = false;
	}
	if (estado_ataque3 == 2 && estoy_ataque3 == true)
	{
		validacionAsignacion = true;
	}

	
	


	if (estado_ataque1==6 && estoy_ataque1==true)
	{
		estoy_ataque1 = false;
		std::cout << "Ataque 1" << std::endl;
		std::cout << "El valor de n es" << n << std::endl;
	}
	if (estado_ataque2 == 5 && estoy_ataque2==true)
	{
		estoy_ataque2 = false;
		std::cout << "Ataque 2" << std::endl;
		std::cout << "El valor de n es" << n << std::endl;
	}
	if (estado_ataque3 == 4 && estoy_ataque3==true)
	{
		estoy_ataque3 = false;
		validacionAsignacion = false;						//La validacion de asignacion se pone a false aqui porque justo termina en este sprite para este caso.
		std::cout << "Ataque 3" << std::endl;
		std::cout << "El valor de n es" << n << std::endl;
	}
	if (estado_ataque_esp == 3 && estoy_ataqueesp==true)
	{
		estoy_ataque1 = false;
		contador++;
	}
	if (estado_die == 13)
	{
		estado_die = false;
	}
	if (estado_jump == 2)
	{
		Jump.setState(2, true);
	}
	if (contador == 30)
	{
		estoy_ataqueesp = false;
		contador = 0;
		validacionAsignacion = false;
	}
	glPushMatrix();
	glTranslated(posicion.x, posicion.y, 0);
	   	 
	
	//ZONA SPRITES
	if ((estoy_statico==true))//ESTA CORRIENDO
	{
		Statico.draw();
	}
	if ((estoy_statico == false) && (velocidad.x != 0) && (estoy_ataque1==false) && (estoy_ataque2 == false) && (estoy_ataque3 == false) && (estoy_ataqueesp == false) && (estoy_muriendo == false) && (velocidad.y==0))//ESTA CORRIENDO
	{
		Run.draw();
	}
	if ((estoy_statico == false) && (estoy_ataque1 == true) && (estoy_ataque2 == false) && (estoy_ataque3 == false) && (estoy_ataqueesp == false) && (estoy_muriendo == false) && (velocidad.y==0))
	{
		Ataque.draw();
	}
	if ((estoy_statico == false) && (estoy_ataque1 == false) && (estoy_ataque2 == true) && (estoy_ataque3 == false) && (estoy_ataqueesp == false) && (estoy_muriendo == false) && (velocidad.y == 0))
	{
		Patada.draw();
	}
	if ((estoy_statico == false) && (estoy_ataque1 == false) && (estoy_ataque2 == false) && (estoy_ataque3 == true) && (estoy_ataqueesp == false) && (estoy_muriendo == false) && (velocidad.y == 0))
	{
		Puñetazo.draw();
	}
	if ((estoy_statico == false) && (estoy_ataque1 == false) && (estoy_ataque2 == false) && (estoy_ataque3 == false) && (estoy_ataqueesp == true) && (estoy_muriendo == false) && (velocidad.y == 0))
	{
		Torbellino.draw();
	}
	if ((estoy_statico == false) && (estoy_ataque1 == false) && (estoy_ataque2 == false) && (estoy_ataque3 == false) && (estoy_ataqueesp == false) && (estoy_muriendo == true) && (velocidad.y == 0))
	{
		Die.draw();
	}
	if (velocidad.y!=0)
	{
		Jump.draw();
	}
	glTranslated(-posicion.x, -posicion.y, 0);
	glPopMatrix();

	if (velocidad.x > 0.01)
	{
		Run.flip(false, false);
		Ataque.flip(false, false);
		Die.flip(false, false);
		Ataque.flip(false, false);
		Patada.flip(false, false);
		Puñetazo.flip(false, false);
		Torbellino.flip(false, false);
		Jump.flip(false, false);
	}
	else if (velocidad.x < -0.01)
	{
		Run.flip(true, false);
		Ataque.flip(true, false);
		Die.flip(true, false);
		Ataque.flip(true, false);
		Patada.flip(true, false);
		Puñetazo.flip(true, false);
		Torbellino.flip(true, false);
		Jump.flip(true, false);
	}
}

void BossFinal::Mueve(float t)
{
	posicion.x += velocidad.x * 0.025 + (1 / 2) * aceleracion.x * pow(0.025, 2);
	velocidad.x -= aceleracion.x * 0.025;
	//salto
	velocidad.y -= aceleracion.y * 0.025;
	posicion.y += velocidad.y * 0.025 - (1 / 2) * aceleracion.y * pow(0.025, 2);

	if (cae == true) {
		aceleracion.y = 30;
		cae = false;
	}

	
		Puñetazo.loop();

		Patada.loop();
	
		Ataque.loop();

		Torbellino.loop();
	
		Jump.loop();
	
		Run.loop();
	
		Statico.loop();
}

void BossFinal::Persigue(Personaje& p)
{
	// si no hay nada en medio(las disntacias  otra cosa no es mayor ) lo persigue
		
	SetSalto(p);
		if (ComenzarCombate(p))
		{
			estoy_statico = false;
			// to do - preparar la matematica de pserseguir
			float mov = p.posicion.x - posicion.x;
			if (mov < 0)
			{
				velocidad.x = -4.5;
			}
			else
				velocidad.x = 4.5;
		}
		else
		{
			estoy_statico = true;
			velocidad.x = 0.0f;
		}
	
}

bool BossFinal::ComenzarCombate(Personaje& p)
{
	if ((DistanciaPlayer(p)<=5) || estoy_statico==false)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}



