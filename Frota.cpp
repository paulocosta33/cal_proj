/*
 * Frota.cpp
 *
 *  Created on: 19/04/2016
 *      Author: up201404022
 */
#include "Frota.h"
using namespace std;

Frota::Frota(vector<Camiao *> f)
{
	numeroCamioes =0;
	frota = f;
}

void Frota::addCamiao(Camiao camiao)
	{
		//camiao.setId(numeroCamioes);
		numeroCamioes++;
		frota.push_back(&camiao);
	}
vector<Camiao *> Frota::getFrota()
{
	return frota;
}
