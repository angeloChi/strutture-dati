/*
 * BinAlbero.h
 *
 *  Created on: 02 feb 2017
 *      Author: angelo
 */

#ifndef BINALBERO_H_
#define BINALBERO_H_
#include"nodoBinAlbero.h"


class BinAlbero{
public:
	BinAlbero();
	~BinAlbero();
	void creaBinAlbero();
	boolean binAlberoVuoto();
	NodoBinAlbero* binRadice();
	NodoBinAlbero* Padre(NodoBinAlbero*);
	NodoBinAlbero* figlioSinistro(NodoBinAlbero*);
	NodoBinAlbero* figlioDestro(NodoBinAlbero*);
	boolean sinistroVuoto(NodoBinAlbero*);
	boolean destroVuoto(NodoBinAlbero*);
	typeElem leggiNodo(NodoBinAlbero*);
	void scriviNodo(NodoBinAlbero*,typeElem);
	void insRadice();
	void insFiglioSx(NodoBinAlbero*);
	void insFiglioDx(NodoBinAlbero*);
	void cancSottoBinAlbero(NodoBinAlbero*);

private:
	NodoBinAlbero* albero;
};





#endif /* BINALBERO_H_ */
