//============================================================================
// Name        : queue_vector.cpp
// Author      : Angelo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include"service_queue.h"
using namespace std;

int main() {

	Queue<char> queue;
	//Acquisizione
	autoAcquisition(queue);
	printQueue(queue);
	//Cancellazione elemento
	cancElement(queue);
	printQueue(queue);
	//Numero di elemento;
	cout<<"Numero di elementi: "<<numberElements(queue)<<endl;
	//Ricerca
	char a = 'f';
	cout<<"Ricerca del valore: "<<a<<endl;
	if(searchElement(queue,a))
		cout<<"L'elemento esiste"<<endl;
	else
		cout<<"L'elemento non esiste"<<endl;

	return 0;
}
