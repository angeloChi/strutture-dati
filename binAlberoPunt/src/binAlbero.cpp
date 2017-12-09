/*
 * binAlbero.cpp
 *
 *  Created on: 02 feb 2017
 *      Author: angelo
 */
#include<iostream>
#include<iomanip>
#include<assert.h>
#include"binAlbero.h"

using namespace std;

BinAlbero::BinAlbero(){
	creaBinAlbero();
}

BinAlbero::~BinAlbero(){}

void BinAlbero::creaBinAlbero(){
	albero = NULL;
}

boolean BinAlbero::binAlberoVuoto(){
	return(albero==NULL);
}

NodoBinAlbero* BinAlbero::binRadice(){
	if(!binAlberoVuoto() )
		return albero;
	else
		return NULL;
}

NodoBinAlbero* BinAlbero::Padre(NodoBinAlbero* u){

	if(!binAlberoVuoto() && u!=binRadice())
		return u->getPadre();
	else
		return NULL;
}

NodoBinAlbero* BinAlbero::figlioSinistro(NodoBinAlbero* u){
	if(!binAlberoVuoto() && !sinistroVuoto(u))
		return u->getFiglioSx();
	else
		return NULL;
}

NodoBinAlbero* BinAlbero::figlioDestro(NodoBinAlbero* u){

	if(!binAlberoVuoto() && !destroVuoto(u))
		return u->getFiglioDx();
	return NULL;
}

boolean BinAlbero::sinistroVuoto(NodoBinAlbero* u){
	return(u->getFiglioSx()==NULL);
}

boolean BinAlbero::destroVuoto(NodoBinAlbero* u){
	return(u->getFiglioDx()==NULL);
}

typeElem BinAlbero::leggiNodo(NodoBinAlbero* u){
	return u->getDato();
}

void BinAlbero::scriviNodo(NodoBinAlbero* u, typeElem value){
	u->setDato(value);
}

void BinAlbero::insRadice(){
	if(binAlberoVuoto())
		albero = new NodoBinAlbero();
}

void BinAlbero::insFiglioSx(NodoBinAlbero* u){
	if(!binAlberoVuoto() && sinistroVuoto(u)){
		NodoBinAlbero* sx = new NodoBinAlbero();
		u->setFiglioSx(sx);
		sx->setPadre(u);
	}

}

void BinAlbero::insFiglioDx(NodoBinAlbero* u){
	if(!binAlberoVuoto() && destroVuoto(u)){
		NodoBinAlbero* dx = new NodoBinAlbero();
		u->setFiglioDx(dx);
		dx->setPadre(u);
	}

}

void BinAlbero::cancSottoBinAlbero(NodoBinAlbero* u){
	if(!binAlberoVuoto()){
		if(u==albero){
			 albero=NULL;
		}else{
			NodoBinAlbero* padre = u->getPadre();
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
