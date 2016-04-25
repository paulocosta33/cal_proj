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
#include "Item.h"

using namespace std;

class Camiao
{
	public:
	 Camiao(int capacidadePeso);
	 vector <Item > items;
	 int getPeso();
	 int getId();
	 void setId(int id);
	 void loadDestinos();
	 vector <Item > getItems(){return items;}
	 vector <string> getDestinos_atuais();
	 vector <string> destinos_atuais;

	 private:
	 int capacidade_peso;
	 int id;
};

#endif /* CAMIAO_H_ */
