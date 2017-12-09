/*
 * serviziBinAlberoTemplate.h
 *
 *  Created on: 08 feb 2017
 *      Author: angelo
 */

#ifndef SERVIZIBINALBEROTEMPLATE_H_
#define SERVIZIBINALBEROTEMPLATE_H_
#include"queueTemplate.h"
#include"binAlberoTemplate.h"
//#include<conio.h>
//#include<windows.h> //per usare il tasto esc per uscire sostiuire l'identificatore boolean con booleano,
					//altrienti va in errore con la libreria windows
using namespace std;

//non uso template <class typeElem> perchè con typeElem chiamo l'albero per convenzione

//ACQUISIZIONE
template<class S>
void autoAcquisizione(BinAlberoT<S> &T) {
	T.creaBinAlbero();

	T.insRadice();
	NodoBinAlberoT<S>* radix = T.binRadice();
	T.scriviNodo(radix,49);

	T.insFiglioSx(radix);
	NodoBinAlberoT<S>* left = T.figlioSinistro(radix);
	T.scriviNodo(left,22);

	T.insFiglioDx(radix);
	NodoBinAlberoT<S>* right = T.figlioDestro(radix);
	T.scriviNodo(right,82);

	T.insFiglioSx(left);
	NodoBinAlberoT<S>* leftA = T.figlioSinistro(left);
	T.scriviNodo(leftA,17);

	T.insFiglioSx(right);
	NodoBinAlberoT<S>* leftB = T.figlioSinistro(right);
	T.scriviNodo(leftB,57);

	T.insFiglioDx(right);
	NodoBinAlberoT<S>* rightA = T.figlioDestro(right);
	T.scriviNodo(rightA,88);

}
template<class S>
void acquisizione(BinAlberoT<S> &T){
	S x;
		cout<<"inserisci elemento (-1 per terminare): ";
		cin>>x;
		while (x!=-1) {
			if (!T.binAlberoVuoto()) {
				inserimentOrdinato(T,x,T.binRadice());
			} else {
				T.creaBinAlbero();
				T.insRadice();
				T.scriviNodo(T.binRadice(),x);
			}
			cout<<"inserisci elemento (-1 per terminare): ";
			cin>>x;
		}
}

/*
//Usata per uscire premendo il tasto ESC
template<class S>
void acquisizione(BinAlberoT<S> &T){
  S x;
  do {
    cout<<"inserisci elemento : ";
    cin>>x;
    cout<<"premi un tasto per continuare, premi ESC per terminare"<<endl;

      if (!T.binAlberoVuoto()) {
        inserimentOrdinato(T,x,T.binRadice());
      } else {
        T.creaBinAlbero();
        T.insRadice();
        T.scriviNodo(T.binRadice(),x);
      }

  }while (getch()!=27);


}*/

template <class S>
int confrontaTipi(S a,S b){
	int conf;
	if(a<b)
		conf = -1;
	if(a==b)
		conf = 0;
	if(a>b)
		conf = 1;
	return conf;
}

//INSERIMENTO
template<class S>
void inserimentOrdinato(BinAlberoT<S> &T, S x, NodoBinAlberoT<S>* u){

	if (T.binAlberoVuoto()) {			//Albero vuoto
		T.insRadice();
		T.scriviNodo(T.binRadice(),x);
	} else {							//Albero non vuoto
		if (confrontaTipi(x,T.leggiNodo(u)) == -1) {	//se x è minore del valore del nodo u
			if (T.sinistroVuoto(u)) {					//caso in cui il figlio sx di u è vuoto
				T.insFiglioSx(u);
				T.scriviNodo(T.figlioSinistro(u),x);
			} else
				inserimentOrdinato(T,x,T.figlioSinistro(u)); //caso in cui il figlio sx di u non è vuoto
		}
		if (confrontaTipi(x,T.leggiNodo(u)) == 1) {			//se x è maggiore del valore del nodo u
			if (T.destroVuoto(u)) {							// caso in cui il figlio dx di u è vuoto
				T.insFiglioDx(u);
				T.scriviNodo(T.figlioDestro(u),x);
			} else											//caso in cui il figlio dx non è vuoto
				inserimentOrdinato(T,x,T.figlioDestro(u));   // chiamata ricorsiva
		}
		if (confrontaTipi(x,T.leggiNodo(u)) == 0)
			cout<<"Elemento gia' presente!!!"<<endl;
	}
}

//PROFONDITA
template<class S>
int maxProfondita(NodoBinAlberoT<S>* u,BinAlberoT<S> &T) {
	int max,corr;
	if (T.sinistroVuoto(u) && T.destroVuoto(u))
		return 0;
	else {
		max = 0;
		if (!T.sinistroVuoto(u)) {
			corr = maxProfondita(T.figlioSinistro(u),T);
			if (max <= corr)
				max = corr;
		}
		if (!T.destroVuoto(u)) {
			corr = maxProfondita(T.figlioDestro(u),T);
			if (max <= corr)
				max = corr;
		}
		return (max+1);
	}
}

//Funzione di appoggio per la funzione getLevel
template<class S>
int getLevelUtil(BinAlberoT<S> &T,NodoBinAlberoT<S>* u, S x, int level){
	if(u==NULL)
		return 0;
	if (confrontaTipi(x,T.leggiNodo(u)) == 0)
		return level;
	int downlevel = getLevelUtil(T,T.figlioSinistro(u),x,level+1);
	if(downlevel!=0)
		return downlevel;

	downlevel = getLevelUtil(T,T.figlioDestro(u),x,level+1);
	return downlevel;
}

//Livello di un nodo
template<class S>
int getLevel(BinAlberoT<S> &T,NodoBinAlberoT<S>* u, S x){
	return getLevelUtil(T,u,x,0);
}

//esamina nodo
template<class S>
void esaminaNodo(NodoBinAlberoT<S>* u, BinAlberoT<S> &T){
	cout<<T.leggiNodo(u)<<" ";
}

//Conta nodi
template<class S>
int contaNodi(BinAlberoT<S> &T, NodoBinAlberoT<S>* u){
	int i = 0;
	if(!T.binAlberoVuoto()){
		if(!T.sinistroVuoto(u))
			i = i + contaNodi(T,T.figlioSinistro(u));
		if(!T.destroVuoto(u))
			i = i + contaNodi(T,T.figlioDestro(u));
		i++;
	}
	return i;
}


//Ricerca binaria restituisce il nodo
template<class S>
NodoBinAlberoT<S>* searchBinaria(BinAlberoT<S> &T, S x, NodoBinAlberoT<S>* u){
	if(!T.binAlberoVuoto()){
		if( x == T.leggiNodo(u)){
			esaminaNodo(u,T);
			return u;
		}else if(x<T.leggiNodo(u) && !T.sinistroVuoto(u)){
			 return searchBinaria(T,x,T.figlioSinistro(u));
		}else if(x>T.leggiNodo(u) && !T.destroVuoto(u)){
			 return searchBinaria(T,x,T.figlioDestro(u));
		}

	}else{
		cout<<"Albero vuoto"<<endl;
	}
	//cout<<"Elemento non presente"<<endl;
	return u;				//restituisce l'ultimo nodo foglia della scansione
}

//Ricerca binaria booleana
template<class S>
boolean searchBinariaBool(BinAlberoT<S> &T, S x, NodoBinAlberoT<S>* u){
	boolean trovato = false;
	if(!T.binAlberoVuoto()){
		if( x == T.leggiNodo(u)){
			esaminaNodo(u,T);
			return trovato = true;
		}else if(x<T.leggiNodo(u) && !T.sinistroVuoto(u)){
			 return searchBinariaBool(T,x,T.figlioSinistro(u));
		}else if(x>T.leggiNodo(u) && !T.destroVuoto(u)){
			 return searchBinariaBool(T,x,T.figlioDestro(u));
		}

	}else{
		cout<<"Albero vuoto"<<endl;
	}

	return trovato;
}

//funzione di appoggio per seachBool
template<class S>
boolean searchBool(BinAlberoT<S> &T, S x, NodoBinAlberoT<S>* u,boolean found){
	if(!T.binAlberoVuoto()){
		if(T.leggiNodo(u)==x){
			found = true;
		}
		if(!T.sinistroVuoto(u))
			found = searchBool(T,x,T.figlioSinistro(u),found);
		if(!T.destroVuoto(u))
			found = searchBool(T,x,T.figlioDestro(u),found);
	}
	return found;
}

//ricerca booleana su un albero binario non ordinato
template<class S>
boolean searchBoolean(BinAlberoT<S> &T, S x, NodoBinAlberoT<S>* u){
	return searchBool(T,x,u,false);
}

//ricerca su un albero binario non ordinato, restituisce il nodo
template<class S>
NodoBinAlberoT<S>* search(BinAlberoT<S> &T, S x, NodoBinAlberoT<S>* u) {
	NodoBinAlberoT<S>* nodo = NULL;
	if (!T.binAlberoVuoto()) {
		if (confrontaTipi(x,T.leggiNodo(u)) == 0)
			nodo = u;
		else {
			if (T.sinistroVuoto(u) && T.destroVuoto(u))
				nodo = NULL;
			else {
				if (!T.sinistroVuoto(u))
					nodo = search(T,x,T.figlioSinistro(u));
				if (nodo == NULL && !T.destroVuoto(u))
					nodo = search(T,x,T.figlioDestro(u));
			}
		}
	}
	return nodo;
}

//VISITE
template<class S>
void preVisita(NodoBinAlberoT<S>* u,BinAlberoT<S> &T){
	if(!T.binAlberoVuoto()){
		esaminaNodo(u,T);
		if(!T.sinistroVuoto(u))
			preVisita(T.figlioSinistro(u),T);
		if(!T.destroVuoto(u))
			preVisita(T.figlioDestro(u),T);
	}else{
		cout<<"Albero vuoto"<<endl;
	}
}

template<class S>
void postVisita(NodoBinAlberoT<S>* u,BinAlberoT<S> &T){
	if(!T.binAlberoVuoto()){
		if(!T.sinistroVuoto(u))
			postVisita(T.figlioSinistro(u),T);
		if(!T.destroVuoto(u))
			postVisita(T.figlioDestro(u),T);
		esaminaNodo(u,T);
	}else{
		cout<<"Albero vuoto"<<endl;
	}
}

template<class S>
void simmetrica(NodoBinAlberoT<S>* u,BinAlberoT<S> &T){
	if(!T.binAlberoVuoto()){
		if(!T.sinistroVuoto(u))
			simmetrica(T.figlioSinistro(u),T);
		esaminaNodo(u,T);
		if(!T.destroVuoto(u))
			simmetrica(T.figlioDestro(u),T);
	}else{
		cout<<"Albero vuoto"<<endl;
	}
}

template<class S>
void ampiezza(BinAlberoT<S> &T){
	Queue<NodoBinAlberoT<S>*> queue;
	NodoBinAlberoT<S>* x;
	if(!T.binAlberoVuoto()){
		esaminaNodo(T.binRadice(),T);
		queue.enqueue(T.binRadice());
		while(!queue.isEmpty()){
			x = queue.first();
			queue.dequeue();
			if(!T.sinistroVuoto(x)){
				esaminaNodo(T.figlioSinistro(x),T);
				queue.enqueue(T.figlioSinistro(x));
			}
			if(!T.destroVuoto(x)){
				esaminaNodo(T.figlioDestro(x),T);
				queue.enqueue(T.figlioDestro(x));
			}
		}
	}else{
		cout<<"Albero vuoto"<<endl;
	}
}

#endif /* SERVIZIBINALBEROTEMPLATE_H_ */
