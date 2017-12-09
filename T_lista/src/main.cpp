//============================================================================
// Name        : T_lista.cpp
// Author      : Angelo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include"serviziListaTemplate.h"
using namespace std;

typedef Nodo<char>* posizione;

int main() {

	Lista<char,posizione> lista;

	//ACQUISIZIONE E STAMPA LISTA
	acquisisciLista(lista);
	stampaLista(lista);
	//Inserimento nella lista in seconda posizione
	char dato = 'a';
	cout<<"Inserimento del valore: "<<dato<<" in seconda posizione"<<endl;
	lista.insLista(dato,lista.succLista(lista.primoLista()));
	stampaLista(lista);
	//Inserimento nella lista mediande inListap
	dato = 'l';
	int i = 3;
	cout<<"Inserimento del valore: "<<dato<<" in posizione "<<i<<endl;
	insListap(lista,i,dato);
	insListap(lista,i,dato);
	stampaLista(lista);
	//Ordinamento della
	lista = mergeSort(lista);
	cout<<"Stampa lista ordinata: "<<endl;
	stampaLista(lista);
	//Eliminazione doppioni
	cout<<"Elminazione doppioni: "<<endl;
	epurazione(lista);
	stampaLista(lista);
	//Cancellazione primo valore
	cout<<"Cancellazione primo elemento: "<<endl;
	lista.cancLista(lista.primoLista());
	stampaLista(lista);
	//Numero elementi
	cout<<"Numero elementi: "<<numeroElem(lista)<<endl;
	//Ricerca
	cerca(lista,'k');

	return 0;
}
