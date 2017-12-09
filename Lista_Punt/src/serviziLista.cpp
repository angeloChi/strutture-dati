/*
 * serviziLista.cpp
 *
 *  Created on: 24 dic 2016
 *      Author: angelo
 */
#include <iostream>
#include<iomanip>
#include<assert.h>
#include"serviziLista.h"
#include"Lista.h"

using namespace std;

void acquisisciLista(Lista &lista){
	tipoElem dato;
	lista.creaLista();

	//inserimento lista vuota
	posizione pos = lista.primoLista();
	dato = 1;
	lista.insLista(dato,pos);

	dato = 2;
	lista.insLista(dato,pos);

	dato = 3;
	lista.insLista(dato,pos);

	dato = 4;
	lista.insLista(dato,pos);

	dato = 5;
	lista.insLista(dato,pos);



}

void stampaLista(Lista &lista){
	posizione pos = lista.primoLista();
	if(!lista.listaVuota()){
		cout<<"List: ";
		while(!lista.fineLista(pos)){
			cout<<lista.leggiLista(pos)<<" ";
			pos = lista.succLista(pos);
		}
	}else{
		cout<<"la lista e' vuota"<<endl;
	}
}

void insListap(Lista &lista, int i, tipoElem dato){
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

int numeroElem(Lista &lista){

	int i = 1;
	posizione pos = lista.primoLista();
	while(pos!=lista.ultimoLista() && !lista.fineLista(pos)){
		pos=lista.succLista(pos);
		i++;
	}
	return i;

}

void canc(Lista &lista, int i){
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

posizione cerca(Lista &lista,tipoElem elem) {
	posizione pos = new Nodo();
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

void svuotaLista(Lista &lista){
	if(lista.listaVuota()){
			cout<<"Impossibile svuotare lista vuota"<<endl;
		}else{

			while(!lista.listaVuota()){
				lista.cancLista(lista.primoLista());
			}
		}
}
