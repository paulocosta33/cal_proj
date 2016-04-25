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
   	Item(string nome,int valor, int peso, string destino, int fatura);
   	Item(){
   		peso = 0;
   		fatura = 0;
   		valor = 0;
   	};
 	string dest;
	string nome;
   	double valor;
   	int fatura;
   	int peso;

   private:

};


#endif /* SRC_ITEM_H_ */
