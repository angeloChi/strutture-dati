//============================================================================
// Name        : Stack_Punt.cpp
// Author      : Angelo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "serviceStack.h"
using namespace std;


int main() {
	Stack stack;
	autoAcquisition(stack);
	printStack(stack);
	cout<<"Number of the elements"<<" "<<numberElements(stack)<<endl;
	cancElement(stack);
	printStack(stack);
	cout<<"Number of the elements"<<" "<<numberElements(stack)<<endl;
	return 0;
}
