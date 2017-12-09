/*
 * T_queue.h
 *
 *  Created on: 29 gen 2017
 *      Author: angelo
 */

#ifndef QUEUETEMPLATE_H_
#define QUEUETEMPLATE_H_
#include<iostream>
#include<iomanip>
#include<assert.h>
#include"nodeCodaTemplate.h"

using namespace std;
typedef bool boolean;

template<class typeElem>
class Queue{
public:
	Queue();
	~Queue();
	void createQueue();
	boolean isEmpty();
	typeElem first();
	void dequeue();
	void enqueue(typeElem);

private:

	Node<typeElem>* head;
	Node<typeElem>* bottom;


};

template<class typeElem>
Queue<typeElem>::Queue(){
	createQueue();
}

template<class typeElem>
Queue<typeElem>::~Queue(){}

template<class typeElem>
void Queue<typeElem>::createQueue(){
	head = NULL;
	bottom = NULL;
}

template<class typeElem>
boolean Queue<typeElem>::isEmpty(){
	return(head==NULL ? true : false);
}

template<class typeElem>
typeElem Queue<typeElem>::first(){
	assert(!isEmpty());
	return head->getElement();
}

template<class typeElem>
void Queue<typeElem>::dequeue(){
	assert(!isEmpty());
	Node<typeElem>* temp = head;
	head = head->getNextPtr();
	delete temp;

}

template<class typeElem>
void Queue<typeElem>::enqueue(typeElem value){
	Node<typeElem>* newNode = new Node<typeElem>;
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
#endif /* QUEUETEMPLATE_H_ */
