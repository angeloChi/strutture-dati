
/*
 * prioriCoda.cpp
 *
 *  Created on: 12 feb 2017
 *      Author: angelo
 */
#include<iostream>
#include<iomanip>
#include<assert.h>
#include"prioriCoda.h"

using namespace std;

PrioriCoda::PrioriCoda(){
	creaPrioriCoda();
}

PrioriCoda::~PrioriCoda(){}

void PrioriCoda::creaPrioriCoda(){
	int i;
	for(i=1; i<=MAX_LUNG; i++)
		heap[i] = new NodoCodaPriori();
	ultimo = 0;
}


typeElem PrioriCoda::min(){
	if(prioriCodaVuota()){
		return 0;
	}
	else
		return heap[1]->getElemento();
}

void PrioriCoda::inserisci(typeElem x, int pr){
	int i,k;
	NodoCodaPriori* temp = new NodoCodaPriori();
	if(ultimo == MAX_LUNG)
		cout<<"errore coda piena"<<endl;
	else{
		ultimo = ultimo + 1;
		heap[ultimo]->setElemento(x);
		heap[ultimo]->setPriorita(pr);
		i = ultimo;
		if(i>1)
			k = i/2;
			while((i>1) && (heap[i]->getPriorita()< heap[k]->getPriorita())){
				temp = heap[i];
				heap[i] = heap[k];
				heap[k] = temp;
				i = k;
				if(i>1)
					k = i/2;
			}
			i++;
	}
}

void PrioriCoda::cancellaMin(){
	int i,k;
		NodoCodaPriori* temp = new NodoCodaPriori();
		boolean scambio;
		if(prioriCodaVuota())
			cout<<"Prioricoda vuota"<<endl;
		else{
			heap[1] = heap[ultimo];
			ultimo--;
			i = 1;
			scambio = true;
			while((i<=(ultimo/2)) && scambio){
				k = 2*i;
				if(k<ultimo)
					if(heap[k]->getPriorita()>heap[k+1]->getPriorita())
						k++;
				if(heap[k]->getPriorita()<heap[i]->getPriorita()){
					temp = heap[i];
					heap[i] = heap[k];
					heap[k] = temp;
					i = k;
				}else
					scambio = false;
			}
		}
}

int PrioriCoda::getUltimo(){
	return ultimo;
}

boolean PrioriCoda::prioriCodaVuota(){
	return (ultimo==0);
}

int PrioriCoda::getNumeroNodi(){
	return ultimo;
}

typeElem PrioriCoda::leggiNodo(int i){
	if(!prioriCodaVuota() && i<=getNumeroNodi())
		return heap[i]->getElemento();
	else
		return 0;
}

int PrioriCoda::leggiPrioriNodo(int i){
	if(!prioriCodaVuota() && i<=getNumeroNodi())
			return heap[i]->getPriorita();
		else
			return 0;
}


