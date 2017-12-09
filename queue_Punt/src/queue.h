/*
 * queue.h
 *
 *  Created on: 29 gen 2017
 *      Author: angelo
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include"Node.h"

typedef bool boolean;

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

	position head;
	position bottom;

};





#endif /* QUEUE_H_ */
