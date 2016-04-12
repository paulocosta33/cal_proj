#include <iostream>
#include <string>
#include <stdlib.h>
#include <queue>
#include <list>
#include <limits>
#include <cmath>
using namespace std;

const int NOT_VISITED = 0;
const int BEING_VISITED = 1;
const int DONE_VISITED = 2;
const int INT_INFINITY = INT_MAX;

class Item
{
   public:
   	string getNome();
   	double getValor();
   	string getDest();
   	int getFatura();
   	Item();

   private:
   	string nome;
   	double valor;
   	string dest;
   	int fatura;
};

Item::Item(int fatura){
	this->fatura=fatura;
	cout << "New Object\n"; 
}

string Item:getNome(){return nome;}
double Item:getValor(){return valor;}
string Item:getDest(){return dest;}
int Item:getFatura(){return fatura;}

class Camiao
{	
	public:
	 int getCapacidade();
	
	private:
	 int capacidade;
};

Camiao::Camiao(void){

}

int Camiao::getCapacidade(){
	return capacidade;
}

class Frota
{
	private:
	vector<Camiao> frota;

};

Frota::Frota(void){

}

//classes vertex|edge do grafo
template <class T>
class Vertex {
	T info;
	vector<Edge<T>  > adj;
	bool visited;
	bool processing;
	int indegree;
	double dist;
public:

	Vertex(T in);
	friend class Graph<T>;

	//void addEdge(Vertex<T> *dest, double w);
	//bool removeEdgeTo(Vertex<T> *d);

	T getInfo() const;
	void setInfo(T info);

	int getDist() const;
	int getIndegree() const;

	bool operator<(const Vertex<T> vertex);

	Vertex* path;
};

template <class T>
struct vertex_greater_than {
    bool operator()(Vertex<T> * a, Vertex<T> * b) const {
        return a->getDist() > b->getDist();
    }
};

template <class T>
Vertex<T>::Vertex(T in): info(in), visited(false), processing(false), indegree(0), dist(0) {
	path = NULL;
}

template <class T>
T Vertex<T>::getInfo() const {
	return this->info;
}

template <class T>
int Vertex<T>::getDist() const {
	return this->dist;
}


template <class T>
void Vertex<T>::setInfo(T info) {
	this->info = info;
}

template <class T>
int Vertex<T>::getIndegree() const {
	return this->indegree;
}

//edge
template <class T>
class Edge {
	Vertex<T> * dest;
	double weight;
public:
	Edge(Vertex<T> *d, double w);
	friend class Graph<T>;
	friend class Vertex<T>;
};

template <class T>
Edge<T>::Edge(Vertex<T> *d, double w): dest(d), weight(w){}

//Graph class
template <class T>
class Graph {
	vector<Vertex<T> *> vertexSet;
	void dfs(Vertex<T> *v, vector<T> &res) const;

	int numCycles;
	//void dfsVisit(Vertex<T> *v);
	//void dfsVisit();
	void getPathTo(Vertex<T> *origin, list<T> &res);

	
	int ** W;   //weight
	int ** P;   //path

public:
	bool addVertex(const T &in);
	bool addEdge(const T &sourc, const T &dest, double w);
	bool removeVertex(const T &in);
	bool removeEdge(const T &sourc, const T &dest);
	void dijkstraShortestPath();


//algoritmo de distancia mais curta
template<class T>
void Graph<T>::dijkstraShortestPath(const T &s) {

	for(unsigned int i = 0; i < vertexSet.size(); i++) {
		vertexSet[i]->path = NULL;
		vertexSet[i]->dist = INT_INFINITY;
		vertexSet[i]->processing = false;
	}

	Vertex<T>* v = getVertex(s);
	v->dist = 0;

	vector< Vertex<T>* > pq;
	pq.push_back(v);

	make_heap(pq.begin(), pq.end());


	while( !pq.empty() ) {

		v = pq.front();
		pop_heap(pq.begin(), pq.end());
		pq.pop_back();

		for(unsigned int i = 0; i < v->adj.size(); i++) {
			Vertex<T>* w = v->adj[i].dest;

			if(v->dist + v->adj[i].weight < w->dist ) {

				w->dist = v->dist + v->adj[i].weight;
				w->path = v;

				//se já estiver na lista, apenas a actualiza
				if(!w->processing)
				{
					w->processing = true;
					pq.push_back(w);
				}

				make_heap (pq.begin(),pq.end(),vertex_greater_than<T>());
			}
		}
	}
}


int main(void){

}