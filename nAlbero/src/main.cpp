//============================================================================
// Name        : nAlbero.cpp
// Author      : Angelo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "serviziNalbero.h"

using namespace std;

int main() {
	Nalbero tree;
	//autoAcquisizione(tree);

	acquisisciTastiera(tree);
	NodoNalbero* u = tree.radice();
	cout<<"PreVisita: ";
	preVisita(tree,u);
	cout<<endl;
	cout<<"PostVisita: ";
	postVisita(tree,u);
	cout<<endl;
	cout<<"Simmetrica: ";
	simmetrica(tree,u);
	cout<<endl;
	cout<<"Ampiezza: ";
	ampiezza(tree,u);
	cout<<endl;
	cout<<"Conta Nodi: "<<getContaNodi(tree,u)<<endl;
	cout<<"Conta Foglie: "<<getContaFoglie(tree,u)<<endl;
	cout<<"Profondita Nodo: "<<profonditaNodo(tree,(ricerca(tree,20)))<<endl;
	cout<<"Ricerca: ";
	typeElem x = 21;
	if(ricerca(tree,x)!=0)
		cout<<tree.leggiNodo(ricerca(tree,x))<<endl;

	cout<<"Altezza: "<<altezza(tree,tree.radice())<<endl;

	tree.canSottoNalbero(tree.radice());
	cout<<"Ampiezza: ";
		ampiezza(tree,u);
		cout<<endl;




	return 0;
}
