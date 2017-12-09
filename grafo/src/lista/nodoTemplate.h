/*
 * nodoTemplate.h
 *
 *  Created on: 28 dic 2016
 *      Author: angelo
 */

#ifndef NODOTEMPLATE_H_
#define NODOTEMPLATE_H_
#include <iostream>
#include<iomanip>
using namespace std;

template <class tipoElem>
class Nodo{
public:
	Nodo();
	~Nodo();
	//elemento
	void setElemento(tipoElem );
	tipoElem getElemento();
	//puntatore successivo
	void setNextPtr(Nodo<tipoElem>*);
	Nodo<tipoElem>* getNextPtr();
	//puntatore precedente
	void setPrecPtr(Nodo<tipoElem>*);
	Nodo<tipoElem>* getPrecPtr();






private:
	tipoElem elemento;
	Nodo<tipoElem>* nextPtr;
	Nodo<tipoElem>* precPtr;

};

template <class tipoElem>
Nodo<tipoElem>::Nodo(){
	elemento = 0;
	nextPtr = NULL;
	precPtr = NULL;
}

template <class tipoElem>
Nodo<tipoElem>::~Nodo(){}

template <class tipoElem>
void Nodo<tipoElem>::setElemento(tipoElem valore){
	elemento = valore;
}

template <class tipoElem>
tipoElem Nodo<tipoElem>::getElemento(){
	return elemento;
}

template <class tipoElem>
void Nodo<tipoElem>::setNextPtr(Nodo<tipoElem>* succ){
	nextPtr=succ;

}

template <class tipoElem>
Nodo<tipoElem>* Nodo<tipoElem>::getNextPtr(){
	return nextPtr;
}

template <class tipoElem>
void Nodo<tipoElem>::setPrecPtr(Nodo<tipoElem>* prec){
	precPtr=prec;
}

template<class tipoElem>
Nodo<tipoElem>* Nodo<tipoElem>::getPrecPtr(){
	return precPtr;
}
#endif /* NODOTEMPLATE_H_ */

