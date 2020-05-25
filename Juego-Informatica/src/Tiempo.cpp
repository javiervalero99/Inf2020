#include "Tiempo.h"


bool Tiempo::contaje(float t, float margen,float millis)
{
	
	bool fin_contaje = false;
	
	float counter = 0;

	 counter = t - millis;



	if (counter > margen) {
		fin_contaje = true;

	}

	return fin_contaje;

	
}
