/*
 * Camiao.h
 *
 *  Created on: 19/04/2016
 *      Author: up201404022
 */

#ifndef CAMIAO_H_
#define CAMIAO_H_
#include <iostream>
#include <string>
#include <stdlib.h>
#include <queue>
#include <list>
#include <limits>
#include <cmath>

using namespace std;

class Camiao
{
	public:
	 Camiao(int capacidadeVolume,int capacidadePeso);
	 int getPeso();
	 int getVolume();
	 int getId();
	 void setId(int id);

	private:
	 int capacidade_volume;
	 int capacidade_peso;
	 int id;
};

#endif /* CAMIAO_H_ */
