/*
 * arcoGrafoTemplate.h
 *
 *  Created on: 18 feb 2017
 *      Author: angelo
 */

#ifndef ARCOGRAFOTEMPLATE_H_
#define ARCOGRAFOTEMPLATE_H_
#include"cellaGrafoTemplate.h"

template<class tipoArco, class tipoNodo>
class ArcoGrafo{
public:
	ArcoGrafo();
	~ArcoGrafo();
	void setNodoPartenza(CellaGrafo<tipoNodo>*);
	CellaGrafo<tipoNodo>* getNodoPartenza();
	void setNodoArrivo(CellaGrafo<tipoNodo>*);
	CellaGrafo<tipoNodo>* getNodoArrivo();
	void setInfoArco(tipoArco);
	tipoArco getInfoArco();

private:
	CellaGrafo<tipoNodo>* nodoPartenza;
	CellaGrafo<tipoNodo>* nodoArrivo;
	tipoArco infoArco;
};


template<class tipoArco, class tipoNodo>
ArcoGrafo<tipoArco,tipoNodo>::ArcoGrafo(){
	nodoPartenza = NULL;
	nodoArrivo = NULL;
}

template<class tipoArco, class tipoNodo>
ArcoGrafo<tipoArco,tipoNodo>::~ArcoGrafo(){}

template<class tipoArco, class tipoNodo>
void ArcoGrafo<tipoArco,tipoNodo>::setNodoPartenza(CellaGrafo<tipoNodo>* partenza){
	nodoPartenza = partenza;
}

template<class tipoArco, class tipoNodo>
CellaGrafo<tipoNodo>* ArcoGrafo<tipoArco,tipoNodo>::getNodoPartenza(){
	return nodoPartenza;
}

template<class tipoArco, class tipoNodo>
void ArcoGrafo<tipoArco,tipoNodo>::setNodoArrivo(CellaGrafo<tipoNodo>* arrivo){
	nodoArrivo = arrivo;
}

template<class tipoArco, class tipoNodo>
CellaGrafo<tipoNodo>* ArcoGrafo<tipoArco,tipoNodo>::getNodoArrivo(){
	return nodoArrivo;
}

template<class tipoArco, class tipoNodo>
void ArcoGrafo<tipoArco,tipoNodo>::setInfoArco(tipoArco arco){
	infoArco = arco;
}

template<class tipoArco, class tipoNodo>
tipoArco ArcoGrafo<tipoArco,tipoNodo>::getInfoArco(){
	return infoArco;
}
#endif /* ARCOGRAFOTEMPLATE_H_ */
