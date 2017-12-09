/*
 * cellaGrafoTemplate.h
 *
 *  Created on: 18 feb 2017
 *      Author: angelo
 */

#ifndef CELLAGRAFOTEMPLATE_H_
#define CELLAGRAFOTEMPLATE_H_
#include<iostream>
#include<stdlib.h>
#include<string>
#include<cstring>

using namespace std;

typedef bool boolean;

template<class T>
class CellaGrafo{
public:
	CellaGrafo();
	~CellaGrafo();
	void setInfoNodo(T);
	T getInfoNodo();
	void setVisitato(boolean);
	boolean getVisitato();
	void setDistanza(int);
	int getDistanza();

private:
	T infoNodo; //al costruttore modificare l'inizializzazione
	boolean visitato; //UTILE PER LE BFS E DFS
	int distanza;
};

template<class T>
CellaGrafo<T>::CellaGrafo(){
	//infoNodo = 0; //costruttore da modificare in base al tipo
	visitato = false;
	distanza = 0;
}

template<class T>
CellaGrafo<T>::~CellaGrafo(){}

template<class T>
void CellaGrafo<T>::setInfoNodo(T info){
	infoNodo = info;
}

template<class T>
T CellaGrafo<T>::getInfoNodo(){
	return infoNodo;
}

template<class T>
void CellaGrafo<T>::setVisitato(boolean vis){
	visitato = vis;
}

template<class T>
boolean CellaGrafo<T>::getVisitato(){
	return visitato;
}

template<class T>
void CellaGrafo<T>::setDistanza(int dist){
	distanza = dist;
}

template<class T>
int CellaGrafo<T>::getDistanza(){
	return distanza;
}
#endif /* CELLAGRAFOTEMPLATE_H_ */
