/*
 * T_queue.h
 *
 *  Created on: 31 gen 2017
 *      Author: angelo
 */

#ifndef T_QUEUE_H_
#define T_QUEUE_H_
#include<iostream>
#include<iomanip>
#include<assert.h>

using namespace std;

typedef bool boolean;
const int MAX =100;
template<class typeElem>
class Queue{

public:
	Queue();
	~Queue();
	void createQueue();
	boolean isEmpty();
	typeElem first();
	void enqueue(typeElem);
	void dequeue();

private:
	typeElem values[MAX];
	int start;
	int len;
};

template<class typeElem>
Queue<typeElem>::Queue(){
	createQueue();
}

template<class typeElem>
Queue<typeElem>::~Queue(){}

template<class typeElem>
void Queue<typeElem>::createQueue(){
	start = 0;
	len = 0;
}

template<class typeElem>
boolean Queue<typeElem>::isEmpty(){
	return(len<=0);
}

template<class typeElem>
typeElem Queue<typeElem>::first(){
	return values[start];
}

template<class typeElem>
void Queue<typeElem>::enqueue(typeElem a){
	if(len==MAX){
		cout<<"the queue is full, impossible insert the element"<<endl;
	}else{
		values[(start+len) % MAX] = a;
		len++;
	}
}

template<class typeElem>
void Queue<typeElem>::dequeue(){
	if(isEmpty()){
		cout<<"The queue is empty, impossible delete the element"<<endl;
	}else{
		start = (start+1) % MAX;
		len--;
	}
}

#endif /* T_QUEUE_H_ */
