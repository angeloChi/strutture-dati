/*
 * stack.cpp
 *
 *  Created on: 27 gen 2017
 *      Author: angelo
 */
#include<iomanip>
#include<iostream>
#include"stack.h"
#include<assert.h>

using namespace std;

Stack::Stack(){
	createStack();
}

void Stack::createStack(){
	head = NULL;
}

Stack::~Stack(){}


boolean Stack::isEmpty(){
	return(head==NULL);
}

typeElem Stack::top(){
	assert(!isEmpty());
	return head->getElement();
}

void Stack::pop(){
	if(isEmpty())
		cout<<"The stack is empty"<<endl;
	else{
		position pos = head;
		head = head->getNextPtr();
		delete pos;
	}
}

void Stack::push(typeElem value){
	Node *node = new Node();
	node->setElement(value);
	node->setNextPtr(head);
	head = node;
}

