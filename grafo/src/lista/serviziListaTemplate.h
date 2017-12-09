/*
 * serviziListaTemplate.h
 *
 *  Created on: 30 dic 2016
 *      Author: angelo
 */

#ifndef SERVIZILISTATEMPLATE_H_
#define SERVIZILISTATEMPLATE_H_
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include"listaTemplate.h"
#include"nodoTemplate.h"

using namespace std;

template<class tipoElem, class posizione>
void acquisisciLista(Lista<tipoElem,posizione> &lista){
	posizione pos = lista.primoLista();
	tipoElem dato;
	lista.creaLista();

	dato = 8;
	lista.insLista(dato,pos);

	dato = 9;
	lista.insLista(dato,pos);

	dato = 1;
	lista.insLista(dato,pos);

	dato = 7;
	lista.insLista(dato,pos);

	dato = 3;
	lista.insLista(dato,pos);

}

template<class tipoElem, class posizione>
void stampaLista(Lista<tipoElem,posizione> &lista){
	posizione pos = lista.primoLista();
		if(!lista.listaVuota()){
			cout<<"List: ";
			while(!lista.fineLista(pos)){
				cout<<lista.leggiLista(pos)<<" ";
				pos = lista.succLista(pos);
			}
		}else{
			cout<<"La lista e' vuota"<<endl;
		}
}

template<class tipoElem, class posizione>
int numeroElem(Lista<tipoElem,posizione> &lista){

	if(!lista.listaVuota()){
	int i = 1;
		posizione pos = lista.primoLista();
		while(pos!=lista.ultimoLista() && !lista.fineLista(pos)){
			pos=lista.succLista(pos);
			i++;
		}
		return i;
	}else{
		cout<<"La lista è vuota"<<endl;
		return 0;
	}

}

template<class tipoElem, class posizione>
void insListap(Lista<tipoElem,posizione> &lista, int i, tipoElem dato){

	posizione p = lista.primoLista();
		int j =0;

		int lunghezza = numeroElem(lista);

		if(i==lunghezza){
			p = lista.ultimoLista();
			lista.insLista(dato,p);
		}else if(i==lunghezza+1){
			p = lista.succLista(lista.ultimoLista());
			lista.insLista(dato,p);
		}else if (i==1){
			lista.insLista(dato,p);

		}else{
			while(j!=i){
				p = lista.succLista(p);
				j++;
			}
			p = lista.precLista(p);
			lista.insLista(dato,p);
		}


}

template<class tipoElem, class posizione>
void canc(Lista<tipoElem,posizione> &lista,int i){
	int j = 1;
	int lunghezza = numeroElem(lista);

	if(i==lunghezza){
		lista.cancLista(lista.ultimoLista());

	}else if(i==j){
		lista.cancLista(lista.primoLista());
	}else{
		posizione pos = lista.primoLista();
		while(j!=i){
			pos = lista.succLista(pos);
			j++;
		}
		lista.cancLista(pos);

	}
}






template<class tipoElem, class posizione>
posizione cerca(Lista<tipoElem,posizione> &lista,tipoElem elem){
	posizione pos = new Nodo<tipoElem>();
	pos = NULL;
	boolean trovato = false;
	int i = 0;
	pos = lista.primoLista();
	if (!lista.listaVuota()) {
		while (!lista.fineLista(pos) && !trovato) {
			i++;
			if (lista.leggiLista(pos) == elem)
				trovato = true;
			else
				pos = lista.succLista(pos);
		}
	}
	cout << "L'elemento "<<elem;
	if (trovato)
		cout << " e' ";
	else
		cout << " non e' ";
	cout << " presente nella lista" << endl;
	return pos;
}

template<class tipoElem, class posizione>
void svuotaLista(Lista<tipoElem,posizione> &lista){
	if(lista.listaVuota()){
		cout<<"Impossibile svuotare lista vuota"<<endl;
	}else{
		posizione pos = lista.primoLista();
		while(!lista.listaVuota() && !lista.fineLista(pos)){
			posizione pos = lista.primoLista();
			lista.cancLista(pos);
		}
	}
}



#endif /* SERVIZILISTATEMPLATE_H_ */
