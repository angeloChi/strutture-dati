/*
 * node.cpp
 *
 *  Created on: 29 gen 2017
 *      Author: angelo
 */

#include<iostream>
#include<iomanip>

#include "Node.h"

using namespace std;

Node::Node(){
	nextPtr = NULL;
	element = 0;
}

Node::~Node(){}

void Node::setElement(typeElem value){
	element = value;
}

typeElem Node::getElement(){
	return element;
}

void Node::setNextPtr(position pos){
	nextPtr = pos;
}

position Node::getNextPtr(){
	return nextPtr;
}


