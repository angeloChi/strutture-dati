/*
 * serviziGrafo.cpp
 *
 *  Created on: 18 feb 2017
 *      Author: angelo
 */

#include"serviziGrafo.h"

void acquisisciGrafo(Grafo &grafo){
	grafo.creaGrafo();
	CellaGrafo* a = new CellaGrafo();
	CellaGrafo* b = new CellaGrafo();
	CellaGrafo* c = new CellaGrafo();
	CellaGrafo* d = new CellaGrafo();

	ArcoGrafo* arco1 = new ArcoGrafo();
	ArcoGrafo* arco2 = new ArcoGrafo();
	ArcoGrafo* arco3 = new ArcoGrafo();
	ArcoGrafo* arco4 = new ArcoGrafo();
	ArcoGrafo* arco5 = new ArcoGrafo();


	grafo.insNodo(a,"A");
	grafo.insNodo(b,"B");
	grafo.insNodo(c,"C");
	grafo.insNodo(d,"D");

	grafo.insArco(a,b,arco1,"(A,B)");
	grafo.insArco(a,d,arco2,"(A,D)");
	grafo.insArco(b,c,arco3,"(B,C)");
	grafo.insArco(c,a,arco4,"(C,A)");
	grafo.insArco(c,d,arco5,"(C,D)");
}

void stampaListaNodi(Grafo &grafo){
	CellaGrafo* posizione;
	    Nodo<CellaGrafo*>* pos = grafo.listaNodi.primoLista();
	    Nodo<CellaGrafo*>* pos_adi;
	    Lista<CellaGrafo*, Nodo<CellaGrafo*>*> Adiacenti;
	    while (pos != NULL) {
	    	Adiacenti.creaLista();
	    	posizione = pos->getElemento();
	    	Adiacenti = grafo.adiacenti(posizione);
	    	cout << endl;
	    	cout << "Nodo# " << pos->getElemento()->getInfoNodo() << " ";
	    	pos_adi = Adiacenti.primoLista();
	    	while (pos_adi != NULL) {
	    		cout << "adiacenti# " << pos_adi->getElemento()->getInfoNodo() << " ";
	                     pos_adi = Adiacenti.succLista(pos_adi);
	    	}
	    	cout << "   " << endl;
	    	pos = grafo.listaNodi.succLista(pos);
	    }
	    cout << endl << endl;
}

void stampaArchi(Grafo &grafo) {
    Nodo<ArcoGrafo*>* pos = grafo.listaArchi.primoLista();
    while (pos != NULL) {
    	cout << "Arco#" << pos->getElemento()->getInfoArco() << " "
                            << pos->getElemento()->getNodoPartenza()->getInfoNodo() << "->"
                            << pos->getElemento()->getNodoArrivo()->getInfoNodo() << endl;
    	pos = grafo.listaArchi.succLista(pos);
    }
    cout << endl << endl;

}


int numVertici(Grafo &grafo){
	int i = 0;
	Nodo<CellaGrafo*>* pos = grafo.listaNodi.primoLista();
	while(!grafo.listaNodi.fineLista(pos)){
		pos = grafo.listaNodi.succLista(pos);
		i++;
	}
	return i;
}

int numArchi(Grafo &grafo){
	int i = 0;
		Nodo<ArcoGrafo*>* pos = grafo.listaArchi.primoLista();
		while(!grafo.listaArchi.fineLista(pos)){
			pos = grafo.listaArchi.succLista(pos);
			i++;
		}
		return i;
}

