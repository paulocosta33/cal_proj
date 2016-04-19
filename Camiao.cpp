/*
 * Camiao.cpp
 *
 *  Created on: 19/04/2016
 *      Author: up201404022
 */

#include "Camiao.h"

using namespace std;

Camiao::Camiao(int capacidadePeso,int capacidadeVolume)
{
this->capacidade_peso=capacidadePeso;
this->capacidade_volume=capacidadeVolume;
}


int Camiao::getPeso()
{
return capacidade_peso;
}

int Camiao::getVolume()
{
return capacidade_volume;
}
void Camiao::setId(int id)
{
	this->id=id;
}

int Camiao::getId()
{
	return id;
}
