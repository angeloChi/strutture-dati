//============================================================================
// Name        : grafoTemplate.cpp
// Author      : Angelo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include"serviziGrafoTemplate.h"
using namespace std;

typedef string arco;
typedef string nodo;

int main() {
	Grafo<arco,nodo> grafo;
	acquisisciGrafo(grafo);
	cout<<"********************  STAMPA LISTA NODI *********************"<<endl;
	stampaListaNodi(grafo);
	cout<<"********************  STAMPA LISTA ARCHI ********************"<<endl;
	stampaArchi(grafo);

	//CANCELLAZIONE
	/*CellaGrafo<nodo>* posizione;
	Nodo<CellaGrafo<nodo>*>* pos = grafo.listaNodi.primoLista();
	posizione = pos->getNextPtr()->getNextPtr()->getNextPtr()->getElemento();
	cout<<"Stampa nodo: "<<posizione->getInfoNodo()<<endl;

	grafo.cancNodo(posizione);
	cout<<"********************  STAMPA LISTA NODI *********************"<<endl;
	stampaListaNodi(grafo);
	cout<<"********************  STAMPA LISTA ARCHI ********************"<<endl;
	stampaArchi(grafo);*/

	/*************************************/
	cout<<"Numero vertici: "<<numVertici(grafo)<<endl;
	cout<<"Numero archi: "<<numArchi(grafo)<<endl;

	//PROVA VISITA BFS
	CellaGrafo<nodo>* posizione;
	Nodo<CellaGrafo<nodo>*>* pos = grafo.listaNodi.primoLista();
	posizione = pos->getNextPtr()->getNextPtr()->getNextPtr()->getNextPtr()->getElemento();
	cout<<"Stampa nodo: "<<posizione->getInfoNodo()<<endl;

	cout<<"Stampa visita ampiezza: ";
	visitaAmpiezza(grafo,posizione);
	cout<<endl;

	cout<<"Stampa visita profondita': ";
	dfs(grafo,posizione);
	cout<<endl;

	//Distanza
	posizione = pos->getNextPtr()->getNextPtr()->getElemento();
	cout<<"La distanza dal nodo "<<posizione->getInfoNodo()<<" e': ";
	cout<<posizione->getDistanza()<<endl;

	return 0;
}
