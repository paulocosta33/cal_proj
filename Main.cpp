//============================================================================
// Name        : cal_proj.cpp
// Author      : paulo costa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Graph.h"
#include "Frota.h"
#include <stdio.h>
#include <iostream>
#include "Mapa.h"
#include "mapa2.h"
using namespace std;

int main() {

	int myints[] = {10,20,30,5,15};
	vector<int> v(myints,myints+5);

	make_heap (v.begin(),v.end()); //orders high-low
	pop_heap (v.begin(),v.end()); //puts highest elem in last
	v.pop_back(); //pops last elem
	//cout << v.front() << endl; //heap max
	v.push_back(99);
	push_heap (v.begin(),v.end());

	//adicionar estaticos
	//algoritmo path camiao
	//file reader
	//items recebidos nos nos, total da compra

	Item item1("cadeira",20,2,10,"f",0001);
	Item item2("quadro",70,2,10,"c",0002);
	Item item3("mesa",20,2,10,"b",0003);
	Item item4("cofre",35,2,10,"e",0004);
	Item item5("cadeira",20,2,10,"c",0005);

	Camiao c1(400,7);
	Camiao c2(400,7);
	Camiao c3(400,7);
	Camiao c4(1500,15);
	Camiao c5(1500,15);
	Camiao c6(1500,15);
	Camiao c7(12000,40);
	Camiao c8(12000,40);
	Camiao c9(12000,40);

	vector<Camiao *> frota;
	//frota.push_back(&c1);
	Frota fleet(frota);
	fleet.addCamiao(c1);
	fleet.addCamiao(c2);
	fleet.addCamiao(c3);
	fleet.addCamiao(c4);
	fleet.addCamiao(c5);
	fleet.addCamiao(c6);
	fleet.addCamiao(c7);
	fleet.addCamiao(c8);
	fleet.addCamiao(c9);

	c1.getItems().push_back(&item1);
	c1.getItems().push_back(&item2);
	c1.getItems().push_back(&item3);
	c1.getItems().push_back(&item4);
	c1.getItems().push_back(&item5);



	string node_s;
	string node_f;
/*
	//info
	string x1 = "a";
	string x2 = "b";
	string x3 = "c";
	string x4 = "d";
	string x5 = "e";
	string x6 = "f";

	//vertex
	Vertex<string> a(x1);
	Vertex<string> b(x2);
	Vertex<string> c(x3);
	Vertex<string> d(x4);
	Vertex<string> e(x5);
	Vertex<string> f(x6);

	//edge
	Edge<string> ab(&b,7);
	Edge<string> ad(&d,5);
	Edge<string> de(&e,5);
	Edge<string> bc(&c,2);
	Edge<string> be(&e,1);
	Edge<string> ef(&f,3);
	Edge<string> cf(&f,3);

	vector<Vertex<string>*> vec; //vec is vertexSet
	vec.push_back(&a); //0
	vec.push_back(&b); //1
	vec.push_back(&c); //2
	vec.push_back(&d); //3
	vec.push_back(&e); //4
	vec.push_back(&f); //5


	Graph<string> g(vec);

	g.addEdge(a.info,b.info,7);
	g.addEdge(a.info,d.info,5);
	g.addEdge(d.info,e.info,5);
	g.addEdge(b.info,c.info,2);
	g.addEdge(b.info,e.info,1);
	g.addEdge(e.info,f.info,3);
	g.addEdge(c.info,f.info,3);
*/
	Mapa2<string> m2;
	Graph<string>* grafo= m2.readfiles();
	cout << grafo->vertexSet[0]->adj[0].weight;
	//grafo->dijkstraShortestPath(grafo->vertexSet[1]->info);

	cout << "Please select the starter node: \n";
	cin >> node_s;
	cout << "Please select the finish node: \n";
	cin >> node_f;
	cout << "The shortest path is: \n";

	grafo->dijkstraShortestPath(node_s);
	grafo->getPath(node_s,node_f);
	for(unsigned int k = 0;k < grafo->path_res.size();k++)
	{
		cout <<grafo->path_res[k] << " ";
	}

	cout << "\n";
	cout << "Shortest path with all the destinations: \n";




}



