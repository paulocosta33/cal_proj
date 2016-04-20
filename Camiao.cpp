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
id = 0;
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

vector<string> Camiao::getDestinos_atuais()
{
	return destinos_atuais;
}

void Camiao::loadDestinos(){
	for(unsigned int x=0; x<items.size();x++ ){
		destinos_atuais.push_back(items[x]->dest);
	}

}
