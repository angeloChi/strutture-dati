/*
 * serviceQueue.cpp
 *
 *  Created on: 29 gen 2017
 *      Author: angelo
 */
#include<iostream>
#include<iomanip>
#include"serviceQueue.h"

using namespace std;

void autoAcquisition(Queue &queue){

	queue.createQueue();

	typeElem i = 9;
	queue.enqueue(i);

	i= 38;
	queue.enqueue(i);

	i = 56;
	queue.enqueue(i);

	i = 74;
	queue.enqueue(i);

	i = 83;
	queue.enqueue(i);

}

void printQueue(Queue &queue){
	Queue temp;
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

void empty(Queue &queue){
	if(queue.isEmpty()){
		cout<<"The queue is empty"<<endl;
	}else{
		while(!queue.isEmpty()){
			queue.dequeue();
		}
	}
}

int numberElements(Queue &queue){
	int i = 0;
	Queue temp;
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

void cancElement(Queue &queue){
	Queue temp;
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

boolean searchElement(Queue &queue, typeElem key){
	Queue temp;
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





