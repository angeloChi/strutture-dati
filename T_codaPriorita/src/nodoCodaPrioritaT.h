/*
 * nodoCodaPrioritaT.h
 *
 *  Created on: 13 feb 2017
 *      Author: angelo
 */

#ifndef NODOCODAPRIORITAT_H_
#define NODOCODAPRIORITAT_H_
#include<iostream>
#include<iomanip>

typedef bool boolean;

using namespace std;

template<class typeElem>
class NodoCodaPriori{
public:
	NodoCodaPriori();
	~NodoCodaPriori();
	//Elemento
	void setElemento(typeElem);
	typeElem getElemento();
	//Priorità
	void setPriorita(int);
	int getPriorita();

private:
	typeElem elemento;
	int priorita;
};

template<class typeElem>
NodoCodaPriori<typeElem>::NodoCodaPriori(){
	elemento = 0;
	priorita = -1;
}

template<class typeElem>
NodoCodaPriori<typeElem>::~NodoCodaPriori(){}

template<class typeElem>
void NodoCodaPriori<typeElem>::setElemento(typeElem elem){
	elemento = elem;
}

template<class typeElem>
typeElem NodoCodaPriori<typeElem>::getElemento(){
	return elemento;
}

template<class typeElem>
void NodoCodaPriori<typeElem>::setPriorita(int priori){
	priorita = priori;
}

template<class typeElem>
int NodoCodaPriori<typeElem>::getPriorita(){
	return priorita;
}
#endif /* NODOCODAPRIORITAT_H_ */
