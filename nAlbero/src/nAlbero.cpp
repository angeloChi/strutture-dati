 /*
 * nAlbero.cpp
 *
 *  Created on: 10 feb 2017
 *      Author: angelo
 */

#include<iostream>
#include<iomanip>
#include<assert.h>
#include"nAlbero.h"
using namespace std;

Nalbero::Nalbero(){
	creaAlbero();
}

Nalbero::~Nalbero(){}

void Nalbero::creaAlbero(){
	albero = NULL;
}

boolean Nalbero::NalberoVuoto(){
	return (albero==NULL);
}

void Nalbero::insRadice(typeElem elem){
	albero = new NodoNalbero();
	scriviNodo(albero,elem);
	albero->setPadre(NULL);
	albero->setPrimoFiglio(NULL);
	albero->setSuccFratello(NULL);
}

NodoNalbero* Nalbero::radice(){
	return albero;
}

NodoNalbero* Nalbero::padre(NodoNalbero* u){
	assert(!NalberoVuoto() && u!=albero);
	return u->getPadre();
}

boolean Nalbero::foglia(NodoNalbero* u){
	assert(!NalberoVuoto());
	return (u->getPrimoFiglio()==NULL);
}

NodoNalbero* Nalbero::primoFiglio(NodoNalbero* u){
	assert(!NalberoVuoto() &&  !foglia(u));
	return u->getPrimoFiglio();

}

boolean Nalbero::ultimoFratello(NodoNalbero* u){
	assert(!NalberoVuoto());
		return (u->getSuccFratello()==NULL);
}

NodoNalbero* Nalbero::succFratello(NodoNalbero* u){
	assert(!NalberoVuoto() && !ultimoFratello(u));
	return u->getSuccFratello();
}

void Nalbero::insPrimoFiglio(NodoNalbero* u, typeElem elem){
	assert(!NalberoVuoto() && foglia(u));
	if(!NalberoVuoto() && foglia(u)){
	NodoNalbero* nuovo = new NodoNalbero();
	scriviNodo(nuovo,elem);
	u->setPrimoFiglio(nuovo);
	nuovo->setPadre(u);
	nuovo->setPrimoFiglio(NULL);
	nuovo->setSuccFratello(NULL);
	}
}

void Nalbero::insFratelloSucc(NodoNalbero* u, typeElem elem){
	assert(!NalberoVuoto() && ultimoFratello(u) && u!=albero);
	if(!NalberoVuoto() && ultimoFratello(u) && u!=albero){
	NodoNalbero* nuovo = new NodoNalbero();
	scriviNodo(nuovo,elem);
	u->setSuccFratello(nuovo);
	nuovo->setPadre(u->getPadre());
	nuovo->setPrimoFiglio(NULL);
	nuovo->setSuccFratello(NULL);
	}
}

typeElem Nalbero::leggiNodo(NodoNalbero* u){
	return u->getDato();
}

void Nalbero::scriviNodo(NodoNalbero* u, typeElem elem){
	u->setDato(elem);
}


void Nalbero::canSottoNalbero(NodoNalbero* n) {
	NodoNalbero *temp;
	if(n != albero) {
        if ( (n->getPadre())->getPrimoFiglio() ==  n )
        	(n->getPadre())->setPrimoFiglio(n->getSuccFratello());
		else {
            temp = (n->getPadre())->getPrimoFiglio();
            while(temp->getSuccFratello() != n)
            	temp = temp->getSuccFratello();
            temp->setSuccFratello(n->getSuccFratello());
		}
    } else {
    	NodoNalbero* u;
    	u = primoFiglio(albero);
    	while(!ultimoFratello(u)) {
    		canSottoNalbero(u);
    		u = succFratello(u);
    	}
    	albero = NULL;
    	cout << "L'albero e' stato completamente rimosso "<<endl;
    }
    if(n->getPrimoFiglio() != NULL ){
        temp = n->getPrimoFiglio();
        if(temp->getSuccFratello() != NULL)
        	canSottoNalbero(temp->getSuccFratello());
        canSottoNalbero(temp);
    }
    delete n;
}













