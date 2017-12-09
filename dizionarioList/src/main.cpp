//============================================================================
// Name        : dizionarioList.cpp
// Author      : Angelo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include"serviziDizionario.h"
using namespace std;

int main() {
	Dizionario<string> D = Dizionario<string>();
	    TipoDizionario<string> array[10];
	    int i;
	    for(i=0; i<10; i++)
	         array[i] = TipoDizionario<string>();

	    array[0].setAttributo("A");
	    array[1].setAttributo("B");
	    array[2].setAttributo("C");
	    array[3].setAttributo("D");
	    array[4].setAttributo("E");
	    array[5].setAttributo("F");
	    array[6].setAttributo("G");
	    array[7].setAttributo("H");
	    array[8].setAttributo("A5");
	    array[9].setAttributo("A4");

	    cout<<"FunzioneHash "<<FunzioneHash(array[0]);
	    cout<<endl;
	    cout<<"FunzioneHash "<<FunzioneHash(array[1]);
	    cout<<endl;
	    cout<<"FunzioneHash "<<FunzioneHash(array[2]);
	    cout<<endl;
	    cout<<"FunzioneHash "<<FunzioneHash(array[3]);
	    cout<<endl;
	    cout<<"FunzioneHash "<<FunzioneHash(array[4]);
	    cout<<endl;
	    cout<<"FunzioneHash "<<FunzioneHash(array[5]);
	    cout<<endl;
	    cout<<"FunzioneHash "<<FunzioneHash(array[6]);
	    cout<<endl;
	    cout<<"FunzioneHash "<<FunzioneHash(array[7]);
	    cout<<endl;
	    cout<<"FunzioneHash "<<FunzioneHash(array[8]);
	    cout<<endl;
	    cout<<"FunzioneHash "<<FunzioneHash(array[9]);
	    cout<<endl;

	   for(i=0 ; i<10; i++)
	         D.inserisci(array[i]);

	    cout<<endl<<endl;
	    cout<<"FunzioneHash(A): "<<FunzioneHash(array[1])<<endl<<endl;
	    cout<<endl<<endl;

	    cout<<"StampaDizionario..."<<endl;
	    StampaDizionario(&D);

	    cout<<endl<<endl;

	    cout<<"Ricerca(F): "<<Ricerca<string>(&D,"F");
	    if(Ricerca<string>(&D,"F") != NULL )
	         cout<<" contiene: "<<Ricerca<string>(&D,"F")->getKey()<<" ";
	    else cout<<" non esiste ";

	    cout<<endl<<endl;

	    cout<<"Ricerca(A5): "<<Ricerca<string>(&D,"A5");
	    if(Ricerca<string>(&D,"A5") != NULL )
	         cout<<" contiene: "<<Ricerca<string>(&D,"A5")->getKey()<<" ";
	    else cout<<" non esiste ";


	    cout<<endl<<endl;

	    cout<<"Recupera: "<<D.recupera(2);
	    cout<<endl;




	return 0;
}
