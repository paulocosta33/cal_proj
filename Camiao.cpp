/*
 * Camiao.cpp
 *
 *  Created on: 19/04/2016
 *      Author: up201404022
 */

#include "Camiao.h"

using namespace std;

Camiao::Camiao(int capacidadePeso)
{
id = 0;
this->capacidade_peso=capacidadePeso;
}


int Camiao::getPeso()
{
return capacidade_peso;
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


