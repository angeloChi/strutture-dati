/*
 * Nodo.h
 *
 *  Created on: 21 dic 2016
 *      Author: angelo
 */

#ifndef NODO_H_
#define NODO_H_


typedef int tipoElem;
typedef class Nodo *posizione;


class Nodo{

public:
	Nodo();
	~Nodo();
	void setElemento(tipoElem);
	tipoElem getElemento();
	void setNextPtr(posizione);
	posizione getNextPtr();
	void setPrecPtr(posizione);
	posizione getPrecPtr();

private:

	tipoElem elemento;
	Nodo *nextPtr;
	Nodo *precPtr;

};


#endif /* NODO_H_ */
