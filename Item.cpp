/*
 * Item.cpp
 *
 *  Created on: 19/04/2016
 *      Author: up201404022
 */
#include "Item.h"

using namespace std;

Item::Item(string nome,int valor, int peso, int volume, string destino, int fatura)
{
	this->valor=valor;
	this->dest=destino;
	this->nome=nome;
	this->volume=volume;
	this->peso=peso;
	this->fatura=fatura;
	cout << "New Object\n";
}

string Item::getNome(){return nome;}
double Item::getValor(){return valor;}
string Item::getDest(){return dest;}
int Item::getFatura(){return fatura;}
int Item::getPeso(){return peso;}
int Item::getVolume(){return volume;}