/*
 * cellaGrafo.h
 *
 *  Created on: 17 feb 2017
 *      Author: angelo
 */

#ifndef CELLAGRAFO_H_
#define CELLAGRAFO_H_

#include<iostream>
#include<stdlib.h>
#include<string>
#include<cstring>

using namespace std;

typedef bool boolean;
typedef string tipoNodo;
typedef string tipoArco;



class CellaGrafo{
public:
	CellaGrafo();
	~CellaGrafo();
	void setInfoNodo(tipoNodo);
	tipoNodo getInfoNodo();
	void setVisitato(boolean);
	boolean getVisitato();

private:
	tipoNodo infoNodo; //al costruttore modificare l'inizializzazione
	boolean visitato; //UTILE PER LE BFS E DFS

};




#endif /* CELLAGRAFO_H_ */
