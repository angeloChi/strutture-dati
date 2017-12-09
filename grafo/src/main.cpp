//============================================================================
// Name        : grafo.cpp
// Author      : Angelo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include"serviziGrafo.h"
using namespace std;

int main() {
		Grafo grafo;
		acquisisciGrafo(grafo);
		cout<<"********************  STAMPA LISTA NODI *********************"<<endl;
		stampaListaNodi(grafo);
		cout<<"********************  STAMPA LISTA ARCHI ********************"<<endl;
		stampaArchi(grafo);

		//CANCELLAZIONE
		CellaGrafo* posizione;
		Nodo<CellaGrafo*>* pos = grafo.listaNodi.primoLista();
	    posizione = pos->getNextPtr()->getNextPtr()->getNextPtr()->getElemento();
	    cout<<"Stampa nodo: "<<posizione->getInfoNodo()<<endl;;

	    grafo.cancNodo(posizione);
		cout<<"********************  STAMPA LISTA NODI *********************"<<endl;
		stampaListaNodi(grafo);
	    cout<<"********************  STAMPA LISTA ARCHI ********************"<<endl;
	    stampaArchi(grafo);

	    /*************************************/
		cout<<"Numero vertici: "<<numVertici(grafo)<<endl;
		cout<<"Numero archi: "<<numArchi(grafo)<<endl;






	return 0;
}

