/*
 * Node.h
 *
 *  Created on: 29 gen 2017
 *      Author: angelo
 */

#ifndef NODE_H_
#define NODE_H_

typedef int typeElem;
typedef class Node* position;

class Node{
public:
	Node();
	~Node();
	void setElement(typeElem);
	typeElem getElement();
	void setNextPtr(position);
	position getNextPtr();




private:
	typeElem element;
	position nextPtr;

};




#endif /* NODE_H_ */
