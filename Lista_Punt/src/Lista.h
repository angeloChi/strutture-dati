/*
 * Lista.h
 *
 *  Created on: 21 dic 2016
 *      Author: angelo
 */
#include "Nodo.h"
#ifndef LISTA_H_
#define LISTA_H_

typedef bool boolean;

class Lista{

public:
	Lista();
	~Lista();
	void creaLista();
	boolean listaVuota();
	tipoElem leggiLista(posizione);
	void scriviLista(tipoElem, posizione);
	posizione primoLista();
	posizione ultimoLista();
	boolean fineLista(posizione);
	posizione succLista(posizione);
	posizione precLista(posizione);
	void insLista(tipoElem, posizione);
	void cancLista(posizione);

private:

	Nodo *testa;

};



#endif /* LISTA_H_ */
