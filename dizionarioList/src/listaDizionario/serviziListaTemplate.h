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

#include "../listaDizionario/listaTemplate.h"
#include "../listaDizionario/nodoTemplate.h"

using namespace std;

template<class T>
void acquisisciLista(Lista<T> &lista){
	Nodo<T>*  pos = lista.primoLista();
	T dato;
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

/*template<class T>
void stampaLista(Lista<T> &lista){
	Nodo<T>*  pos = lista.primoLista();
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

*/
template<class T>
int numeroElem(Lista<T> &lista){

	if(!lista.listaVuota()){
	int i = 1;
	Nodo<T>*  pos = lista.primoLista();
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

template<class T>
void insListap(Lista<T> &lista, int i, T dato){

	Nodo<T>*  p = lista.primoLista();
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

template<class T>
void canc(Lista<T> &lista,int i){
	int j = 1;
	int lunghezza = numeroElem(lista);

	if(i==lunghezza){
		lista.cancLista(lista.ultimoLista());

	}else if(i==j){
		lista.cancLista(lista.primoLista());
	}else{
		Nodo<T>*  pos = lista.primoLista();
		while(j!=i){
			pos = lista.succLista(pos);
			j++;
		}
		lista.cancLista(pos);

	}
}






template<class T>
Nodo<T>*  cerca(Lista<T> &lista,T elem){
	Nodo<T>*  pos = new Nodo<T>();
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

template<class T>
void svuotaLista(Lista<T> &lista){
	if(lista.listaVuota()){
		cout<<"Impossibile svuotare lista vuota"<<endl;
	}else{
		Nodo<T>*  pos = lista.primoLista();
		while(!lista.listaVuota() && !lista.fineLista(pos)){
			Nodo<T>*  pos = lista.primoLista();
			lista.cancLista(pos);
		}
	}
}

template<class T>
void InsOrdine(Lista<T>* L, T elem)
{
     Nodo<T>* pos = new Nodo<T>;
     pos = L->primoLista();
     while(pos != NULL && elem->getKey()> L->leggiLista(pos)->getKey() )
     {
          pos = L->succLista(pos);
     }
     L->insLista(elem,pos);
}

template<class T>
void StampaLista(Lista<T>* L)
{
	Nodo<T>* postemp = new Nodo<T>;
	postemp = L->primoLista();
	if(L->listaVuota())
		cout<<"-> "<<endl;
	else
	{
        cout<<"-> ";
		do
        {
			StampaElemLista(L, postemp);
			//cout<<L->LEGGILISTA(postemp)->getKey()<<" ";
			postemp = L->succLista(postemp);
		}
		while(postemp != NULL);
		cout<<endl;
    }
}

template<class T>
void StampaElemLista(Lista<T>* L, Nodo<T>* n)
{
     cout<<L->leggiLista(n)->getKey()<<" ";
}

#endif /* SERVIZILISTATEMPLATE_H_ */
