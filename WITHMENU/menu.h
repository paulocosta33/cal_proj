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
	//
	string node_s;
	string node_f;
	Mapa<string> m;
	Graph<string>* grafo= m.readfiles();
	string mp; 
	string ans;
	vector<string> must_points;
	vector<string> mp_ordered;
	//
	Menu(){};
	template <typename T>
	string NumberToString ( T Number )
	{
		stringstream ss;
		ss << Number;
		return ss.str();
	}
	double dist_calc(double long1,double lat1,double long2, double lat2)
	{
		double dlong = long2 - long1;
		double dlat = lat2 - lat1;
		double res;
		res = sqrt((double)dlong*dlong + dlat*dlat);
		return res;
	}

static bool sort_lesser_than(double u, double v)
{
   return u < v;
}

vector<string> orderMP(string node_ss, vector<string> mustp,Graph<string>* g){
	vector<string> mp_order;
	double d1,d2,d3,d4;
	int s_tag;
	vector<double> mp_distini;
	vector<double> mp_distini_ordered;
	vector<int> indice;
	for(unsigned int u =0; u < g->vertexSet.size();u++)
	{
		if(g->vertexSet[u]->info == node_ss) s_tag = u;
	}
	for(unsigned int y= 0;y < mustp.size(); y++)
	{
		for(unsigned int x =0; x < g->vertexSet.size();x++)
		{
			if(mustp[y].compare(g->vertexSet[x]->info)==0)
			{
				d1 = g->vertexSet[s_tag]->longitude;
				d2 = g->vertexSet[s_tag]->latitude;
				d3 = g->vertexSet[x]->longitude;
				d4 = g->vertexSet[x]->latitude;
				//distancia de cada mustpasspoint ao inicio
				mp_distini.push_back(dist_calc(d1,d2,d3,d4));
			}
		}
	}

	mp_distini_ordered = mp_distini;
	sort(mp_distini_ordered.begin(),mp_distini_ordered.end(),sort_lesser_than);

	for(unsigned int i =0; i<mp_distini.size();i++)
	{
		for(unsigned int j=0; j<mp_distini_ordered.size();j++)
		{
			if (mp_distini[i]==mp_distini_ordered[j])
			{
				indice.push_back(j);
			}
		}
	}

	for(unsigned int z=0; z<mp_order.size();z++)
	{
		mp_order[z] = mustp[indice[z]];
	}
	return mp_order;
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
			//menu1();
			grafo->floydWarshallShortestPath();
			for(int i =0; i < items.size();i++)
			{
				must_points.push_back(items[i].dest);	
			}
			cout << "Please select the id of the starter node: \n";
			cin >> node_s;
			cout << "Please select the id of the finnish node: \n";
			cin >> node_f;
			
			cout << "Are there any more must pass point? (yes/no)\n";
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

		mp_ordered = must_points;
		mp_ordered = orderMP(node_s, must_points,grafo);

		cout << "The shortest path is: \n";

		grafo->getfloydWarshallPath(node_s,mp_ordered[0]);
		for(unsigned int i = 1;i < mp_ordered.size() -1;i++)
		{
			grafo->getfloydWarshallPath(mp_ordered[i],mp_ordered[i+1]);
		}
		grafo->getfloydWarshallPath(mp_ordered[mp_ordered.size()-1],node_f);


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



}
			
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
