/*
 * nodoBinAlberoTeplate.h
 *
 *  Created on: 08 feb 2017
 *      Author: angelo
 */

#ifndef NODOBINALBEROTEMPLATE_H_
#define NODOBINALBEROTEMPLATE_H_
#include<iostream>
#include<iomanip>
typedef bool boolean;

using namespace std;
template<class typeElem>

class NodoBinAlberoT{
public:
		NodoBinAlberoT();
		~NodoBinAlberoT();
		//padre
		void setPadre(NodoBinAlberoT<typeElem>*);
		NodoBinAlberoT<typeElem>* getPadre();
		//figlioSx
		void setFiglioSx(NodoBinAlberoT<typeElem>*);
		NodoBinAlberoT<typeElem>* getFiglioSx();
		//figlioDx
		void setFiglioDx(NodoBinAlberoT<typeElem>*);
		NodoBinAlberoT<typeElem>* getFiglioDx();
		//dato
		void setDato(typeElem);
		typeElem getDato();

private:
		NodoBinAlberoT<typeElem>* padre;
		NodoBinAlberoT<typeElem>* figlioSx;
		NodoBinAlberoT<typeElem>* figlioDx;
		typeElem dato;
};

template<class typeElem>
NodoBinAlberoT<typeElem>::NodoBinAlberoT(){
	padre = NULL;
	figlioSx = NULL;
	figlioDx = NULL;
	dato = 0;
}

template<class typeElem>
NodoBinAlberoT<typeElem>::~NodoBinAlberoT(){
	padre = NULL;
	delete figlioSx;
	delete figlioDx;
}

//PADRE
template<class typeElem>
void NodoBinAlberoT<typeElem>::setPadre(NodoBinAlberoT<typeElem>* father){
	padre = father;
}

template<class typeElem>
NodoBinAlberoT<typeElem>* NodoBinAlberoT<typeElem>::getPadre(){
	return padre;
}

//FIGLIOSX
template<class typeElem>
void NodoBinAlberoT<typeElem>::setFiglioSx(NodoBinAlberoT<typeElem>* sx){
	figlioSx = sx;
}

template<class typeElem>
NodoBinAlberoT<typeElem>* NodoBinAlberoT<typeElem>::getFiglioSx(){
	return figlioSx;
}

//FIGLIODX
template<class typeElem>
void NodoBinAlberoT<typeElem>::setFiglioDx(NodoBinAlberoT<typeElem>* dx){
	figlioDx = dx;
}

template<class typeElem>
NodoBinAlberoT<typeElem>* NodoBinAlberoT<typeElem>::getFiglioDx(){
	return figlioDx;
}

//DATO
template<class typeElem>
void NodoBinAlberoT<typeElem>::setDato(typeElem valore){
dato = valore;
}

template<class typeElem>
typeElem NodoBinAlberoT<typeElem>::getDato(){
return dato;
}

#endif /* NODOBINALBEROTEMPLATE_H_ */
