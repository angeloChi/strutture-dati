//============================================================================
// Name        : T_codaPriorita.cpp
// Author      : Angelo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include"serviziCodaPriT.h"
using namespace std;

int main() {
	PrioriCoda<char> priCoda;
	//AutoAcquisizione
	autoAcquisizione(priCoda);
	cout<<"Stampa valori: ";
	stampa(priCoda);
	cout<<endl;
	cout<<"Stampa Priorita: ";
	stampaPriorita(priCoda);
	cout<<endl;
	//Cancellazione del minimo
	cout<<"cancellazione"<<endl;
	priCoda.cancellaMin();
	cout<<"Stampa valori: ";
	stampa(priCoda);
	cout<<endl;
	cout<<"Stampa Priorita: ";
	stampaPriorita(priCoda);
	cout<<endl;
	//Ricerca
	cout<<"Ricerca: "<<ricerca(priCoda,'o')<<endl;
	//Padre
	cout<<"Padre: "<<getPadre(priCoda,ricerca(priCoda,'o'))<<endl;
	return 0;
}
