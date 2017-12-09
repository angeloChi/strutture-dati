/*
 * nodoCodaPriorita.h
 *
 *  Created on: 12 feb 2017
 *      Author: angelo
 */

#ifndef NODOCODAPRIORITA_H_
#define NODOCODAPRIORITA_H_

typedef char typeElem;
typedef bool boolean;

class NodoCodaPriori{
public:
	NodoCodaPriori();
	~NodoCodaPriori();
	void setElemento(typeElem);
	typeElem getElemento();
	void setPriorita(int);
	int getPriorita();

private:
	typeElem elemento;
	int priorita;
};




#endif /* NODOCODAPRIORITA_H_ */
