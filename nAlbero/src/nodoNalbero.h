/*
 * nodo.h
 *
 *  Created on: 10 feb 2017
 *      Author: angelo
 */

#ifndef NODONALBERO_H_
#define NODONALBERO_H_

typedef int typeElem;
typedef bool boolean;

class NodoNalbero{
public:
	NodoNalbero();
	~NodoNalbero();

	//DATO
	void setDato(typeElem);
	typeElem getDato();

	//PRIMOFIGLIO
	void setPrimoFiglio(NodoNalbero*);
	NodoNalbero* getPrimoFiglio();

	//FRATELLOsUCC
	void setSuccFratello(NodoNalbero*);
	NodoNalbero* getSuccFratello();

	//PADRE
	void setPadre(NodoNalbero*);
	NodoNalbero* getPadre();

private:
	typeElem dato;
	NodoNalbero* primoFiglio;
	NodoNalbero* succFratello;
	NodoNalbero* padre;
};




#endif /* NODONALBERO_H_ */
