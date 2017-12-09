/*
 * tipoDizionario.h
 *
 *  Created on: 15 feb 2017
 *      Author: angelo
 */

#ifndef TIPODIZIONARIO_H_
#define TIPODIZIONARIO_H_

#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

template <class T>

class TipoDizionario {

public:
    TipoDizionario();
    ~TipoDizionario();
    string getKey();
    string getAttributo();
    void setAttributo(T);

private:
    T attributo; // attributo chiave

};


template <class T>
TipoDizionario<T>::TipoDizionario(){}


template <class T>
TipoDizionario<T>::~TipoDizionario(){}


template <class T>
string TipoDizionario<T>::getKey(){
       return getAttributo();
}


template <class T>
string TipoDizionario<T>::getAttributo(){
       return attributo;
}


template <class T>
void TipoDizionario<T>::setAttributo(T attributo){
     this->attributo = attributo;
}



#endif /* TIPODIZIONARIO_H_ */
