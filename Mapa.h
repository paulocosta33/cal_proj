/*
 * Mapa.h
 *
 *  Created on: 19/04/2016
 *      Author: up201404022
 */

#ifndef MAPA_H_
#define MAPA_H_
#include <iostream>
#include <string>
#include <stdlib.h>
#include <queue>
#include <list>
#include <limits>
#include <cmath>
#include "Graph.h"
#include <fstream>

using namespace std;

template <class T>
class Mapa
{
public:
	Mapa(){};
	void readFiles(){
	fstream nodes;
	string node_id;
	string node_lat;
	string node_lon;
	string lixo;
	nodes.open("ficheiro.txt");
	while (nodes)
	{
		getline(nodes, node_id, ';');
		getline(nodes, node_lat, ';');
		getline(nodes, node_lon, ';');
		getline(nodes, lixo);
		Vertex<T> node(node_id);
		node.info = node_id;
		node.latitude = atof(node_lat.c_str());
		node.longitude = atof(node_lon.c_str());
		cout << node.info << ";";//<< node.latitude << ";" << node.longitude;*/
	}
}

	private:
	//Graph grafo;
	//vector<Vertex<T>> nodes;
	//vector<Edge<T>> Edges;
	//vector<Vertex<T>*>  vertices;

	
};




#endif /* MAPA_H_ */
