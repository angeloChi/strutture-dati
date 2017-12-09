/*
 * serviziCodaPriT.h
 *
 *  Created on: 13 feb 2017
 *      Author: angelo
 */

#ifndef SERVIZICODAPRIT_H_
#define SERVIZICODAPRIT_H_
#include<iomanip>
#include<iostream>
#include"prioriCodaT.h"

using namespace std;

template<class S>
void autoAcquisizione(PrioriCoda<S> &C){
	C.creaPrioriCoda();
	C.inserisci('c',3);
	C.inserisci('e',5);
	C.inserisci('i',9);
	C.inserisci('f',6);
	C.inserisci('h',8);
	C.inserisci('o',13);
	C.inserisci('n',12);
	C.inserisci('m',11);
	C.inserisci('t',18);
	C.inserisci('l',10);
}

template<class S>
void inserimento(PrioriCoda<S> &C){
	C.creaPrioriCoda();
	S x;
	char risp;
	int pr = 0;
	for(int i=1; i<MAX_LUNG && (risp!='n' && risp!='N'); i++){
		cout<<"Inserire elemento: ";
		cin>>x;
		cout<<"Inserire priorita: ";
		cin>>pr;
		C.inserisci(x,pr);
		cout<<"Vuoi continuare? [S/N]"<<endl;
		cin>>risp;
	}
}


template<class S>
void stampa(PrioriCoda<S> &C){
	if(!C.prioriCodaVuota()){
		for(int i = 1; i<=C.getNumeroNodi(); i++)
			cout<<C.leggiNodo(i)<<" ";
	}
	else
		cout<<"PrioriCoda Vuota"<<endl;
}

template<class S>
void stampaPriorita(PrioriCoda<S> &C){
	if(!C.prioriCodaVuota()){
		for(int i = 1; i<=C.getNumeroNodi(); i++)
			cout<<C.leggiPrioriNodo(i)<<" ";
	}
	else
		cout<<"PrioriCoda Vuota"<<endl;
}

template<class S>
S getPadre(PrioriCoda<S> &C, int x){
	int j = x/2;
	return C.leggiNodo(j);
}

//Ricerca restituisce la posizione
template<class S>
int ricerca(PrioriCoda<S> &C, S x){
	int trovato = 1;
	int i = 1;
	while(i<=C.getNumeroNodi() && trovato){
		if(C.leggiNodo(i)==x){
			trovato = i;
		}
			i++;
	}
	return trovato;
}
#endif /* SERVIZICODAPRIT_H_ */
