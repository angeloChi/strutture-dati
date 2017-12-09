/*
 * nodeTemplate.h
 *
 *  Created on: 29 gen 2017
 *      Author: angelo
 */

#ifndef NODECODATEMPLATE_H_
#define NODECODATEMPLATE_H_
#include<iostream>
#include<iomanip>
using namespace std;

template<class typeElem>
class Node{
public:
	Node();
	~Node();
	typeElem getElement();
	void setElement(typeElem);
	Node<typeElem>* getNextPtr();
	void setNextPtr(Node<typeElem>*);

private:
	typeElem element;
	Node<typeElem>* nextPtr;

};



template<class typeElem>
Node<typeElem>::Node(){
	nextPtr = NULL;
	element = 0;
}

template<class typeElem>
Node<typeElem>::~Node(){}

template<class typeElem>
void Node<typeElem>::setElement(typeElem value){
	element = value;
}

template<class typeElem>
typeElem Node<typeElem>::getElement(){
	return element;
}

template<class typeElem>
void Node<typeElem>::setNextPtr(Node<typeElem>* succ){
	nextPtr = succ;
}

template<class typeElem>
Node<typeElem>* Node<typeElem>::getNextPtr(){
	return nextPtr;
}



#endif /* NODECODATEMPLATE_H_ */




