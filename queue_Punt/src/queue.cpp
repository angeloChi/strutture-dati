/*
 * queue.cpp
 *
 *  Created on: 29 gen 2017
 *      Author: angelo
 */

#include<iostream>
#include<iomanip>
#include<assert.h>
#include"queue.h"

using namespace std;

Queue::Queue(){
	createQueue();
}

Queue::~Queue(){}

void Queue::createQueue(){
	head = NULL;
	bottom = NULL;
}


boolean Queue::isEmpty(){
	return(head==NULL ? true : false);
}

typeElem Queue::first(){
	assert(!isEmpty());
	return head->getElement();
}

void Queue::dequeue(){
	assert(!isEmpty());
	position temp = head;
	head = head->getNextPtr();
	delete temp;

}

void Queue::enqueue(typeElem value){
	Node* newNode = new Node();
	newNode->setElement(value);
	newNode->setNextPtr(NULL);
	if(isEmpty()){
		head = newNode;
		bottom = head;
	}else{
		bottom->setNextPtr(newNode);
		bottom = newNode;

	}
}
