//============================================================================
// Name        : Lista2.cpp
// Author      : Angelo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Nodo.h"
#include "Lista.h"
#include "serviziLista.h"


int main() {



						//PROVA LISTA

	//AUTO-ACQUISIZIONE
	cout<<"Auto-Acquisizione: "<<endl;
	Lista lista;
	acquisisciLista(lista);
	stampaLista(lista);
	cout<<endl;

	cout<<"Numero elementi della lista: "<<numeroElem(lista)<<endl;

	//INSERIMENTO IN POSIZIONE QUALSIASI
	int posizione = 6;
	int val = 6;
	cout<<endl<<"Inserimento in posizione:  "<<posizione<<endl;
	insListap(lista,posizione,val);
	stampaLista(lista);
	cout<<"Numero elementi della lista: "<<numeroElem(lista)<<endl;


	//CANCELLAZIONE IN POSIZIONE QUALSIASI
	cout<<endl<<"Cancellazione in posizione: "<<posizione<<endl;
	canc(lista,posizione);
	stampaLista(lista);
	cout<<"Numero elementi della lista: "<<numeroElem(lista)<<endl;


	//RICERCA ELEMENTO
	cout<<endl<<"Ricerca"<<endl;
	cerca(lista,5);

	svuotaLista(lista);
	stampaLista(lista);


	return 0;
}
