/*
 * serviceStack.cpp
 *
 *  Created on: 27 gen 2017
 *      Author: angelo
 */
#include<iostream>
#include<iomanip>
#include <stdlib.h>
#include"serviceStack.h"


using namespace std;

void autoAcquisition(Stack &stack){
	stack.createStack();
	typeElem value = 5;
	stack.push(value);

	value = 6;
	stack.push(value);

	value = 85;
	stack.push(value);

	value = 96;
	stack.push(value);

	value = 88;
	stack.push(value);

}



void printStack(Stack &stack){
	Stack temp;
	if(stack.isEmpty()){
		cout<<"The stack is empty"<<endl;
	}else{
		while(!stack.isEmpty()){
				temp.push(stack.top());
				cout<<temp.top()<<endl; //print vertical
				stack.pop();

		}while(!temp.isEmpty()){
			//cout<<temp.top()<<" ";  //print horizontal
			stack.push(temp.top());
			temp.pop();
		}
	}

	cout<<endl;
}

int numberElements(Stack &stack){
	int i=0;
	Stack temp;
	while(!stack.isEmpty()){
		temp.push(stack.top());
		stack.pop();
		i++;
	}while(!temp.isEmpty()){
		stack.push(temp.top());
		temp.pop();
	}
	return i;
}

boolean searchElement(Stack &stack, typeElem key){
	Stack temp;
	boolean found = false;
	if(!stack.isEmpty()){
		while(!stack.isEmpty() && !found){
			temp.push(stack.top());
			stack.pop();
			if(temp.top()==key)
				found = true;
		}while(!temp.isEmpty()){
			stack.push(temp.top());
			temp.pop();
		}
	}
	return found;
}

void empty(Stack &stack){
	while(!stack.isEmpty())
		stack.pop();
}

void cancElement(Stack &stack){
	Stack temp;
	typeElem x;
	boolean found = false;
	cout<<"Insert the element to delete"<<endl;
	cin>>x;
	if(!stack.isEmpty()){
		while(!stack.isEmpty() && !found){
					temp.push(stack.top());
					stack.pop();
					if(temp.top()==x){
						found = true;
						temp.pop();
						cout<<"Deleted item"<<endl;
					}
				}if(!found){
					cout<<"Element doesn't exist "<<endl;
				}while(!temp.isEmpty()){
					stack.push(temp.top());
					temp.pop();
				}

	}

}
