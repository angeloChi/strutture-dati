/*
 * NalberoT.h
 *
 *  Created on: 11 feb 2017
 *      Author: angelo
 */

#ifndef NALBEROT_H_
#define NALBEROT_H_
#include"nodoNalberoT.h"

using namespace std;

template<class typeElem>
class NalberoT{
public:
	NalberoT();
	~NalberoT();
	void creaAlbero();
	boolean NalberoVuoto();
	void insRadice(typeElem);
	NodoNalberoT<typeElem>* radice();
	NodoNalberoT<typeElem>* padre(NodoNalberoT<typeElem>*);
	boolean foglia(NodoNalberoT<typeElem>*);
	NodoNalberoT<typeElem>* primoFiglio(NodoNalberoT<typeElem>*);
	boolean ultimoFratello(NodoNalberoT<typeElem>*);
	NodoNalberoT<typeElem>* succFratello(NodoNalberoT<typeElem>*);
	void insPrimoFiglio(NodoNalberoT<typeElem>*,typeElem);
	void insFratelloSucc(NodoNalberoT<typeElem>*,typeElem);
	void canSottoNalbero(NodoNalberoT<typeElem>*);
	typeElem leggiNodo(NodoNalberoT<typeElem>*);
	void scriviNodo(NodoNalberoT<typeElem>*,typeElem);

private:
	NodoNalberoT<typeElem>* albero;
};

template<class typeElem>
NalberoT<typeElem>::NalberoT(){
	creaAlbero();
}

template<class typeElem>
NalberoT<typeElem>::~NalberoT(){}

template<class typeElem>
void NalberoT<typeElem>::creaAlbero(){
	albero = NULL;
}

template<class typeElem>
boolean NalberoT<typeElem>::NalberoVuoto(){
	return (albero==NULL);
}

template<class typeElem>
void NalberoT<typeElem>::insRadice(typeElem elem){
	albero = new NodoNalberoT<typeElem>;
	scriviNodo(albero,elem);
	albero->setPadre(NULL);
	albero->setPrimoFiglio(NULL);
	albero->setSuccFratello(NULL);
}

template<class typeElem>
NodoNalberoT<typeElem>* NalberoT<typeElem>::radice(){
	return albero;
}

template<class typeElem>
NodoNalberoT<typeElem>* NalberoT<typeElem>::padre(NodoNalberoT<typeElem>* u){
	assert(!NalberoVuoto() && u!=albero);
	return u->getPadre();
}

template<class typeElem>
boolean NalberoT<typeElem>::foglia(NodoNalberoT<typeElem>* u){
	assert(!NalberoVuoto());
	return (u->getPrimoFiglio()==NULL);
}

template<class typeElem>
NodoNalberoT<typeElem>* NalberoT<typeElem>::primoFiglio(NodoNalberoT<typeElem>* u){
	assert(!NalberoVuoto() &&  !foglia(u));
	return u->getPrimoFiglio();
}

template<class typeElem>
boolean NalberoT<typeElem>::ultimoFratello(NodoNalberoT<typeElem>* u){
	assert(!NalberoVuoto());
		return (u->getSuccFratello()==NULL);
}

template<class typeElem>
NodoNalberoT<typeElem>* NalberoT<typeElem>::succFratello(NodoNalberoT<typeElem>* u){
	assert(!NalberoVuoto() && !ultimoFratello(u));
	return u->getSuccFratello();
}

template<class typeElem>
void NalberoT<typeElem>::insPrimoFiglio(NodoNalberoT<typeElem>* u, typeElem elem){
	assert(!NalberoVuoto() && foglia(u));
	if(!NalberoVuoto() && foglia(u)){
	NodoNalberoT<typeElem>* nuovo = new NodoNalberoT<typeElem>;
	scriviNodo(nuovo,elem);
	u->setPrimoFiglio(nuovo);
	nuovo->setPadre(u);
	nuovo->setPrimoFiglio(NULL);
	nuovo->setSuccFratello(NULL);
	}
}

template<class typeElem>
void NalberoT<typeElem>::insFratelloSucc(NodoNalberoT<typeElem>* u, typeElem elem){
	assert(!NalberoVuoto() && ultimoFratello(u) && u!=albero);
	if(!NalberoVuoto() && ultimoFratello(u) && u!=albero){
	NodoNalberoT<typeElem>* nuovo = new NodoNalberoT<typeElem>;
	scriviNodo(nuovo,elem);
	u->setSuccFratello(nuovo);
	nuovo->setPadre(u->getPadre());
	nuovo->setPrimoFiglio(NULL);
	nuovo->setSuccFratello(NULL);
	}
}

template<class typeElem>
typeElem NalberoT<typeElem>::leggiNodo(NodoNalberoT<typeElem>* u){
	return u->getDato();
}

template<class typeElem>
void NalberoT<typeElem>::scriviNodo(NodoNalberoT<typeElem>* u, typeElem elem){
	u->setDato(elem);
}

template<class typeElem>
void NalberoT<typeElem>::canSottoNalbero(NodoNalberoT<typeElem>* n) {
	NodoNalberoT<typeElem> *temp;
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
    	NodoNalberoT<typeElem>* u;
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
#endif /* NALBEROT_H_ */
