/*
 * service_queue.h
 *
 *  Created on: 31 gen 2017
 *      Author: angelo
 */

#ifndef SERVICE_QUEUE_H_
#define SERVICE_QUEUE_H_

#include"T_queue.h"

using namespace std;

template<class typeElem>
void autoAcquisition(Queue<typeElem> &queue){
	queue.createQueue();
	for(typeElem i = 'a'; i<='h'; i++)
		queue.enqueue(i);
}

template<class typeElem>
void printQueue(Queue<typeElem> &queue){
	Queue<typeElem> temp;
	if(queue.isEmpty()){
		cout<<"The queue is empty"<<endl;
	}else{
		while(!queue.isEmpty()){
			temp.enqueue(queue.first());
			cout<<queue.first()<<endl; //print vertical
			queue.dequeue();
		}
		while(!temp.isEmpty()){
			//cout<<temp.first()<<" "; //print horizontal
			queue.enqueue(temp.first());
			temp.dequeue();
		}
	}
	cout<<endl;
}

template<class typeElem>
void empty(Queue<typeElem> &queue){
	if(queue.isEmpty()){
		cout<<"The queue is empty"<<endl;
	}else{
		while(!queue.isEmpty()){
			queue.dequeue();
		}
	}
}

template<class typeElem>
int numberElements(Queue<typeElem> &queue){
	int i = 0;
	Queue<typeElem> temp;
	if(queue.isEmpty()){
		cout<<"The queue is empty"<<endl;
	}else{
		while(!queue.isEmpty()){
			temp.enqueue(queue.first());
			queue.dequeue();
		}
		while(!temp.isEmpty()){
			queue.enqueue(temp.first());
			i++;
			temp.dequeue();
		}
	}
	return i;
}

template<class typeElem>
void cancElement(Queue<typeElem> &queue){
	Queue<typeElem> temp;
	typeElem x,info;
	boolean found = false;
	if(queue.isEmpty()){
		cout<<"The queue is empty"<<endl;
	}else{
		cout<<"Insert the element to delete"<<endl;
		cin>>x;
		while(!queue.isEmpty() ){
			info = queue.first();
			queue.dequeue();
			if(info==x){
				found = true;
				cout<<"Delete item"<<endl;
			}else{
				temp.enqueue(info);
			}
		}if(!found){
			cout<<"Element doesn't exist "<<endl;
		}while(!temp.isEmpty()){
			info = temp.first();
			queue.enqueue(info);
			temp.dequeue();
		}
	}
}

template<class typeElem>
boolean searchElement(Queue<typeElem> &queue, typeElem key){
	Queue<typeElem> temp;
	boolean found = false;

	if(queue.isEmpty()){
		cout<<"the queue is empty"<<endl;
	}else{
		while(!queue.isEmpty()){
			temp.enqueue(queue.first());
			if(queue.first()==key){
				found = true;
			}
			queue.dequeue();
		}
		while(!temp.isEmpty()){
			queue.enqueue(temp.first());
			temp.dequeue();
		}
	}
	return found;
}

#endif /* SERVICE_QUEUE_H_ */
