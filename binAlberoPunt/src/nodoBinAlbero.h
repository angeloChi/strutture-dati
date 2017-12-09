/*
 * nodoBinAlbero.h
 *
 *  Created on: 02 feb 2017
 *      Author: angelo
 */

#ifndef NODOBINALBERO_H_
#define NODOBINALBERO_H_


typedef bool boolean;
typedef int typeElem;

class NodoBinAlbero{

public:
	NodoBinAlbero();
	~NodoBinAlbero();

	//padre
	void setPadre(NodoBinAlbero*);
	NodoBinAlbero* getPadre();

	//figlioSx
	void setFiglioSx(NodoBinAlbero*);
	NodoBinAlbero* getFiglioSx();

	//figlioDx
	void setFiglioDx(NodoBinAlbero*);
	NodoBinAlbero* getFiglioDx();

	//dato
	void setDato(typeElem);
	typeElem getDato();

private:
	NodoBinAlbero* padre;
	NodoBinAlbero* figlioSx;
	NodoBinAlbero* figlioDx;
	typeElem dato;

};




#endif /* NODOBINALBERO_H_ */
