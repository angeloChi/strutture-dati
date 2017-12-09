/*
 * arcoGrafo.cpp
 *
 *  Created on: 17 feb 2017
 *      Author: angelo
 */
#include"arcoGrafo.h"

ArcoGrafo::ArcoGrafo(){
	nodoPartenza = NULL;
	nodoArrivo = NULL;
}

ArcoGrafo::~ArcoGrafo(){}

void ArcoGrafo::setNodoPartenza(CellaGrafo* partenza){
	nodoPartenza = partenza;
}

CellaGrafo* ArcoGrafo::getNodoPartenza(){
	return nodoPartenza;
}

void ArcoGrafo::setNodoArrivo(CellaGrafo* arrivo){
	nodoArrivo = arrivo;
}

CellaGrafo* ArcoGrafo::getNodoArrivo(){
	return nodoArrivo;
}

void ArcoGrafo::setInfoArco(tipoArco arco){
	infoArco = arco;
}

tipoArco ArcoGrafo::getInfoArco(){
	return infoArco;
}


