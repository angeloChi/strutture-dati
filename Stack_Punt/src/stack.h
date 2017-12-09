/*
 * stack.h
 *
 *  Created on: 27 gen 2017
 *      Author: angelo
 */

#ifndef STACK_H_
#define STACK_H_
#include "Node.h"
typedef bool boolean;

class Stack{
public:
	Stack();
	~Stack();
	void createStack();
	boolean isEmpty();
	typeElem top();
	void push(typeElem);
	void pop();

private:
	Node* head;

};




#endif /* STACK_H_ */
