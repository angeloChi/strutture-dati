/*
 * serviziDizionario.h
 *
 *  Created on: 15 feb 2017
 *      Author: angelo
 */

#ifndef SERVIZIDIZIONARIO_H_
#define SERVIZIDIZIONARIO_H_


#include "dizionario.h"

// Ricerca un elemento del dizionario
template <class T>
TipoDizionario<T>* Ricerca(Dizionario<T>*, T);

// Stampa il dizionario
template <class T>
void StampaDizionario(Dizionario<T>&);

template <class T>
TipoDizionario<T>* Ricerca(Dizionario<T>* D, T key)
{
     TipoDizionario<T> elem = TipoDizionario<T>();
     elem.setAttributo(key);
     int pos = FunzioneHash(elem);
     Lista<TipoDizionario<T>*>* L = D->recupera(pos);
     Nodo<TipoDizionario<T>*>* tmp = NULL;
     if(L != NULL)
     {
         if(!L->listaVuota())
         {
             tmp = L->primoLista();
             while(tmp != NULL)
             {
                  if(L->leggiLista(tmp)->getKey() == elem.getKey())
                      return tmp->getElemento();
                  tmp = L->succLista(tmp);
             }
         }
     }

     if(tmp != NULL)
          return tmp->getElemento();
     else
          return NULL;
}



template <class T>
void StampaDizionario(Dizionario<T>* D)
{
     for(int i=0 ; i<DIM; i++)
     {
          if( !D->recupera(i)->listaVuota() )
          {
               cout<<i<<"  ";
               StampaLista(D->recupera(i));
          }
     }
}


#endif /* SERVIZIDIZIONARIO_H_ */
