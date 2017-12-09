/*
 * listaTemplate.h
 *
 *  Created on: 30 dic 2016
 *      Author: angelo
 */


#ifndef LISTATEMPLATE_H_
#define LISTATEMPLATE_H_
#include<iostream>
#include<iomanip>
#include<assert.h>

#include "../listaDizionario/nodoTemplate.h"
using namespace std;



typedef bool boolean;

template <class T>
class Lista{
public:
	Lista();
	~Lista();
	void creaLista();
	boolean listaVuota();
	T leggiLista(Nodo<T>*);
	void scriviLista(T, Nodo<T>*);
	Nodo<T>*  primoLista();
	Nodo<T>*  ultimoLista();
	boolean fineLista(Nodo<T>*);
	Nodo<T>*  succLista(Nodo<T>*);
	Nodo<T>*  precLista(Nodo<T>*);
	void insLista(T, Nodo<T>*);
	void cancLista(Nodo<T>*);

private:

	Nodo<T> *testa;
};

//COSTRUTTORE
template <class T>
Lista<T>::Lista(){
	creaLista();
}

//DISTRUTTORE
template<class T>
Lista<T>::~Lista(){}

//CREALISTA
template<class T>
void Lista<T>::creaLista(){
	testa = NULL;
}

//LISTAVUOTA
template<class T>
boolean Lista<T>::listaVuota(){
	return (testa==NULL ? true : false);
}

//LEGGILISTA
template<class T>
T Lista<T>::leggiLista(Nodo<T>*  pos){
	assert(!listaVuota());
	return pos->getElemento();
}

//SCRIVILISTA
template<class T>
void Lista<T>::scriviLista(T dato, Nodo<T>*  pos){
	assert(!listaVuota() && pos!=NULL);
	pos->setElemento(dato);
}

//PRIMOLISTA
template<class T>
Nodo<T>*  Lista<T>::primoLista(){
	return testa;
}

//ULTIMOLISTA
template<class T>
Nodo<T>*  Lista<T>::ultimoLista(){
	Nodo<T>*  p = primoLista();
	while(p->getNextPtr()!=NULL && !fineLista(p)){
		p=succLista(p);
	}
	return p;
}

//FINELISTA
template<class T>
boolean Lista<T>::fineLista(Nodo<T>*  pos){
	return(pos==NULL);
}

//SUCCLISTA
template<class T>
Nodo<T>*  Lista<T>::succLista(Nodo<T>*  pos){
	assert(pos!=NULL);
	return pos->getNextPtr();
}

//PRECLISTA
template<class T>
Nodo<T>*  Lista<T>::precLista(Nodo<T>*  pos){
	assert(pos!=NULL);
	return pos->getPrecPtr();
}

//INSLISTA
template<class T>
void Lista<T>::insLista(T dato, Nodo<T>*  pos){
	Nodo<T>* nuovo = new Nodo<T>();
	nuovo->setElemento(dato);


	if(pos!=NULL){

		Nodo<T>*  pre = pos->getPrecPtr();
		nuovo->setNextPtr(pos);
		nuovo->setPrecPtr(pre);
		pos->setPrecPtr(nuovo);

		if(primoLista()==pos){
			nuovo->setNextPtr(pos);
			pos->setPrecPtr(nuovo);
			nuovo->setPrecPtr(NULL);
			testa=nuovo;

		}else{
			pre->setNextPtr(nuovo);
		}
	}else{ //se  pos==NULL
		if(listaVuota()){
			nuovo->setPrecPtr(NULL);
			testa = nuovo;
		}else{
			 pos = primoLista();
				while(pos->getNextPtr()!=NULL && !fineLista(pos)){
					pos=succLista(pos);
				}
				pos->setNextPtr(nuovo);
				nuovo->setPrecPtr(pos);
		}
			nuovo->setNextPtr(NULL);

	}
}

template<class T>
void Lista<T>::cancLista(Nodo<T>*  pos){
	if(pos!=NULL){
		if(listaVuota()){
			cout<<"lista vuota"<<endl;
		}else if(pos->getPrecPtr()==NULL && pos->getNextPtr()==NULL){	//solo un elemento
			testa=NULL;
			delete pos;
		}else if(pos==primoLista()){	//cancellazione testa
			Nodo<T>*  succ = succLista(pos);
			succ->setPrecPtr(NULL);
			delete pos;
			testa=succ;
		}else if(pos==ultimoLista()){	//cancellazione ultimo elemento
			Nodo<T>*  prec =precLista(pos);
			prec->setNextPtr(NULL);
			delete pos;

		}else{		//cancellazione in posizione generica
			Nodo<T>*  pre = precLista(pos);
			Nodo<T>*  succ = succLista(pos);
			pre->setNextPtr(succ);
			succ->setPrecPtr(pre);
			delete pos;
		}

	}else{
		cout<<"Posizione non corretta"<<endl; //anche lista vuota
	}
}





#endif /* LISTATEMPLATE_H_ */
