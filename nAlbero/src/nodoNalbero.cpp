/*
 * NodoNalbero.cpp
 *
 *  Created on: 10 feb 2017
 *      Author: angelo
 */
#include<iostream>
#include<iomanip>
#include"nodoNalbero.h"

using namespace std;

NodoNalbero::NodoNalbero(){
	dato = 0;
	primoFiglio = NULL;
	succFratello = NULL;
	padre = NULL;
}

NodoNalbero::~NodoNalbero(){}

void NodoNalbero::setDato(typeElem value){
	dato = value;
}

typeElem NodoNalbero::getDato(){
	return dato;
}

void NodoNalbero::setPrimoFiglio(NodoNalbero* figlio){
	primoFiglio = figlio;
}

NodoNalbero* NodoNalbero::getPrimoFiglio(){
	return primoFiglio;
}

void NodoNalbero::setSuccFratello(NodoNalbero* fratello){
	succFratello = fratello;
}

NodoNalbero* NodoNalbero::getSuccFratello(){
	return succFratello;
}

void NodoNalbero::setPadre(NodoNalbero* father){
	padre = father;
}

NodoNalbero* NodoNalbero::getPadre(){
	return padre;
}
