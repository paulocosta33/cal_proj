/*
 * Graph.h
 *
 *  Created on: 16/04/2016
 *      Author: jigsawkiller
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <list>
#include <limits>
#include <cmath>
#include <stddef.h>
#include "Frota.h"
using namespace std;

const int NOT_VISITED = 0;
const int BEING_VISITED = 1;
const int DONE_VISITED = 2;
const int INT_INFINITY = 1000000;

template <class T> class Graph;
template <class T> class Vertex;
template <class T> class Edge;

/* ================================================================================================
 * Class Edge
 * ================================================================================================
 */
template <class T>
class Edge {

public:
	Edge(Vertex<T> *d, double w);
	friend class Graph<T>;
	friend class Vertex<T>;
	Vertex<T> * dest;
	int weight;
	string nome;
	string id;
	bool duploSentido;
	Edge(){};
};

template <class T>
Edge<T>::Edge(Vertex<T> *d, double w): dest(d), weight(w){}


/*
 * ================================================================================================
 * Class Vertex
 * ================================================================================================
 */
template <class T>
class Vertex {
public:
	//Vertex();
	T info;
	bool visited;
	bool processing;
	int indegree;
	string id;
	double dist; //distancia acumulada
	double latitude;
	double longitude;
	Vertex(T in);
	vector<Edge<T>  > adj;
	friend class Graph<T>;
	Vertex* path;
	void addEdge(Vertex<T> *dest, double w);
	bool removeEdgeTo(Vertex<T> *d);

	T getInfo() const;
	void setInfo(T info);

	int getDist() const;
	int getIndegree() const;

	bool operator<(const Vertex<T> vertex);


};

template <class T>
bool Vertex<T>::removeEdgeTo(Vertex<T> *d)
{
	d->indegree--; //adicionado do exercicio 5
	typename vector<Edge<T> >::iterator it= adj.begin();
	typename vector<Edge<T> >::iterator ite= adj.end();
	while (it!=ite) {
		if (it->dest == d) {
			adj.erase(it);
			return true;
		}
		else it++;
	}
	return false;
}

//atualizado pelo exercício 5
template <class T>
Vertex<T>::Vertex(T in): info(in), visited(false), processing(false), indegree(0), dist(0) {
	path = NULL;
}


template <class T>
void Vertex<T>::addEdge(Vertex<T> *dest, double w) {
	Edge<T> edgeD(dest,w);
	adj.push_back(edgeD);
}

//--
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


template <class T>
struct vertex_greater_than {
    bool operator()(Vertex<T> * a, Vertex<T> * b) const {
        return a->getDist() > b->getDist();
    }
};


/* ================================================================================================
 * Class Graph
 * ================================================================================================
 */
template <class T>
class Graph {

	void dfs(Vertex<T> *v, vector<T> &res) const;
	int numCycles; //
	void dfsVisit(Vertex<T> *v);
	void dfsVisit();

	//exercicio 6
	int ** W;   //weight
	int ** P;   //path

public:
	Graph(vector<Vertex<T>*> v);
	Graph(){};
	vector<Vertex<T> *> vertexSet;
	bool addVertex(const T &in);
	void addEdge(const T &sourc,const T &dest, double w);
	bool removeVertex(const T &in);
	bool removeEdge(const T &sourc, const T &dest);
	void getPath(const T &origin, const T &dest);
	vector<T> dfs() const;
	vector<T> bfs(Vertex<T> *v) const;
	vector<T> path_res;
	int maxNewChildren(Vertex<T> *v, T &inf) const;
	vector<Vertex<T> * > getVertexSet() const;
	int getNumVertex() const;

	//exercicio 5
	Vertex<T>* getVertex(const T &v) const;
	void resetIndegrees();
	vector<Vertex<T>*> getSources() const;
	int getNumCycles();
	vector<T> topologicalOrder();
	void unweightedShortestPath(const T &v);
	bool isDAG();

	//exercicio 6
	void bellmanFordShortestPath(const T &s);
	void dijkstraShortestPath(const T &s);
};

template <class T>
Graph<T>::Graph(vector<Vertex<T>*> v){
	P = NULL;
	W = 0;
	numCycles = 0;
	vertexSet =v;
};

template <class T>
Vertex<T>* Graph<T>::getVertex(const T &v) const {
	for(unsigned int i = 0; i < vertexSet.size(); i++)
		if (vertexSet[i]->info == v) return vertexSet[i];
	return NULL;
}

template <class T>
int Graph<T>::getNumVertex() const {
	return vertexSet.size();
}
template <class T>
vector<Vertex<T> * > Graph<T>::getVertexSet() const {
	return vertexSet;
}

template <class T>
int Graph<T>::getNumCycles() {
	numCycles = 0;
	dfsVisit();
	return this->numCycles;
}

template <class T>
bool Graph<T>::isDAG() {
	return (getNumCycles() == 0);
}

template<class T>
void Graph<T>::getPath(const T &origin, const T &dest){

	list<T> buffer;
	Vertex<T>* v = getVertex(dest);

	buffer.push_front(v->info);
	while ( v->path != NULL &&  v->path->info != origin) {
		v = v->path;
		buffer.push_front(v->info);
	}
	if( v->path != NULL )
		buffer.push_front(v->path->info);


	while( !buffer.empty() ) {
		path_res.push_back( buffer.front() );
		buffer.pop_front();
	}
}

template <class T>
void Graph<T>::addEdge(const T &sourc, const T &dest, double w) {
	typename vector<Vertex<T>*>::iterator it= vertexSet.begin();
	typename vector<Vertex<T>*>::iterator ite= vertexSet.end();
	int found=0;
	Vertex<T> *vS, *vD;
	while (found!=2 && it!=ite ) {
		if((*it)->info.compare(sourc)==0) // ( (*it)->info == sourc ), changed to str
			{ vS=*it; found++;}
		if((*it)->info.compare(dest)==0)
			{ vD=*it; found++;}
		it ++;
	}
	//if (found!=2);
	vD->indegree++;
	vS->addEdge(vD,w);
}


template<class T>
void Graph<T>::dijkstraShortestPath(const T &s)

{

	for(unsigned int i = 0; i < vertexSet.size(); i++) {
		vertexSet[i]->path = NULL;
		vertexSet[i]->dist = INT_INFINITY;
		vertexSet[i]->processing = false;
	}

	Vertex<T>* v = getVertex(s); //v is the starter vertex
	v->dist = 0;

	vector< Vertex<T>* > pq; //pq is a vector with all the vertex
	pq.push_back(v);

	make_heap(pq.begin(), pq.end());


	while( !pq.empty() ) {

		v = pq.front();
		pop_heap(pq.begin(), pq.end());
		pq.pop_back();

		for(unsigned int i = 0; i < v->adj.size(); i++) { // adj are the adj edge
			Vertex<T>* w = v->adj[i].dest;    //w -> vertice de destino da edge


			if(v->dist + v->adj[i].weight < w->dist ) {

				//for(int k =0 ; k < getFrota.size(); k )
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



#endif /* GRAPH_H_ */
