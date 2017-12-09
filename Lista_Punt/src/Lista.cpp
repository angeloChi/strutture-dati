/*
 * Lista.cpp
 *
 *  Created on: 21 dic 2016
 *      Author: angelo
 */
#include <iostream>
#include <iomanip>
#include <cstddef>
#include "Lista.h"
#include<assert.h>


using namespace std;



Lista::Lista(){
	creaLista();
}

void Lista::creaLista(){
	testa=NULL;
}

Lista::~Lista(){}

boolean Lista::listaVuota(){
	return (testa==NULL ? true : false);
}


tipoElem Lista::leggiLista(posizione posizione){
	assert(!listaVuota());
	return posizione->getElemento();
}

void Lista::scriviLista(tipoElem dato, posizione posizione){
	assert(!listaVuota());
	posizione->setElemento(dato);

}

posizione Lista::primoLista(){
	return testa;
}

posizione Lista::ultimoLista(){
	posizione p = primoLista();
	while(p->getNextPtr()!=NULL && !fineLista(p)){
		p=succLista(p);
	}
	return p;
}


boolean Lista::fineLista(posizione posizione){
	return (posizione == NULL);
}

posizione  Lista::succLista(posizione posizione){
	assert(posizione !=NULL);
	return posizione->getNextPtr();

}

posizione Lista::precLista(posizione posizione){
	assert(posizione !=NULL);
	return posizione->getPrecPtr();
}



void Lista::insLista(tipoElem valore,posizione pos) {

	Nodo *nuovo = new Nodo();
	nuovo->setElemento(valore);

	if(pos!=NULL){

		posizione pre = pos->getPrecPtr();
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

void Lista::cancLista(posizione pos){
	if(pos!=NULL){
			if(listaVuota()){
				cout<<"lista vuota"<<endl;
			}else if(pos->getPrecPtr()==NULL && pos->getNextPtr()==NULL){	//solo un elemento
				testa=NULL;
				delete pos;
			}else if(pos==primoLista()){	//cancellazione testa
				posizione succ = succLista(pos);
				succ->setPrecPtr(NULL);
				delete pos;
				testa=succ;
			}else if(pos==ultimoLista()){	//cancellazione ultimo elemento
				posizione prec =precLista(pos);
				prec->setNextPtr(NULL);
				delete pos;

			}else{		//cancellazione in posizione generica
				posizione pre = precLista(pos);
				posizione succ = succLista(pos);
				pre->setNextPtr(succ);
				succ->setPrecPtr(pre);
				delete pos;
			}

		}else{
			cout<<"Posizione non corretta"<<endl; //anche lista vuota
		}
	}




