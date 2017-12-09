//============================================================================
// Name        : T_nAlbero.cpp
// Author      : Angelo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include"serviziNalberoT.h"
using namespace std;

int main() {

		NalberoT<int> tree;
		//Autoacquisizione
		autoAcquisizione(tree);
		//Visite
		NodoNalberoT<int>* u = tree.radice();
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
		//Numero nodi
		cout<<"Conta Nodi: "<<getContaNodi(tree,u)<<endl;
		//Numero foglie
		cout<<"Conta Foglie: "<<getContaFoglie(tree,u)<<endl;
		//Profondità nodo
		cout<<"Profondita Nodo: "<<profonditaNodo(tree,(ricerca(tree,20)))<<endl;
		//Ricera
		cout<<"Ricerca: ";
		int x = 21;
		if(ricerca(tree,x)!=0)
			cout<<tree.leggiNodo(ricerca(tree,x))<<endl;
		//Altezza
		cout<<"Altezza: "<<altezza(tree,tree.radice())<<endl;
		//Cancellazione sottoAlbero
		tree.canSottoNalbero(tree.radice());
		cout<<"Ampiezza: ";
		ampiezza(tree,u);
		cout<<endl;
	return 0;
}
