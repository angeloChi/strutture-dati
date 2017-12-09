/*
 * nodoBinAlbero.cpp
 *
 *  Created on: 02 feb 2017
 *      Author: angelo
 */
#include<iostream>
#include<iomanip>
#include"nodoBinAlbero.h"

using namespace std;

NodoBinAlbero::NodoBinAlbero(){
	padre = NULL;
	figlioSx = NULL;
	figlioDx = NULL;
	dato = 0;
}

NodoBinAlbero::~NodoBinAlbero(){
	padre = NULL;
	delete figlioSx;
	delete figlioDx;
}

		//PADRE
void NodoBinAlbero::setPadre(NodoBinAlbero* father){
	padre = father;
}

NodoBinAlbero* NodoBinAlbero::getPadre(){
	return padre;
}

		//FIGLIOSX
void NodoBinAlbero::setFiglioSx(NodoBinAlbero* sx){
	figlioSx = sx;
}

NodoBinAlbero* NodoBinAlbero::getFiglioSx(){
	return figlioSx;
}

		//FIGLIODX
void NodoBinAlbero::setFiglioDx(NodoBinAlbero* dx){
	figlioDx = dx;
}

NodoBinAlbero* NodoBinAlbero::getFiglioDx(){
	return figlioDx;
}

		//DATO
void NodoBinAlbero::setDato(typeElem valore){
	dato = valore;
}

typeElem NodoBinAlbero::getDato(){
	return dato;
}
