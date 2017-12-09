/*
 * serviziNalbero.h
 *
 *  Created on: 10 feb 2017
 *      Author: angelo
 */

#ifndef SERVIZINALBERO_H_
#define SERVIZINALBERO_H_
#include "nAlbero.h"



//ACQUISIZIONE
void autoAcquisizione(Nalbero &);
void acquisisciTastiera(Nalbero &);

//SUPPORTI
void esaminaNodo(NodoNalbero*, Nalbero &);
int confrontaTipo(typeElem, typeElem);
int calcolo(Nalbero &,NodoNalbero*, int, int);

//CONTEGGIO NODI
int getContaNodi(Nalbero &, NodoNalbero*);
int contaNodi(Nalbero &, NodoNalbero*, int);

//CONTEGGIO FOGLIE
int getContaFoglie(Nalbero &, NodoNalbero*);
int contaFoglie(Nalbero &, NodoNalbero*, int);

//PROFONDITA
int profonditaNodo(Nalbero &, NodoNalbero*);

//RICERCA
NodoNalbero* ricerca(Nalbero &,typeElem);

//ALTEZZA
int altezza(Nalbero &,NodoNalbero*);

//VISITA
void preVisita(Nalbero &, NodoNalbero*);
void postVisita(Nalbero &, NodoNalbero*);
void simmetrica(Nalbero &, NodoNalbero*);
void ampiezza(Nalbero &, NodoNalbero* u);

#endif /* SERVIZINALBERO_H_ */
