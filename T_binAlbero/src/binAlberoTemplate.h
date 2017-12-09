/*
 * binAlberoTemplate.h
 *
 *  Created on: 08 feb 2017
 *      Author: angelo
 */

#ifndef BINALBEROTEMPLATE_H_
#define BINALBEROTEMPLATE_H_

#include"nodoBinAlberoTemplate.h"

using namespace std;

template<class typeElem>
class BinAlberoT{
public:
	BinAlberoT();
	~BinAlberoT();
	void creaBinAlbero();
	boolean binAlberoVuoto();
	NodoBinAlberoT<typeElem>* binRadice();
	NodoBinAlberoT<typeElem>* Padre(NodoBinAlberoT<typeElem>*);
	NodoBinAlberoT<typeElem>* figlioSinistro(NodoBinAlberoT<typeElem>*);
	NodoBinAlberoT<typeElem>* figlioDestro(NodoBinAlberoT<typeElem>*);
	boolean sinistroVuoto(NodoBinAlberoT<typeElem>*);
	boolean destroVuoto(NodoBinAlberoT<typeElem>*);
	typeElem leggiNodo(NodoBinAlberoT<typeElem>*);
	void scriviNodo(NodoBinAlberoT<typeElem>*,typeElem);
	void insRadice();
	void insFiglioSx(NodoBinAlberoT<typeElem>*);
	void insFiglioDx(NodoBinAlberoT<typeElem>*);
	void cancSottoBinAlbero(NodoBinAlberoT<typeElem>*);

private:
	NodoBinAlberoT<typeElem>* albero; 	//Radice
};

template<class typeElem>
BinAlberoT<typeElem>::BinAlberoT(){
	creaBinAlbero();
}

template<class typeElem>
BinAlberoT<typeElem>::~BinAlberoT(){}

template<class typeElem>
void BinAlberoT<typeElem>::creaBinAlbero(){
	albero = NULL;
}

template<class typeElem>
boolean BinAlberoT<typeElem>::binAlberoVuoto(){
	return(albero==NULL);
}

template<class typeElem>
NodoBinAlberoT<typeElem>* BinAlberoT<typeElem>::binRadice(){
	if(!binAlberoVuoto() )
			return albero;
		else
			return NULL;
}

template<class typeElem>
NodoBinAlberoT<typeElem>* BinAlberoT<typeElem>::Padre(NodoBinAlberoT<typeElem>* u){
	if(!binAlberoVuoto() && u!=binRadice())
		return u->getPadre();
	else
		return NULL;
}

template<class typeElem>
NodoBinAlberoT<typeElem>* BinAlberoT<typeElem>::figlioSinistro(NodoBinAlberoT<typeElem>* u){
	if(!binAlberoVuoto() && !sinistroVuoto(u))
		return u->getFiglioSx();
	else
		return NULL;
}

template<class typeElem>
NodoBinAlberoT<typeElem>* BinAlberoT<typeElem>::figlioDestro(NodoBinAlberoT<typeElem>* u){
	if(!binAlberoVuoto() && !destroVuoto(u))
		return u->getFiglioDx();
	return NULL;
}

template<class typeElem>
boolean BinAlberoT<typeElem>::sinistroVuoto(NodoBinAlberoT<typeElem>* u){
	return(u->getFiglioSx()==NULL);
}

template<class typeElem>
boolean BinAlberoT<typeElem>::destroVuoto(NodoBinAlberoT<typeElem>* u){
	return(u->getFiglioDx()==NULL);
}

template<class typeElem>
typeElem BinAlberoT<typeElem>::leggiNodo(NodoBinAlberoT<typeElem>* u){
	return u->getDato();
}

template<class typeElem>
void BinAlberoT<typeElem>::scriviNodo(NodoBinAlberoT<typeElem>* u, typeElem value){
	u->setDato(value);
}

template<class typeElem>
void BinAlberoT<typeElem>::insRadice(){
	if(binAlberoVuoto())
		albero = new NodoBinAlberoT<typeElem>();
}

template<class typeElem>
void BinAlberoT<typeElem>::insFiglioSx(NodoBinAlberoT<typeElem>* u){
	if(!binAlberoVuoto() && sinistroVuoto(u)){
		NodoBinAlberoT<typeElem>* sx = new NodoBinAlberoT<typeElem>();
		u->setFiglioSx(sx);
		sx->setPadre(u);
	}
}

template<class typeElem>
void BinAlberoT<typeElem>::insFiglioDx(NodoBinAlberoT<typeElem>* u){
	if(!binAlberoVuoto() && destroVuoto(u)){
		NodoBinAlberoT<typeElem>* dx = new NodoBinAlberoT<typeElem>();
		u->setFiglioDx(dx);
		dx->setPadre(u);
	}
}

template<class typeElem>
void BinAlberoT<typeElem>::cancSottoBinAlbero(NodoBinAlberoT<typeElem>* u){
	if(!binAlberoVuoto()){
		if(u==albero){
			 albero=NULL;
		}else{
			NodoBinAlberoT<typeElem>* padre = u->getPadre();
			if(u==padre->getFiglioSx())
				padre->setFiglioSx(NULL);
			else
				padre->setFiglioDx(NULL);

			delete u;
		}
	}else{
		cout<<"Albero vuoto"<<endl;
	}
}
#endif /* BINALBEROTEMPLATE_H_ */
