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
using namespace std;


int main() {

	string node_s;
	string node_f;
	Mapa<string> m;
	Graph<string>* grafo= m.readfiles();
	grafo->floydWarshallShortestPath();

	string mp; //must pass point
	string ans;
	vector<string> must_points;
	cout << "Please select the starter node: \n";
	cin >> node_s;
	cout << "Please select the finish node: \n";
	cin >> node_f;
	cout << "Are there any must pass point? (yes/no)\n";
	cin >> ans;
	if(ans.compare("yes")==0)
	{
		while (mp.compare("done")!=0)
		{
			cin.clear();
			cout << "Please add the must pass points (done when you finnish)\n";
			cin >> mp;
			must_points.push_back(mp);

		}
		must_points.pop_back();
		cout << "The shortest path is: \n";
		grafo->getfloydWarshallPath(node_s,must_points[0]);
		for(unsigned int i = 1;i < must_points.size() -1;i++)
		{
			grafo->getfloydWarshallPath(must_points[i],must_points[i+1]);
		}
		grafo->getfloydWarshallPath(must_points[must_points.size()-1],node_f);

		for(unsigned int k = 0;k < grafo->path_res.size();k++)
				{
					cout << grafo->path_res[k] << " ";
				}
	}
	else
	{
		cout << "The shortest path is: \n";
		grafo->getfloydWarshallPath(node_s,node_f);
		for(unsigned int k = 0;k < grafo->path_res.size();k++)
		{
			cout << grafo->path_res[k] << " ";
		}
	}
	cout << endl;



}



