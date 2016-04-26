/*
 * menu.h
 *
 *  Created on: 25/04/2016
 *      Author: Utilizador
 */

#ifndef MENU_H_
#define MENU_H_
#include "Graph.h"
#include "Frota.h"
#include "Item.h"
#include <stdio.h>
#include <iostream>
#include "Mapa.h"
#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Menu
{
public:
	Frota* frota= new Frota();
	vector<Item*> items;
	Menu(){};
	template <typename T>
	string NumberToString ( T Number )
	{
		stringstream ss;
		ss << Number;
		return ss.str();
	}
	void menuFrota()
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

			cout<< "#========================# \n";
			for (int i=0; i<frota->frota.size();i++)
			{
				cout<<"| id:"<<frota->frota[i]->getId()<<"; Capacidade :"<<frota->frota[i]->capacidade_peso<< "\n";
				cout<<"| Items: ";
				for  (int j=0; j<frota->frota[i]->items.size();j++)
				{
					cout<<frota->frota[i]->items[j]->nome<< ";";
				}
				cout<< "\n";
			}
			cout<< "#========================# \n";
			cin.get();
			cin.get();
			menuFrota();
		}
		if(opcao==2)
		{
			int capacidade;
			cout<<"Capacidade do Camiao: ";
			cin >> capacidade;
			frota->addCamiao(new Camiao(capacidade));
			menuFrota();

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
			menuFrota();
		}
		if(opcao==4)
		{
			menu1();
		}

	}

	void menu1()
	{
	int opcao;
	cout<< "#========================# \n";
	cout<< "| 1- Gerir Frota         |\n";
	cout<< "| 2- Gerir Items         | \n";
	cout<< "| 3- Carregar            |\n";
	cout<< "| 4- Lancar              |\n";
	cout<< "| 5- Ver Mapa            |\n";
	cout<< "| 6- Sair                |\n";
	cout<< "#========================# \n";
	cin >> opcao;
	if(opcao==1)
	{
	menuFrota();
	}
	if(opcao==2)
	{
    menuItems();
	}
	if(opcao==3)
	{
	menuCarrega();
	}
	if(opcao==5)
	{
	menuMapa();
	}
	if (opcao==6)
	{
		return;
	}
	}

	void menuItems()
	{
		int opcao;
		string nome;
		string dest;
		int fatura,peso;
		double valor;
		cout<< "#========================# \n";
		cout<< "| 1- Ver Items           |\n";
		cout<< "| 2- Criar Item          |\n";
		cout<< "| 3- Remover Item        | \n";
		cout<< "| 4- Retroceder          |\n";
		cout<< "#========================# \n";
		cin >> opcao;
		if (opcao==1)
		{

			cout << "#========================# \n";
			for(int i=0; i< items.size(); i++)
			{
				cout<<"| Nome: "<<items[i]->nome<<" Peso: "<< items[i]->peso <<" Valor: " << items[i]->valor<< " Fatura: "<< items[i]->fatura << " Dest.: "<< items[i]->dest<< endl;
			}
			cout << "#========================# \n";
			cin.get();
			cin.get();
			menuItems();


		}
		if (opcao==2)
		{
			cout<<"Introduza o nome do item:";
			cin>>nome;
			cout<<"Introduza o peso do item:";
			cin>>peso;
			cout<<"Introduza a fatura do item:";
			cin>>fatura;
			cout<<"Introduza o valor do item:";
			cin>>valor;
			cout<<"Introduza o destino do item:";
			cin>>dest;

			Item * item= new Item( nome,valor, peso, dest,fatura);

			items.push_back(item);

			menuItems();

		}
		if(opcao==3)
		{
			int fatura;
			cout<<" Introduza a factura do Item a remover:";
			cin >> fatura;
			for(int i=0; i< items.size(); i++)
			{
				if (fatura==items[i]->fatura)
				{
					items.erase(items.begin()+i);
				}
			}
			menuItems();
		}
		if(opcao==4)
		{
			menu1();
		}
	}



	void menuCarrega()
	{
		for(int k=0; k<frota->frota.size();k++)
		{
			bool acabou=false;
			int max=0;
			int counter=0;
			if(items.size()==0||frota->frota[k]->capacidade_peso==0)
			acabou=true;
			while(acabou==false && frota->frota[k]->capacidade_peso>0 && items.size()!=0)
			{
				for(int i=0; i<items.size();i++)
				{
					if(items[i]->peso>max&&items[i]->marcado==false)
					{
						max=items[i]->peso;
					}
				}
				if(max<=frota->frota[k]->capacidade_peso)
				{
					for(int j=0; j<items.size();j++)
					{
						if(items[j]->peso==max)
						{
							frota->frota[k]->items.push_back(items[j]);
							frota->frota[k]->capacidade_peso-=max;
							items.erase(items.begin()+j);
							max=0;
							break;
						}
					}
				}
				else
				{
					for(int j=0; j<items.size();j++)
					{
						if(items[j]->peso==max)
						{
						   items[j]->marcado=true;
						   max=0;
						   break;
						}
					}
				}
				for(int j=0; j<items.size();j++)
				{
					if(items[j]->marcado==true)
					{
						counter++;
					}
				}

				if (counter==items.size())
				acabou=true;
				counter=0;
				max=0;
			}

			for(int i=0; i<items.size();i++)
			{
				items[i]->marcado=false;
			}

		}
	menu1();
	}//TODO;





	void menuLanca() {} //TODO;

	void menuMapa()
	{
		        Mapa<string> m;

				int x,y,idedge;
				x=5;
				y=5;
				idedge=0;
				Graph<string>* grafo= m.readfiles();
				double minLat=41.13;
				double maxLat=41.163;
				double maxLong=-8.600;
				double minLong=-8.625;

				GraphViewer *gv = new GraphViewer(1800, 900, false);
				gv->createWindow(1800, 900);
				gv->defineEdgeColor("blue");
			    gv->defineVertexColor("yellow");
			    for (int i=0; i < grafo->vertexSet.size(); i++)
			    {
			    	x=((grafo->vertexSet[i]->longitude - minLong) / (maxLong - minLong)) * (1800 - 1);
			    	y= ((grafo->vertexSet[i]->latitude - minLat) / (maxLat - minLat)) * (900 - 1);
			    	gv->addNode(grafo->vertexSet[i]->id,x,y);

			    	x=x+100;
			    	if (x==2505)
			    	{ y=y+100;
			    	  x=5;
			    	}
			    }

			    for (int i=0; i < grafo->vertexSet.size(); i++)
			    {
			    	for (int k=0; k<grafo->vertexSet[i]->adj.size();k++)
			    	{
			    		string str=NumberToString(grafo->vertexSet[i]->adj[k].weight);
			    		gv->addEdge(idedge,grafo->vertexSet[i]->id,grafo->vertexSet[i]->adj[k].dest->id,EdgeType::DIRECTED);
			    		gv->setEdgeLabel(idedge,str);
			    		idedge++;
			    	}
			    }

			    cin.get();
			    cin.get();
			    menu1();
	}


};



#endif /* MENU_H_ */
