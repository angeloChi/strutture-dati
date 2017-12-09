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

template <class T>
class Nodo{
public:
	Nodo();
	~Nodo();
	//elemento
	void setElemento(T );
	T getElemento();
	//puntatore successivo
	void setNextPtr(Nodo<T>*);
	Nodo<T>* getNextPtr();
	//puntatore precedente
	void setPrecPtr(Nodo<T>*);
	Nodo<T>* getPrecPtr();

private:
	T elemento;
	Nodo<T>* nextPtr;
	Nodo<T>* precPtr;

};

template <class T>
Nodo<T>::Nodo(){
	//elemento = 0; 		//Non posso settare l'elemento nel costruttore, perchè deve essere generico
	nextPtr = NULL;
	precPtr = NULL;
}

template <class T>
Nodo<T>::~Nodo(){}

template <class T>
void Nodo<T>::setElemento(T valore){
	elemento = valore;
}

template <class T>
T Nodo<T>::getElemento(){
	return elemento;
}

template <class T>
void Nodo<T>::setNextPtr(Nodo<T>* succ){
	nextPtr=succ;

}

template <class T>
Nodo<T>* Nodo<T>::getNextPtr(){
	return nextPtr;
}

template <class T>
void Nodo<T>::setPrecPtr(Nodo<T>* prec){
	precPtr=prec;
}

template<class T>
Nodo<T>* Nodo<T>::getPrecPtr(){
	return precPtr;
}
#endif /* NODOTEMPLATE_H_ */

