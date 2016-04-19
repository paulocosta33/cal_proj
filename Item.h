/*
 * Item.h
 *
 *  Created on: 19/04/2016
 *      Author: up201404022
 */

#ifndef SRC_ITEM_H_
#define SRC_ITEM_H_
#include <iostream>
#include <string>
#include <stdlib.h>
#include <queue>
#include <list>
#include <limits>
#include <cmath>
using namespace std;


class Item
{
   public:
   	string getNome();
   	double getValor();
   	string getDest();
   	int getFatura();
  	int getPeso();
  	int getVolume();
   	Item(string nome,int valor, int peso, int volume, string destino, int fatura);

   private:
   	string nome;
   	double valor;
   	string dest;
   	int fatura;
   	int volume;
   	int peso;
};


#endif /* SRC_ITEM_H_ */
