/*
 * Nodo.cpp
 *
 *  Created on: 21 dic 2016
 *      Author: angelo
 */

#include<iostream>
#include <iomanip>
#include "Nodo.h"
#include <cstddef>

using namespace std;


Nodo::Nodo(){

	nextPtr = NULL;
	precPtr = NULL;
	elemento = 0;
}

Nodo::~Nodo(){}

void Nodo::setElemento(tipoElem valore){
	elemento = valore;
}

tipoElem Nodo::getElemento(){
	return elemento;
}


void Nodo::setNextPtr(posizione succ){
	nextPtr=succ;
}

posizione Nodo::getNextPtr(){
	return nextPtr;
}

void Nodo::setPrecPtr(posizione prec){
	precPtr=prec;
}

posizione Nodo::getPrecPtr(){
	return precPtr;
}



