
/*
 * serviziAlberoBin.cpp
 *
 *  Created on: 02 feb 2017
 *      Author: angelo
 */
#include<iomanip>
#include<stdio.h>
#include<iostream>
#include"serviziAlberoBin.h"
//#include<conio.h>
//#include<windows.h> //per usare il tasto esc per uscire sostiuire l'identificatore boolean con booleano,
					//altrienti va in errore con la libreria windows

using namespace std;

void autoAcquisizione(BinAlbero &T) {
	T.creaBinAlbero();

	/*T.insRadice();
	NodoBinAlbero* radix = T.binRadice();
	T.scriviNodo(radix,'h');

	T.insFiglioSx(radix);
	NodoBinAlbero* left = T.figlioSinistro(radix);
	T.scriviNodo(left,'a');

	T.insFiglioDx(radix);
	NodoBinAlbero* right = T.figlioDestro(radix);
	T.scriviNodo(right,'c');

	T.insFiglioSx(left);
	NodoBinAlbero* leftA = T.figlioSinistro(left);
	T.scriviNodo(leftA,'d');

	T.insFiglioDx(left);
	NodoBinAlbero* rightA = T.figlioDestro(left);
	T.scriviNodo(rightA,'l');

	T.insFiglioSx(right);
	NodoBinAlbero* leftC = T.figlioSinistro(right);
	T.scriviNodo(leftC,'p');

	T.insFiglioDx(right);
	NodoBinAlbero* rightC = T.figlioDestro(right);
	T.scriviNodo(rightC,'s');

	T.insFiglioSx(rightA);
	NodoBinAlbero* leftL = T.figlioSinistro(rightA);
	T.scriviNodo(leftL,'o');

	T.insFiglioDx(rightA);
	NodoBinAlbero* rightL = T.figlioDestro(rightA);
	T.scriviNodo(rightL,'q');*/

	T.insRadice();
	NodoBinAlbero* radix = T.binRadice();
	T.scriviNodo(radix,49);

	T.insFiglioSx(radix);
	NodoBinAlbero* left = T.figlioSinistro(radix);
	T.scriviNodo(left,22);

	T.insFiglioDx(radix);
	NodoBinAlbero* right = T.figlioDestro(radix);
	T.scriviNodo(right,82);

	T.insFiglioSx(left);
	NodoBinAlbero* leftA = T.figlioSinistro(left);
	T.scriviNodo(leftA,17);

	T.insFiglioSx(right);
	NodoBinAlbero* leftB = T.figlioSinistro(right);
	T.scriviNodo(leftB,57);

	T.insFiglioDx(right);
	NodoBinAlbero* rightA = T.figlioDestro(right);
	T.scriviNodo(rightA,88);


}

void acquisizione(BinAlbero &T){
	typeElem x;
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
void acquisizione(BinAlbero &T){
  typeElem x;
  char c;
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


}
 */


//INSERIMENTO

void inserimentOrdinato(BinAlbero &T, typeElem x, NodoBinAlbero* u){
	if (T.binAlberoVuoto()) {
		T.insRadice();
		T.scriviNodo(T.binRadice(),x);
	} else {
		if (confrontaTipi(x,T.leggiNodo(u)) == -1) {
			if (T.sinistroVuoto(u)) {
				T.insFiglioSx(u);
				T.scriviNodo(T.figlioSinistro(u),x);
			} else
				inserimentOrdinato(T,x,T.figlioSinistro(u));
		}
		if (confrontaTipi(x,T.leggiNodo(u)) == 1) {
			if (T.destroVuoto(u)) {
				T.insFiglioDx(u);
				T.scriviNodo(T.figlioDestro(u),x);
			} else
				inserimentOrdinato(T,x,T.figlioDestro(u));   // chiamata ricorsiva
		}
		if (confrontaTipi(x,T.leggiNodo(u)) == 0)
			cout<<"Elemento gia' presente!!!"<<endl;
	}
}

int confrontaTipi(typeElem a,typeElem b){
	int conf;
	if(a<b)
		conf = -1;
	if(a==b)
		conf = 0;
	if(a>b)
		conf = 1;
	return conf;
}

//PROFONDITA
int maxProfondita(NodoBinAlbero* u,BinAlbero &T) {
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

int getLevelUtil(BinAlbero &T,NodoBinAlbero* u, typeElem x, int level){
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


int getLevel(BinAlbero &T,NodoBinAlbero* u, typeElem x){
	return getLevelUtil(T,u,x,0);
}





//ESAMINANODO
void esaminaNodo(NodoBinAlbero* u, BinAlbero &T){
	cout<<T.leggiNodo(u)<<" ";
}

//CONTAnODI
int contaNodi(BinAlbero &T, NodoBinAlbero* u){
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

//RICERCA
NodoBinAlbero* searchBinaria(BinAlbero &T, typeElem x, NodoBinAlbero* u){
	if(!T.binAlberoVuoto()){
		if( x == T.leggiNodo(u)){
			//esaminaNodo(u,T);
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

boolean searchBinariaBool(BinAlbero &T, typeElem x, NodoBinAlbero* u){
	boolean trovato = false;
	if(!T.binAlberoVuoto()){
		if( x == T.leggiNodo(u)){
			//esaminaNodo(u,T);
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


boolean searchBool(BinAlbero &T, typeElem x, NodoBinAlbero* u, boolean found){

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

boolean searchBoolean(BinAlbero &T, typeElem x, NodoBinAlbero* u){
	return searchBool(T,x,u,false);
}
NodoBinAlbero* search(BinAlbero& T, typeElem x, NodoBinAlbero* u) {
	NodoBinAlbero* nodo = NULL;
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
void preVisita(NodoBinAlbero* u,BinAlbero &T){
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

void postVisita(NodoBinAlbero* u,BinAlbero &T){
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

void simmetrica(NodoBinAlbero* u,BinAlbero &T){
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

void ampiezza(BinAlbero &T){
	Queue<NodoBinAlbero*> queue;
	NodoBinAlbero* x;
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
