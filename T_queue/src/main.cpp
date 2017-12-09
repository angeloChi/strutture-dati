//============================================================================
// Name        : T_queue.cpp
// Author      : Angelo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include"serviceQueueTemplate.h"
using namespace std;

int main() {

	//Acquisizione
	Queue<int> queue;
	autoAcquisition(queue);
	printQueue(queue);
	//Cancellazione elemento
	cancElement(queue);
	printQueue(queue);
	//Ricerca elemento
	int i = 38;
	cout<<"Ricerca del valore: "<<i<<endl;
	if(searchElement(queue,i))
		cout<<"L'elemento esiste"<<endl;
	else
		cout<<"L'elemento non esiste"<<endl;

	return 0;
}
