//============================================================================
// Name        : T_stack.cpp
// Author      : Angelo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<iomanip>
#include <iostream>
#include"serviceStackTemplate.h"
using namespace std;

int main() {
	Stack<int> stack;
	//ACQUISIZIONE
	autoAcquisition(stack);
	printStack(stack);
	//CANCELLAZIONE
	cancElement(stack);
	printStack(stack);
	//Numero elementi
	cout<<"Number of the elements: "<<numberElements(stack)<<endl;
	//RICERCA
	int x = 6;
	cout<<"Ricerca del valore: "<<x<<endl;
	if(searchElement(stack,x))
		cout<<"L'elemento esiste"<<endl;
	else
		cout<<"L'elemento non esiste"<<endl;

	return 0;
}
