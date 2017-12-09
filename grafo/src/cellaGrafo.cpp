/*
 * cellaGrafo.cpp
 *
 *  Created on: 17 feb 2017
 *      Author: angelo
 */

#include"cellaGrafo.h"

CellaGrafo::CellaGrafo(){
	//infoNodo = 0; //costruttore da modificare in base al tipo
	visitato = false;
}

CellaGrafo::~CellaGrafo(){}

void CellaGrafo::setInfoNodo(tipoNodo info){
	infoNodo = info;
}

tipoNodo CellaGrafo::getInfoNodo(){
	return infoNodo;
}

void CellaGrafo::setVisitato(boolean vis){
	visitato = vis;
}

boolean CellaGrafo::getVisitato(){
	return visitato;
}
