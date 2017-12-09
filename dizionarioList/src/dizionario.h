/*
 * dizionario.h
 *
 *  Created on: 15 feb 2017
 *      Author: angelo
 */

#ifndef DIZIONARIO_H_
#define DIZIONARIO_H_

#include<iostream>
#include<iomanip>
#include"tipoDizionario.h"
#include"listaDizionario/serviziListaTemplate.h"

#define DIM 100

using namespace std;

template<class T>
class Dizionario{
public:
	Dizionario();
	~Dizionario();
	void creaDizionario();
	boolean appartiene(TipoDizionario<T>);
	void inserisci(TipoDizionario<T>);
	void cancella(TipoDizionario<T>);
	Lista<TipoDizionario<T>*>* recupera(int);
	void aggiorna(TipoDizionario<T>, TipoDizionario<T>);

private:
	Lista<TipoDizionario<T>*> hashTable[DIM];
};

template<class T>
Dizionario<T>::Dizionario(){
     for(int i = 0; i<DIM ; i++)
          hashTable[i].creaLista();
}

template <class T>
Dizionario<T>::~Dizionario(){
}



template <class T>
void Dizionario<T>::creaDizionario(){
     Dizionario();
}

template <class T>
boolean Dizionario<T>::appartiene(TipoDizionario<T> elem){
     int pos = FunzioneHash(elem);
     Nodo<TipoDizionario<T>*>* tmp;
     if(hashTable[pos].listaVuota())
          return false;
     else
     {
         tmp = hashTable[pos].primoLista();
         while(elem.getKey() > hashTable[pos].leggiLista(tmp).getKey() && tmp != NULL)
              tmp = hashTable[pos].succLista(tmp);
         if(tmp == NULL)
              return false;
         else
              if(hashTable[pos].leggiLista(tmp).getKey() == elem.getKey())
                   return true;
              else
                   return false;
     }
}

template <class T>
void Dizionario<T>::inserisci(TipoDizionario<T> elem){
     int pos = FunzioneHash(elem);
     TipoDizionario<T>* nuovo = new TipoDizionario<T>();
     nuovo->setAttributo(elem.getAttributo());
     InsOrdine<TipoDizionario<T>*>(&hashTable[pos], nuovo);
}

template <class T>
void Dizionario<T>::cancella(TipoDizionario<T> elem){
     int pos = FunzioneHash(elem);
     Nodo<TipoDizionario<T>*>* tmp;
     if(!hashTable[pos].listaVuota())
     {
         tmp = hashTable[pos].primoLista();
         while(elem.getKey() > hashTable[pos].leggiLista(tmp).getKey() && tmp != NULL)
              tmp = hashTable[pos].succLista(tmp);
         if(tmp != NULL)
              if(hashTable[pos].leggiLista(tmp).getKey() == elem.getKey())
                   hashTable[pos].cancLista(tmp);
     }
}

template <class T>
Lista<TipoDizionario<T>*>* Dizionario<T>::recupera(int pos){//visualizza l'indirizzo in cui è memorizzata la posizione nella tabella hash
     return &hashTable[pos];
}

template <class T>
void Dizionario<T>::aggiorna(TipoDizionario<T> vecchio, TipoDizionario<T> nuovo){
     cancella(vecchio);
     inserisci(nuovo);
}

template <class T>
int FunzioneHash(TipoDizionario<T> elem){//PER AVERE LA POSIZIONE IN MODULO N
    int n = 0;

    for(int i = 0; elem.getKey()[i]!='\0' ; i++)
    {
       n = (((int)elem.getKey()[i])*(i+1)) + n;
    }
    int modulo = n-DIM;
    for(int i=0; modulo>0; i++)
          modulo = modulo-DIM;
    modulo = DIM + modulo;

    return modulo;
}


#endif /* DIZIONARIO_H_ */
