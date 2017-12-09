/*
 * alberoN.h
 *
 *  Created on: 10 feb 2017
 *      Author: angelo
 */

#ifndef NALBERO_H_
#define NALBERO_H_
#include"nodoNalbero.h"

class Nalbero{
public:
	Nalbero();
	~Nalbero();
	void creaAlbero();
	boolean NalberoVuoto();
	void insRadice(typeElem);
	NodoNalbero* radice();
	NodoNalbero* padre(NodoNalbero*);
	boolean foglia(NodoNalbero*);
	NodoNalbero* primoFiglio(NodoNalbero*);
	boolean ultimoFratello(NodoNalbero*);
	NodoNalbero* succFratello(NodoNalbero*);
	void insPrimoFiglio(NodoNalbero*,typeElem);
	void insFratelloSucc(NodoNalbero*,typeElem);
	void canSottoNalbero(NodoNalbero*);
	typeElem leggiNodo(NodoNalbero*);
	void scriviNodo(NodoNalbero*,typeElem);

private:
	NodoNalbero* albero;
};




#endif /* NALBERO_H_ */
