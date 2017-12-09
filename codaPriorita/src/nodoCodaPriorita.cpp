/*
 * nodoCodaPriorita.cpp
 *
 *  Created on: 12 feb 2017
 *      Author: angelo
 */
#include<iostream>
#include<iomanip>
#include"nodoCodaPriorita.h"

using namespace std;

NodoCodaPriori::NodoCodaPriori(){
	elemento = 0;
	priorita = -1;
}

NodoCodaPriori::~NodoCodaPriori(){}

void NodoCodaPriori::setElemento(typeElem elem){
	elemento = elem;
}

typeElem NodoCodaPriori::getElemento(){
	return elemento;
}

void NodoCodaPriori::setPriorita(int priori){
	priorita = priori;
}

int NodoCodaPriori::getPriorita(){
	return priorita;
}



