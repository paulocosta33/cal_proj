/*
 * Frota.h
 *
 *  Created on: 19/04/2016
 *      Author: up201404022
 */

#ifndef SRC_FROTA_H_
#define SRC_FROTA_H_
#include <iostream>
#include <string>
#include <stdlib.h>
#include <queue>
#include <list>
#include <limits>
#include <cmath>
using namespace std;

class Frota
{
	private:
	vector<Camiao> frota;
	int numeroCamioes=1;
	public:
	vector<Camiao> getFrota();
	void addCamiao(Camiao camiao );



};



#endif /* SRC_FROTA_H_ */
