/*
 * serviceStackTemplate.h
 *
 *  Created on: 28 gen 2017
 *      Author: angelo
 */

#ifndef SERVICESTACKTEMPLATE_H_
#define SERVICESTACKTEMPLATE_H_
#include"stackTemplate.h"

using namespace std;

template<class typeElem>
void autoAcquisition(Stack<typeElem> &stack){
	stack.createStack();
	typeElem value = 5;
	stack.push(value);

	value = 6;
	stack.push(value);

	value = 85;
	stack.push(value);

	value = 96;
	stack.push(value);

	value = 33;
	stack.push(value);
}

template<class typeElem>					//Stampa dello stack
void printStack(Stack<typeElem> &stack){
	Stack<typeElem> temp;
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

template<class typeElem>
int numberElements(Stack<typeElem> &stack){		//Numero di elementi
	int i=0;
	Stack<typeElem> temp;
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

template<class typeElem>
boolean searchElement(Stack<typeElem> &stack, typeElem key){
	Stack<typeElem> temp;			//stack di appoggio
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

template<class typeElem>
void empty(Stack<typeElem> &stack){
	while(!stack.isEmpty())
		stack.pop();
}

template<class typeElem>
void cancElement(Stack<typeElem> &stack){			//Cancellazione di un elemento qualsiasi
	Stack<typeElem> temp;
	typeElem x;
	boolean found = false;
	cout<<"Insert the element to be delete"<<endl;
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

#endif /* SERVICESTACKTEMPLATE_H_ */
