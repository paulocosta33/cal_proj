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
#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "menu.h"
using namespace std;

template <typename T>
string NumberToString ( T Number )
{
	stringstream ss;
	ss << Number;
	return ss.str();
}

/*void menuFrota(Frota* frota)
{
	int opcao;
	cout<< "#========================# \n";
	cout<< "| 1- Ver Frota           |\n";
	cout<< "| 2- Adicionar Camiao    | \n";
	cout<< "| 3- Remover Camiao      |\n";
	cout<< "| 4- Retroceder          |\n";
	cout<< "#========================# \n";
	cin >> opcao;

	if(opcao==1)
	{
		int opcao2;
		cout<< "#========================# \n";
		for (int i=0; i<frota->frota.size();i++)
		{
			cout<<"| id:"<<frota->frota[i]->getId()<<"; Capacidade :"<<frota->frota[i]->capacidade_peso<< "\n";
			cout<<"| Items: ";
			for  (int j=0; j<frota->frota[i]->items.size();j++)
			{
				cout<<frota->frota[i]->items[j].nome<< ";";
			}
			cout<< "\n";
		}
		cout<< "#========================# \n";
		cin>>opcao2;
		if(opcao2==0)
		{
			menuFrota(frota);
		}
	}
	if(opcao==2)
	{
		int capacidade;
		cout<<"Capacidade do Camiao: ";
		cin >> capacidade;
		frota->addCamiao(new Camiao(capacidade));
		menuFrota(frota);

	}
	if(opcao==3)
	{
		int id;
		cout<<"Id camiao a remover:  ";
		cin>>id;
		for(int i=0;i<frota->frota.size();i++)
		{
			if(id==frota->frota[i]->getId())
			{
				frota->frota.erase(frota->frota.begin()+i);
			}
		}
		menuFrota(frota);
	}
	if(opcao==4)
	{
		menu1(frota);
	}

}

void menu1(Frota* frota)
{
int opcao;
cout<< "#========================# \n";
cout<< "| 1- Gerir Frota         |\n";
cout<< "| 2- Gerir Items         | \n";
cout<< "| 3- Carregar e lancar   |\n";
cout<< "| 4- Ver Mapa            |\n";
cout<< "| 5- Sair                |\n";
cout<< "#========================# \n";
cin >> opcao;
if(opcao==1)
{
menuFrota(frota);
}
if(opcao==5)
{
return;
}
}

*/
int main() {

	//Item item1("cadeira",20,2,"1110698247",0001);
	//Item item2("quadro",70,2,"1110698276",0002);

	/*string name;
	int value;
	string destination;
	int weight;
	int receipt;

	Camiao c1(400);
	string temp = "yes";

	while(temp.compare("yes")==0 && cin.good())
	{
		cin.clear();
		cout << "Would you like to add a new item? (yes/no)\n";
		cin >> temp;
		if(temp.compare("no")==0) break;
		cout << "What will be the name of the item? \n";
		cin >> name;
		cout << "What will be the value of the item? \n";
		cin >> value;
		cout << "What will the weight of the item be? \n";
		cin >> weight;
		cout << "What will be the id of the destination? \n";
		cin >> destination;
		cout << "What will be the receipt number? \n";
		cin >> receipt;
		Item item1(name,value,weight,destination,receipt);
		c1.items.push_back(item1);

	}


	string node_s;
	string node_f;

	grafo->floydWarshallShortestPath();

	string mp; //must pass point
	string ans;
	vector<string> must_points;
	cout << "Please select the id of the starter node: \n";
	cin >> node_s; //test for input error
	cout << "Please select the id of the finnish node: \n";
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
		cout << endl;

		for(unsigned int k = 0;k < c1.items.size();k++)
		{
			for(unsigned int j = 0;j < grafo->path_res.size();j++)
				{
					if(c1.items[k].dest.compare(grafo->path_res[j])==0)
					{
						cout << "Item was sucessfully delived to " << grafo->path_res[j] <<"\n";
					}
				}
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
*/
Menu* menu= new Menu;
menu->menu1();

}


