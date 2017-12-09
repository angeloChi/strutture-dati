//============================================================================
// Name        : queue_Punt.cpp
// Author      : Angelo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include"serviceQueue.h"

int main() {

	Queue queue;
	autoAcquisition(queue);
	printQueue(queue);
	cout<<"Number of the elements queue: "<<numberElements(queue)<<endl;
	cancElement(queue);
	return 0;
}
