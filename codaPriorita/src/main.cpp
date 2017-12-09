//============================================================================
// Name        : codaPriorita.cpp
// Author      : Angelo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include"prioriCoda.h"
#include"serviziCodaPri.h"
using namespace std;

int main() {
	PrioriCoda codaPri;
	autoAcquisizione(codaPri);
	//inserimento(codaPri);
	cout<<"Stampa PrioritaCoda: ";
	stampa(codaPri);
	cout<<endl;
	cout<<"Stampa Priorita: ";
	stampaPriorita(codaPri);
	cout<<endl;
	codaPri.cancellaMin();
	cout<<"cancellazione"<<endl;
	cout<<"Stampa PrioritaCoda: ";
	stampa(codaPri);
	cout<<endl;
	cout<<"Stampa Priorita: ";
	stampaPriorita(codaPri);
	cout<<endl;
	cout<<"Numero nodi: "<<codaPri.getNumeroNodi()<<endl;
	cout<<"Padre: "<<getPadre(codaPri,ricerca(codaPri,'n'))<<endl;
	cout<<"ricerca: "<<ricerca(codaPri,'c')<<endl;




	return 0;
}
