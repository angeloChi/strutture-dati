/*
 * nodoNalberoT.h
 *
 *  Created on: 11 feb 2017
 *      Author: angelo
 */

#ifndef NODONALBEROT_H_
#define NODONALBEROT_H_
#include<iostream>
#include<iomanip>
#include<assert.h>
using namespace std;

typedef bool boolean;

template<class typeElem>
class NodoNalberoT{
public:
	NodoNalberoT();
	~NodoNalberoT();
	//DATO
	void setDato(typeElem);
	typeElem getDato();
	//PRIMOFIGLIO
	void setPrimoFiglio(NodoNalberoT<typeElem>*);
	NodoNalberoT<typeElem>* getPrimoFiglio();
	//FRATELLOsUCC
	void setSuccFratello(NodoNalberoT<typeElem>*);
	NodoNalberoT<typeElem>* getSuccFratello();
	//PADRE
	void setPadre(NodoNalberoT<typeElem>*);
	NodoNalberoT<typeElem>* getPadre();

private:
	typeElem dato;
	NodoNalberoT<typeElem>* primoFiglio;
	NodoNalberoT<typeElem>* succFratello;
	NodoNalberoT<typeElem>* padre;
};

template<class typeElem>
NodoNalberoT<typeElem>::NodoNalberoT(){
	dato = 0;
	primoFiglio = NULL;
	succFratello = NULL;
	padre = NULL;
}

template<class typeElem>
NodoNalberoT<typeElem>::~NodoNalberoT(){}

template<class typeElem>
void NodoNalberoT<typeElem>::setDato(typeElem value){
	dato = value;
}

template<class typeElem>
typeElem NodoNalberoT<typeElem>::getDato(){
	return dato;
}

template<class typeElem>
void NodoNalberoT<typeElem>::setPrimoFiglio(NodoNalberoT<typeElem>* figlio){
	primoFiglio = figlio;
}

template<class typeElem>
NodoNalberoT<typeElem>* NodoNalberoT<typeElem>::getPrimoFiglio(){
	return primoFiglio;
}

template<class typeElem>
void NodoNalberoT<typeElem>::setSuccFratello(NodoNalberoT<typeElem>* fratello){
	succFratello = fratello;
}

template<class typeElem>
NodoNalberoT<typeElem>* NodoNalberoT<typeElem>::getSuccFratello(){
	return succFratello;
}

template<class typeElem>
void NodoNalberoT<typeElem>::setPadre(NodoNalberoT<typeElem>* father){
	padre = father;
}

template<class typeElem>
NodoNalberoT<typeElem>* NodoNalberoT<typeElem>::getPadre(){
	return padre;
}
#endif /* NODONALBEROT_H_ */
