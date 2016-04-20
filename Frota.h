/*
 * Frota.h
 *
 *  Created on: 19/04/2016
 *      Author: up201404022
 */

#ifndef FROTA_H_
#define FROTA_H_
#include <iostream>
#include <string>
#include <stdlib.h>
#include <queue>
#include <list>
#include <limits>
#include <cmath>
#include "Camiao.h"
using namespace std;

class Frota
{
	private:
		int numeroCamioes;
	public:
		vector<Camiao *> frota;
		vector<Camiao *> getFrota();
		void addCamiao(Camiao camiao );
		Frota(vector<Camiao *> frota);
};



#endif /* FROTA_H_ */
