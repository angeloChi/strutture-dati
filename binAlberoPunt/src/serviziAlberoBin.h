/*
 * serviziAlberoBin.h
 *
 *  Created on: 02 feb 2017
 *      Author: angelo
 */

#ifndef SERVIZIALBEROBIN_H_
#define SERVIZIALBEROBIN_H_
#include "binAlbero.h"
#include "queueTemplate.h"



//CONFRONTA TIPI
int confrontaTipi(typeElem a,typeElem b);

//ACQUISIZIONE
void autoAcquisizione(BinAlbero &);
void acquisizione(BinAlbero &);

//INSERIMENTO
void inserimentOrdinato(BinAlbero &, typeElem, NodoBinAlbero*);

//PROFONDITA
int maxProfondita(NodoBinAlbero*,BinAlbero &);  //Altezza albero
int getLevel(BinAlbero &, NodoBinAlbero*, typeElem);//grado nodo
int getLevelUtil(BinAlbero &,NodoBinAlbero*, typeElem, int);

//VISITE
void preVisita(NodoBinAlbero*, BinAlbero &);
void postVisita(NodoBinAlbero*, BinAlbero &);
void simmetrica(NodoBinAlbero*, BinAlbero &);
void ampiezza(BinAlbero &);

//RICERCA
NodoBinAlbero* searchBinaria(BinAlbero &, typeElem, NodoBinAlbero*); //Ricerca Binaria
boolean searchBinariaBool(BinAlbero &, typeElem, NodoBinAlbero*);//Ricerca Binaria booleana
boolean searchBool(BinAlbero &, typeElem, NodoBinAlbero*,boolean);//funzione d'appoggio per searchBoolean
boolean searchBoolean(BinAlbero &, typeElem, NodoBinAlbero*); //Ricerca generale boolean
NodoBinAlbero* search (BinAlbero&, typeElem, NodoBinAlbero*);//Ricerca generale che restituisce il nodo



//CONTANODI
int contaNodi(BinAlbero &, NodoBinAlbero*);


#endif /* SERVIZIALBEROBIN_H_ */
