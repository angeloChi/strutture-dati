/*
 * prioriCoda.h
 *
 *  Created on: 12 feb 2017
 *      Author: angelo
 */

#ifndef PRIORICODA_H_
#define PRIORICODA_H_
#include"nodoCodaPriorita.h"

#define MAX_LUNG 100  //ATTENZIONE +1 per inserire

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
	NodoCodaPriori* heap[MAX_LUNG];
	int ultimo;

};




#endif /* PRIORICODA_H_ */
