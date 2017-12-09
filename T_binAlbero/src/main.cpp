//============================================================================
// Name        : T_binAlbero.cpp
// Author      : Angelo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "serviziBinAlberoTemplate.h"
using namespace std;

int main() {
	BinAlberoT<int> tree;
	//Autoacquisizione
	cout<<"Auto-acquisizione"<<endl;
	autoAcquisizione(tree);
	//Visite
	NodoBinAlberoT<int>* u = tree.binRadice();
	cout<<"Pre-visita: ";
	preVisita(u,tree);
	cout<<endl;
	cout<<"Post-visita: ";
	postVisita(u,tree);
	cout<<endl;
	cout<<"Simmetrica: ";
	simmetrica(u,tree);
	cout<<endl;
	cout<<"Ampiezza: ";
	ampiezza(tree);
	cout<<endl;
	//Inserimento da tastiera
	acquisizione(tree);
	//Visita in ampiezza
	cout<<"Ampiezza: ";
	ampiezza(tree);
	cout<<endl;
	//RicercaBinaria bool
	cout<<"Ricerca Binaria bool: ";
	cout<<searchBinariaBool(tree,20,u)<<endl;
	//Ricerca binaria che restituisce un nodo
	cout<<"Ricerca binaria normale :";
	cout<<tree.leggiNodo(searchBinaria(tree,91,u))<<endl;  //restituisce il padre di 91 (anche se 91 non esiste)
	//Ricerca normale booleana
	cout<<"Ricerca generale bool: ";
	cout<<searchBoolean(tree,17,u)<<endl;
	//Ricerca generale che restituisce un nodo
	cout<<"Ricerca generale: ";
	if(search(tree,91,u)==0)
		cout<<"Non esiste"<<endl;
	else
		cout<<tree.leggiNodo(search(tree,91,u))<<endl;
	//Numero nodi
	cout<<"Conta nodi: ";
	cout<<contaNodi(tree,u)<<endl;
	//Profondità albero
	cout<<"max profondità: ";
	cout<<maxProfondita(tree.binRadice(),tree)<<endl;
	//Levello di un nodo
	cout<<"Livello nodo: ";
	cout<<getLevel(tree,u,82)<<endl;

	return 0;
}
