/*
 * serviziCodaPri.cpp
 *
 *  Created on: 13 feb 2017
 *      Author: angelo
 */
#include<iostream>
#include<stdio.h>
#include<iomanip>
#include"serviziCodaPri.h"

using namespace std;

void autoAcquisizione(PrioriCoda &C){
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

void inserimento(PrioriCoda &C){
	C.creaPrioriCoda();
	typeElem x;
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

void stampa(PrioriCoda &C){
	if(!C.prioriCodaVuota()){
		for(int i = 1; i<=C.getNumeroNodi(); i++)
			cout<<C.leggiNodo(i)<<" ";
	}
	else
		cout<<"PrioriCoda Vuota"<<endl;
}

void stampaPriorita(PrioriCoda &C){
	if(!C.prioriCodaVuota()){
		for(int i = 1; i<=C.getNumeroNodi(); i++)
			cout<<C.leggiPrioriNodo(i)<<" ";
	}
	else
		cout<<"PrioriCoda Vuota"<<endl;
}

typeElem getPadre(PrioriCoda &C, int x){
	int j = x/2;
	return C.leggiNodo(j);


}

int ricerca(PrioriCoda &C, typeElem x){
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
