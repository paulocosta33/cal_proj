/*
 * Frota.cpp
 *
 *  Created on: 19/04/2016
 *      Author: up201404022
 */
#include "Frota.h"
using namespace std;

Frota::Frota()
{
	addCamiao(Camiao(400,7));
	addCamiao(Camiao(400,7));
	addCamiao(Camiao(400,7));
	addCamiao(Camiao(1500,15));
	addCamiao(Camiao(1500,15));
	addCamiao(Camiao(1500,15));
	addCamiao(Camiao(12000,40));
	addCamiao(Camiao(12000,40));
	addCamiao(Camiao(12000,40));
}

void Frota::addCamiao(Camiao camiao)
	{
		camiao.setId(numeroCamioes);
		numeroCamioes++;
		frota.push_back(camiao);
	}
vector<Camiao> Frota::getFrota()
{
return frota;
}
