//============================================================================
// Name        : cal_proj.cpp
// Author      : paulo costa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Graph.h"
#include <stdio.h>
#include <iostream>
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

	string node_s;
	string node_f;

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

	g.dijkstraShortestPath(a.info);

	cout << "Please select the starter node: \n";
	cin >> node_s;
	cout << "Please select the finish node: \n";
	cin >> node_f;
	cout << "The shortest path is: \n";

	g.getPath(node_s,node_f);
	for(unsigned int k = 0;k < g.path_res.size();k++)
	{
		cout << g.path_res[k] << " ";
	}

}



