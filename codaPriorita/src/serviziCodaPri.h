/*
 * serviziCodaPri.h
 *
 *  Created on: 13 feb 2017
 *      Author: angelo
 */

#ifndef SERVIZICODAPRI_H_
#define SERVIZICODAPRI_H_
#include"prioriCoda.h"

void autoAcquisizione(PrioriCoda &);
void inserimento(PrioriCoda &);
void stampa(PrioriCoda &);
void stampaPriorita(PrioriCoda &);
typeElem getPadre(PrioriCoda &, int); //passa l'indice del nodo che vuoi sapere il padre
int ricerca(PrioriCoda &, typeElem);



#endif /* SERVIZICODAPRI_H_ */
