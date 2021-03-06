/*
 * listaTemplate.h
 *
 *  Created on: 30 dic 2016
 *      Author: angelo
 */

#ifndef LISTATEMPLATE_H_
#define LISTATEMPLATE_H_
#include<assert.h>
#include"nodoTemplate.h"
using namespace std;

typedef bool boolean;

template <class tipoElem, class posizione>
class Lista{
public:
	Lista();
	~Lista();
	void creaLista();
	boolean listaVuota();
	tipoElem leggiLista(posizione);
	void scriviLista(tipoElem,posizione);
	posizione primoLista();
	posizione ultimoLista();
	boolean fineLista(posizione);
	posizione succLista(posizione);
	posizione precLista(posizione);
	void insLista(tipoElem, posizione);
	void cancLista(posizione);

private:
	Nodo<tipoElem> *testa;
};

//COSTRUTTORE
template <class tipoElem, class posizione>
Lista<tipoElem, posizione>::Lista(){
	creaLista();
}

//DISTRUTTORE
template<class tipoElem,class posizione>
Lista<tipoElem, posizione>::~Lista(){}

//CREALISTA
template<class tipoElem, class posizione>
void Lista<tipoElem,posizione>::creaLista(){
	testa=NULL;
}

//LISTAVUOTA
template<class tipoElem, class posizione>
boolean Lista<tipoElem, posizione>::listaVuota(){
	return (testa==NULL ? true : false);
}

//LEGGILISTA
template<class tipoElem, class posizione>
tipoElem Lista<tipoElem, posizione>::leggiLista(posizione pos){
	assert(!listaVuota());
	return pos->getElemento();
}

//SCRIVILISTA
template<class tipoElem, class posizione>
void Lista<tipoElem, posizione>::scriviLista(tipoElem dato, posizione pos){
	assert(!listaVuota() && pos!=NULL);
	pos->setElemento(dato);
}

//PRIMOLISTA
template<class tipoElem, class posizione>
posizione Lista<tipoElem,posizione>::primoLista(){
	return testa;
}

//ULTIMOLISTA
template<class tipoElem, class posizione>
posizione Lista<tipoElem, posizione>::ultimoLista(){
	posizione p = primoLista();
	while(p->getNextPtr()!=NULL && !fineLista(p)){
		p=succLista(p);
	}
	return p;
}

//FINELISTA
template<class tipoElem, class posizione>
boolean Lista<tipoElem,posizione>::fineLista(posizione pos){
	return(pos==NULL);
}

//SUCCLISTA
template<class tipoElem, class posizione>
posizione Lista<tipoElem,posizione>::succLista(posizione pos){
	assert(pos!=NULL);
	return pos->getNextPtr();
}

//PRECLISTA
template<class tipoElem, class posizione>
posizione Lista<tipoElem,posizione>::precLista(posizione pos){
	assert(pos!=NULL);
	return pos->getPrecPtr();
}

//INSLISTA
template<class tipoElem, class posizione>
void Lista<tipoElem,posizione>::insLista(tipoElem dato, posizione pos){
	Nodo<tipoElem>* nuovo = new Nodo<tipoElem>();
	nuovo->setElemento(dato);
	if(pos!=NULL){
		posizione pre = pos->getPrecPtr();   	//SALVA L'INDIRIZZO DEL PRECEDENTE
		nuovo->setNextPtr(pos);					//IL PUNTATORE AL SUCCESSIVO DEL NUOVO NODO PUNTA A POS
		nuovo->setPrecPtr(pre);					//IL PUNTATORE AL PRECEDENTE DEL NUOVO NODO PUNTA A PRE
		pos->setPrecPtr(nuovo);					//IL PUNTATORE AL PRECEDENTE DI POS PUNTA A NUOVO
		if(primoLista()==pos){					//INSERIMENTO IN TESTA
			nuovo->setNextPtr(pos);
			pos->setPrecPtr(nuovo);
			nuovo->setPrecPtr(NULL);
			testa=nuovo;
		}else{
			pre->setNextPtr(nuovo);				//POSIZIONE QUALSIASI
		}
	}else{ //se  pos==NULL
		if(listaVuota()){			//LISTA VUOTA
			nuovo->setPrecPtr(NULL);
			testa = nuovo;
		}else{						//LISTA PIENA
			 pos = primoLista();
				while(pos->getNextPtr()!=NULL && !fineLista(pos)){		//RICERCA POSIZIONE SUCCESSIVA ALL'ULTIMA
					pos=succLista(pos);
				}
				pos->setNextPtr(nuovo);			//INSERIMENTO IN ULTIMA POSIZIONE
				nuovo->setPrecPtr(pos);
		}
			nuovo->setNextPtr(NULL);
	}
}

template<class tipoElem,class posizione>
void Lista<tipoElem,posizione>::cancLista(posizione pos){
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
		cout<<"Posizione non corretta"<<endl;
	}
}

#endif /* LISTATEMPLATE_H_ */
