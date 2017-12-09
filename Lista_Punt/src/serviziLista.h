/*
 * serviziLista.h
 *
 *  Created on: 24 dic 2016
 *      Author: angelo
 */

#ifndef SERVIZILISTA_H_
#define SERVIZILISTA_H_
#include "Lista.h"



void acquisisciLista(Lista &);
void stampaLista(Lista &);
void insListap(Lista &, int, tipoElem);		//funzione per inserire in posizione qualsiasi
int numeroElem(Lista &);
void canc(Lista &,int);
posizione cerca(Lista &,tipoElem elem);
void svuotaLista(Lista &);



#endif /* SERVIZILISTA_H_ */
