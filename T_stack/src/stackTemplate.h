/*
 * stackTemplate.h
 *
 *  Created on: 28 gen 2017
 *      Author: angelo
 */

#ifndef STACKTEMPLATE_H_
#define STACKTEMPLATE_H_
#include "nodeTemplate.h"
#include<assert.h>
using namespace std;

typedef bool boolean;

template<class typeElem>
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
	Node<typeElem>* head;
};

template<class typeElem>
Stack<typeElem>::Stack(){
	createStack();
}

template<class typeElem>
Stack<typeElem>::~Stack(){}

template<class typeElem>
void Stack<typeElem>::createStack(){
	head = NULL;
}

template<class typeElem>
boolean Stack<typeElem>::isEmpty(){
	return(head==NULL);
}

template<class typeElem>
typeElem Stack<typeElem>::top(){
	assert(!isEmpty());
	return head->getElement();
}

template<class typeElem>
void Stack<typeElem>::pop(){
	if(isEmpty())
		cout<<"The stack is empty"<<endl;
	else{
		Node<typeElem>* pos = head;
		head = head->getNextPtr();
		delete pos;
	}
}

template<class typeElem>
void Stack<typeElem>::push(typeElem value){
	Node<typeElem>* node = new Node<typeElem>();
	node->setElement(value);
	node->setNextPtr(head);
	head = node;
}

#endif /* STACKTEMPLATE_H_ */
