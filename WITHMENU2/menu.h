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
#include <set>
using namespace std;

class Menu
{
public:
	Frota* frota= new Frota();
	vector<Item*> items;
	Menu(){};
	double dist_calc(double long1,double lat1,double long2, double lat2){
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

		for(unsigned int j=0; j<mp_distini_ordered.size();j++)
		{
			for(unsigned int i =0; i<mp_distini.size();i++)
			{
				if (mp_distini[i]==mp_distini_ordered[j])
				{
					indice.push_back(i);
				}
			}
		}

		for(unsigned int z=0; z<indice.size();z++)
		{
			mp_order.push_back(mustp[indice[z]]);
		}
		return mp_order;
	}
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
	if(opcao==4)
	{
	menuLanca();
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
		Mapa<string> m;
		Graph<string>* grafo= m.readfiles();
		int opcao;
		string nome;
		string dest,destinf;
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
				cout<<"| Nome: "<<items[i]->nome<<" Peso: "<< items[i]->peso <<" Valor: " << items[i]->valor<< " Fatura: "<< items[i]->fatura << " Dest.: "<< items[i]->destinf<<" DestID: "<< items[i]->dest<<endl;
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
			cin>>destinf;

			for(int i=0; i< grafo->vertexSet.size();i++)
			{
				if(NumberToString(grafo->vertexSet[i]->id)==destinf)
				{
					dest=grafo->vertexSet[i]->info;
				}
			}

			Item * item= new Item( nome,valor, peso, dest,fatura);
			item->destinf=destinf;
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





	void menuLanca()
	{
		for(int f=0; f<frota->frota.size();f++)
		{
			if(frota->frota[f]->items.size()==0)
			{
				menu1();
			}
		    string node_s;
			string node_f;
			int itemssize= frota->frota[f]->items.size();
			Mapa<string> m;
			Graph<string>* grafo= m.readfiles();
			grafo->floydWarshallShortestPath();
			string mp; //must pass point
			string ans;
			vector<string> must_points;
			vector<string> mp_ordered;
			vector<string> ruas;
			node_s= "25632293";
			node_f= "25632401";

				for(int it=0; it<frota->frota[f]->items.size();it++)
				{
					bool igual=false;
					for (int m=0; m<must_points.size();m++)
					{
						if(frota->frota[f]->items[it]->dest==must_points[m])
						{
							igual=true;
							break;
						}

					}
					if(igual==false)
					{
						must_points.push_back(frota->frota[f]->items[it]->dest);
					}
				}

				//must_points.pop_back();

				mp_ordered = orderMP(node_s, must_points,grafo);

				if(must_points.size()==1)
				{
							cout << "The shortest path is: \n";

									grafo->getfloydWarshallPath(node_s,mp_ordered[0]);
									grafo->getfloydWarshallPath(mp_ordered[0],node_f);
									for(unsigned int k = 0;k < grafo->path_res.size();k++)
									{
										for(int gr=0;gr<grafo->vertexSet.size();gr++)
										{
											if(grafo->path_res[k]== "25632401" )
											{
												cout << "Armazem; " ;
												break;
											}

											else if(grafo->path_res[k]=="25632293")
											{cout <<"Garagem; ";
											break;}

											else if(grafo->path_res[k]==grafo->vertexSet[gr]->info)
											{cout << grafo->vertexSet[gr]->id << "; ";}
										}
										//cout << grafo->path_res[k] << " ";
									}
									cout << endl;

									cout << "You should follow this path: \n";
										for(unsigned int g = 0; g < grafo->path_res.size();g++)
										{
											if ((g+1) == grafo->path_res.size()) break;
											for(unsigned j = 0;j < grafo->edgeSet.size();j++)
											{
												if(grafo->path_res[g].compare(grafo->edgeSet[j]->source->info ) ==0 && grafo->path_res[g+1].compare(grafo->edgeSet[j]->dest->info )==0)
												{

													ruas.push_back(grafo->edgeSet[j]->road);
												}
											}
										}
										set<string> s( ruas.begin(),ruas.end());
										ruas.assign(s.begin(),s.end());
										reverse(ruas.begin(),ruas.end());
										for(unsigned int i =0;i<ruas.size();i++)
										{
											cout << ruas[i] << " -> ";
										}

				}
				else
				{
				cout << "The shortest path is: \n";

				grafo->getfloydWarshallPath(node_s,mp_ordered[0]);

				for(unsigned int i = 1;i < mp_ordered.size() -1;i++)
				{
					grafo->getfloydWarshallPath(mp_ordered[i],mp_ordered[i+1]);
				}
				grafo->getfloydWarshallPath(mp_ordered[mp_ordered.size()-1],node_f);

				cout << "Camiao "<<frota->frota[f]->getId()<<": ";
				for(unsigned int k = 0;k < grafo->path_res.size();k++)
				{
					for(int gr=0;gr<grafo->vertexSet.size();gr++)
					{
						if(grafo->path_res[k]== "25632401" )
						{
						cout << "Armazem; " ;
						break;
						}

						else if(grafo->path_res[k]=="25632293")
						{cout <<"Garagem; ";
						break;}

						else if(grafo->path_res[k]==grafo->vertexSet[gr]->info)
						{cout << grafo->vertexSet[gr]->id << "; ";}
					}
					//cout << grafo->path_res[k] << "; ";
				}
				cout << endl;
				cout << "You should follow this path: \n";
				for(unsigned int g = 0; g < grafo->path_res.size();g++)
				{
					if ((g+1) == grafo->path_res.size()) break;
					for(unsigned j = 0;j < grafo->edgeSet.size();j++)
					{
						if(grafo->path_res[g].compare(grafo->edgeSet[j]->source->info ) ==0 && grafo->path_res[g+1].compare(grafo->edgeSet[j]->dest->info )==0)
						{

							ruas.push_back(grafo->edgeSet[j]->road);
						}
					}
				}
							set<string> s( ruas.begin(),ruas.end());
							ruas.assign(s.begin(),s.end());
							reverse(ruas.begin(),ruas.end());
							for(unsigned int i =0;i<ruas.size();i++)
							{
								cout << ruas[i] << " -> ";
							}
		}

			cout << endl;
			for(int it2=0; it2<frota->frota[f]->items.size();it2++)
			{
				frota->frota[f]->capacidade_peso+=frota->frota[f]->items[it2]->peso;
				frota->frota[f]->items.erase(frota->frota[f]->items.begin()+it2);
				it2--;
				if(frota->frota[f]->items.size()==0)
				break;
			}
		}
		cin.get();
		cin.get();
		menu1();
	} //TODO;

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
