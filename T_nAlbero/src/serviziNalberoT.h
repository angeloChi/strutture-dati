/*
 * serviziNalberoT.h
 *
 *  Created on: 11 feb 2017
 *      Author: angelo
 */

#ifndef SERVIZINALBEROT_H_
#define SERVIZINALBEROT_H_
#include"nAlberoT.h"
#include"queueTemplate.h"

using namespace std;

template<class S>
void autoAcquisizione(NalberoT<S> &T){
	T.creaAlbero();
	NodoNalberoT<S>* u = new NodoNalberoT<S>;

	T.insRadice(5);

	u = T.radice();
	T.insPrimoFiglio(u,4);

	u = T.primoFiglio(u);
	T.insFratelloSucc(u,15);

	u = T.succFratello(u);
	T.insFratelloSucc(u,6);

	u = T.succFratello(u);
	T.insPrimoFiglio(u,21);

	u = T.primoFiglio(u);
	T.insFratelloSucc(u,20);

	u = T.primoFiglio(T.radice());
	T.insPrimoFiglio(u,8);

	u = T.primoFiglio(u);
	T.insFratelloSucc(u,9);

	u = T.succFratello(u);
	T.insPrimoFiglio(u,12);

	u = T.primoFiglio(u);
	T.insFratelloSucc(u,11);

	u = T.succFratello(u);
	T.insFratelloSucc(u,3);
}

template<class S>
void acquisisciTastiera(NalberoT<S> &T){
    Queue<NodoNalberoT<S>*> tmp;
    bool finito;
    NodoNalberoT<S>* aux;
    S info,infoPrimoFiglio;
	char risp;
	cout << "Inserisci l'elemento che devi mettere nella radice: " << endl;
	cin >> info;
    T.insRadice(info);
    aux = T.radice();
    tmp.enqueue(aux);
    while(!tmp.isEmpty()) {
       aux=tmp.first();
       tmp.dequeue();
       cout<<"Se vuoi inserire il primofiglio di "<<aux->getDato()<<" premi S altrimenti N:";
       do {
          cin>>risp;
       } while(toupper(risp)!='S' && toupper(risp)!='N');

       if (toupper(risp) == 'S') {
   		  cout<<"Inserisci il primofiglio di "<<aux->getDato()<<": ";
       	  cin>>info;
          cout<<endl;
          T.insPrimoFiglio(aux,info);
          aux=T.primoFiglio(aux);
          tmp.enqueue(aux);
          infoPrimoFiglio=info;
          do {
            finito=true;
           	cout<<"Per inserire un fratello di "<<infoPrimoFiglio<<" premi S altrimenti N: ";
	        do {
               cin>>risp;
            } while(toupper(risp)!='S'&& toupper(risp)!='N');
      		if (toupper(risp)=='S') {
               cout<<"Il fratello di "<<infoPrimoFiglio<<" e': ";
			   cin>>info;
               cout<<endl;
               T.insFratelloSucc(aux,info);
               aux=T.succFratello(aux);
               tmp.enqueue(aux);
				infoPrimoFiglio=info;
            finito=false;
            }
         } while(!finito);
      }
   }

}

//SUPPORTO
template<class S>
void esaminaNodo(NodoNalberoT<S>* u, NalberoT<S> &T) {
	if (u!=NULL)
		cout << T.leggiNodo(u) << "  ";
}

template<class S>
int confrontaTipo(S a, S b) {
	int conf;
	if(a<b)
		conf = -1;
	if(a==b)
		conf = 0;
	if(a>b)
		conf = 1;
	return conf;
}

//Funzione di appoggio per getContaNodi
template<class S>
int contaNodi(NalberoT<S> &T, NodoNalberoT<S>* u, int i){
	NodoNalberoT<S>* c;
	if(u==NULL)
		return 0;
	if(!T.NalberoVuoto()){
		i++;
		if(!T.foglia(u)){
			c = T.primoFiglio(u);
			while(!T.ultimoFratello(c)){
				i = contaNodi(T,c,i);
				c = T.succFratello(c);
			}
			i =  contaNodi(T,c,i);
		}
	}
	return i;
}

//Numero nodi
template<class S>
int getContaNodi(NalberoT<S> &T,NodoNalberoT<S>* u){
	return contaNodi(T,u,0);
}

//Funzione d'appoggio per getContaFoglie
template<class S>
int contaFoglie(NalberoT<S> &T, NodoNalberoT<S>* u, int i){
	NodoNalberoT<S>* c;
	if(!T.NalberoVuoto() && u!=NULL){
		if(T.foglia(u))
			i++;
		else{
			c = T.primoFiglio(u);
			while(!T.ultimoFratello(c)){
				i = contaFoglie(T,c,i);
				c = T.succFratello(c);
			}
			i = contaFoglie(T,c,i);
		}
	}
	return i;
}

//Numero foglie
template<class S>
int getContaFoglie(NalberoT<S> &T, NodoNalberoT<S>* u){
	return contaFoglie(T,u,0);
}

//PROFONDITA
template<class S>
int profonditaNodo(NalberoT<S> &T, NodoNalberoT<S>* u){
	if(T.radice()==u)
		return 0;
	else
		return 1+ profonditaNodo(T, T.padre(u));

}

//Ricerca che restituisce un nodo
template<class S>
NodoNalberoT<S>* ricerca(NalberoT<S> &T, S x){
	S s;
    NodoNalberoT<S>* rad = new NodoNalberoT<S>();
    NodoNalberoT<S>* temp= new NodoNalberoT<S>();
    boolean trovato = false;
    Queue<NodoNalberoT<S>*> cod;
    rad = T.radice();
    if (rad->getDato() == x)
    	return rad;
    cod.enqueue(rad);
    while (!cod.isEmpty() && trovato == false) {
    	temp = cod.first();
        s = temp->getDato();
        cod.dequeue();
        if (s == x) {
        	trovato = true;
            	return temp;
        } else if (!T.foglia(temp)) {
        	temp = T.primoFiglio(temp);
            while (!T.ultimoFratello(temp)) {
            	cod.enqueue(temp);
                temp = T.succFratello(temp);
            }
            cod.enqueue(temp);
        }
    }
    if (cod.isEmpty())
    	cout << "elemento non prensente" << endl;
    return NULL;
}

//Funzione d'appoggio per altezza
template<class S>
int calcolo(NalberoT<S> &T,NodoNalberoT<S>* u, int temp, int max) {
    NodoNalberoT<S>* c;
    if (T.foglia(u)) {
    	if (temp >= max)
    		max = temp;
     } else {
             temp++;
             {
            	 c = T.primoFiglio(u);
                 while (!T.ultimoFratello(c)) {
                	 max = calcolo(T,c,temp,max);
                     c = T.succFratello(c);
                 }
                     max = calcolo(T,c, temp, max);
             }
     }
     return max;
}

//Altezza
template<class S>
int altezza(NalberoT<S> &T, NodoNalberoT<S>* u) {
	int max, temp;
    max = temp = 0;
    if (!T.NalberoVuoto())
    	max = calcolo(T,u, temp, max);
    return max;
}

//VISITE
template<class S>
void preVisita(NalberoT<S> &T, NodoNalberoT<S>* u){
	NodoNalberoT<S>* c;
	if(!T.NalberoVuoto()){
		esaminaNodo(u,T);
		if(!T.foglia(u)){
			c = T.primoFiglio(u);
			while(!T.ultimoFratello(c)){
				preVisita(T,c);
				c = T.succFratello(c);
			}
			preVisita(T,c);
		}
	}
	else
		cout<<"Albero vuoto"<<endl;
}

template<class S>
void postVisita(NalberoT<S> &T,NodoNalberoT<S>* u){
	NodoNalberoT<S>* c;
	if(!T.NalberoVuoto()){
		if(!T.foglia(u)){
			c = T.primoFiglio(u);
			while(!T.ultimoFratello(c)){
				postVisita(T,c);
				c = T.succFratello(c);
			}
			postVisita(T,c);
		}
		esaminaNodo(u,T);
	}
	else
		cout<<"Albero vuoto"<<endl;
}

template<class S>
void simmetrica(NalberoT<S> &T,NodoNalberoT<S>* u){
	NodoNalberoT<S>* c;
	if(!T.NalberoVuoto()){
		if(T.foglia(u))
			esaminaNodo(u,T);
		else{
			c = T.primoFiglio(u);
			simmetrica(T,c);
			esaminaNodo(u,T);
			while(!T.ultimoFratello(c)){
				c = T.succFratello(c);
				simmetrica(T,c);
			}
		}
	}
	else
		cout<<"Albero vuoto"<<endl;
}

template<class S>
void ampiezza(NalberoT<S> &T, NodoNalberoT<S>* u){
    NodoNalberoT<S>* temp;
    if(!T.NalberoVuoto()){
    	Queue<NodoNalberoT<S>*> coda;
    	coda.enqueue(u);
    	while (!coda.isEmpty()) {
    		temp = coda.first();
    		esaminaNodo(temp,T);
    		coda.dequeue();
    		if (!T.foglia(temp)) {
    			temp = T.primoFiglio(temp);
    			while (!T.ultimoFratello(temp)) {
    				coda.enqueue(temp);
    				temp = T.succFratello(temp);
    			}
    			coda.enqueue(temp);
    		}
    	}
    }
    else
    	cout<<"Albero vuoto"<<endl;
}
#endif /* SERVIZINALBEROT_H_ */
