/*
 * prioriCodaT.h
 *
 *  Created on: 13 feb 2017
 *      Author: angelo
 */

#ifndef PRIORICODAT_H_
#define PRIORICODAT_H_
#include"nodoCodaPrioritaT.h"

using namespace std;

#define MAX_LUNG 100  //ATTENZIONE +1 per inserire

template<class typeElem>
class PrioriCoda{
public:
	PrioriCoda();
	~PrioriCoda();
	void creaPrioriCoda();
	typeElem min();
	void inserisci(typeElem,int);
	void cancellaMin();

	int getUltimo();
	boolean prioriCodaVuota();
	int getNumeroNodi();
	typeElem leggiNodo(int);
	int leggiPrioriNodo(int);

private:
	NodoCodaPriori<typeElem>* heap[MAX_LUNG];
	int ultimo;
};

template<class typeElem>
PrioriCoda<typeElem>::PrioriCoda(){
	creaPrioriCoda();
}

template<class typeElem>
PrioriCoda<typeElem>::~PrioriCoda(){}

template<class typeElem>
void PrioriCoda<typeElem>::creaPrioriCoda(){
	int i;
	for(i=1; i<=MAX_LUNG; i++)
		heap[i] = new NodoCodaPriori<typeElem>();
	ultimo = 0;
}

template<class typeElem>
typeElem PrioriCoda<typeElem>::min(){
	if(prioriCodaVuota()){
		return 0;
	}
	else
		return heap[1]->getElemento();
}

template<class typeElem>
void PrioriCoda<typeElem>::inserisci(typeElem x, int pr){
	int i,k;
	NodoCodaPriori<typeElem>* temp = new NodoCodaPriori<typeElem>();
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

template<class typeElem>
void PrioriCoda<typeElem>::cancellaMin(){
	int i,k;
		NodoCodaPriori<typeElem>* temp = new NodoCodaPriori<typeElem>();
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

template<class typeElem>
int PrioriCoda<typeElem>::getUltimo(){
	return ultimo;
}

template<class typeElem>
boolean PrioriCoda<typeElem>::prioriCodaVuota(){
	return (ultimo==0);
}

template<class typeElem>
int PrioriCoda<typeElem>::getNumeroNodi(){
	return ultimo;
}

template<class typeElem>
typeElem PrioriCoda<typeElem>::leggiNodo(int i){
	if(!prioriCodaVuota() && i<=getNumeroNodi())
		return heap[i]->getElemento();
	else
		return 0;
}

template<class typeElem>
int PrioriCoda<typeElem>::leggiPrioriNodo(int i){
	if(!prioriCodaVuota() && i<=getNumeroNodi())
			return heap[i]->getPriorita();
		else
			return 0;
}
#endif /* PRIORICODAT_H_ */
