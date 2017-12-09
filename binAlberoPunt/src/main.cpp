
//============================================================================
// Name        : binAlberoPunt.cpp
// Author      : Angelo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include"serviziAlberoBin.h"
using namespace std;
int main() {

	//AUTOACQUISIZIONE
	BinAlbero tree;
	cout<<"Acquisizione"<<endl;
	autoAcquisizione(tree);
	NodoBinAlbero* u = tree.binRadice();

	//VISITE
	cout<<"pre-visista: ";
	preVisita(u,tree);
	cout<<endl;
	cout<<"post-visita: ";
	postVisita(u,tree);
	cout<<endl;
	cout<<"simmetrica: ";
	simmetrica(u,tree);
	cout<<endl;
	cout<<"ampiezza: ";
	ampiezza(tree);
	cout<<endl;

	//ACQUISIZIONE DA TASTIERA
	acquisizione(tree);
	cout<<"ampiezza: ";
	ampiezza(tree);
	cout<<endl;

	//RICERCHE
	cout<<"ricerca booleana binaria: ";
	cout<<searchBinariaBool(tree,20,u)<<endl;
	cout<<"ricerca binaria: ";
	cout<<tree.leggiNodo(searchBinaria(tree,100,u))<<endl;
	cout<<"massima profondita: ";
	cout<<maxProfondita(u,tree);
	cout<<endl;

	cout<<"Ricerca generale bool: ";
	cout<<searchBoolean(tree,100,u)<<endl;

	cout<<"Ricerca generale: ";
	if(search(tree,65,u)==0)
		cout<<"Non esiste il valore"<<endl;
	else
		cout<<tree.leggiNodo(search(tree,65,u))<<endl;

	cout<<"prova grado: ";
	cout<<getLevel(tree,u,91)<<endl;

	return 0;
}
