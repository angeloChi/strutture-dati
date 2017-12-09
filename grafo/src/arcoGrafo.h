/*
 * arcoGrafo.h
 *
 *  Created on: 17 feb 2017
 *      Author: angelo
 */

#ifndef ARCOGRAFO_ARCOGRAFO_H_
#define ARCOGRAFO_ARCOGRAFO_H_
#include"cellaGrafo.h"

class ArcoGrafo{
public:
	ArcoGrafo();
	~ArcoGrafo();
	void setNodoPartenza(CellaGrafo*);
	CellaGrafo* getNodoPartenza();
	void setNodoArrivo(CellaGrafo*);
	CellaGrafo* getNodoArrivo();
	void setInfoArco(tipoArco);
	tipoArco getInfoArco();

private:

	CellaGrafo* nodoPartenza;
	CellaGrafo* nodoArrivo;
	tipoArco infoArco;

};


#endif /* ARCOGRAFO_ARCOGRAFO_H_ */
