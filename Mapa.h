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
#include <string>
#include <sstream>
using namespace std;

template <class T>
class Mapa
{
public:
    Mapa(){};
void readFiles(){
	fstream nodesfile;
	string node_id;
	string node_lat;
	string node_lon;
	string lixo;
	int counter =0;
	nodesfile.open("ficheiro.txt");
	while (nodesfile)
	{
		stringstream info;
		getline(nodesfile, node_id, ';');
		getline(nodesfile, node_lat, ';');
		getline(nodesfile, node_lon, ';');
		getline(nodesfile, lixo);
		Vertex<T> node(node_id);
		info<<counter;
		node.info=info.str();
		node.id = node_id;
		node.latitude = atof(node_lat.c_str());
		node.longitude = atof(node_lon.c_str());
		nodes.push_back(node);
		counter++;

	}
	fstream edgesfile;
	string edge_id;
	string edge_nome;
	string edge_sentido;
	edgesfile.open("ficheiro2.txt");
	while (edgesfile)
		{
			getline(edgesfile, edge_id, ';');
			getline(edgesfile, edge_nome, ';');
			getline(edgesfile, edge_sentido);
			Edge<T> edge;
			edge.id=edge_id;
			edge.nome=edge_nome;
			if (edge_sentido=="True")
			edge.duploSentido=true;
			else
			edge.duploSentido=false;

			edges.push_back(edge);

		}
}
void InicializeMap()
{
	for(int i=0 ; i< nodes.size();i++)
	{
		grafo.vertexSet.push_back(&nodes[i]);
	}
	cout<<"INFO: "<<grafo.vertexSet[7]->info;
	fstream street;
	string road_id;
	string node1_id;
	string node2_id;
	string lixo;
	street.open("ficheiro3.txt");
	while (street)
	{
		double distancialat;
		double distancialong;
		double distancia;
		getline(street,road_id,';');
		getline(street,node1_id,';');
		getline(street,node2_id,';');
		getline(street,lixo);
		for(int j=0; j <grafo.vertexSet.size(); j++)
		{
			for(int l=0; l<grafo.vertexSet.size(); l++)
			{
				if(grafo.vertexSet[j]->id==node1_id && grafo.vertexSet[l]->id==node2_id)
				{
					distancialat= grafo.vertexSet[j]->latitude - grafo.vertexSet[l]->latitude;
					distancialong= grafo.vertexSet[j]->longitude - grafo.vertexSet[l]->longitude;
					distancia= sqrt(pow(distancialat,2)+pow(distancialong,2));

					for (int k=0; k<edges.size();k++)
					{
						if(edges[k].id==road_id)
						{
							edges[k].dest=grafo.vertexSet[l];
							grafo.vertexSet[j]->addEdge(grafo.vertexSet[l],distancia*10000000);
							grafo.addEdge(grafo.vertexSet[j]->info,grafo.vertexSet[l]->info,distancia*10000000);

							/*if(edges[k].duploSentido)
							{
							edges[k].dest=grafo.vertexSet[l];
							grafo.vertexSet[l]->adj.push_back(edges[k]);
							grafo.addEdge(grafo.vertexSet[l]->info,grafo.vertexSet[l]->info,distancia);

							}*/

						}
					}
				}
			}
		}

	}

}

	Graph<string> grafo;
private:
	vector<Vertex<T> > nodes;
	vector<Edge<T> > edges;


	
};




#endif /* MAPA_H_ */
