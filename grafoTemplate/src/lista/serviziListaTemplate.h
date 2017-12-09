/*
 * serviziListaTemplate.h
 *
 *  Created on: 30 dic 2016
 *      Author: angelo
 */

#ifndef SERVIZILISTATEMPLATE_H_
#define SERVIZILISTATEMPLATE_H_
#include<cstring>
#include<stdlib.h>
#include"listaTemplate.h"

using namespace std;

template<class tipoElem, class posizione>
void acquisisciLista(Lista<tipoElem,posizione> &lista){
	lista.creaLista();
	posizione pos = lista.primoLista();
	tipoElem dato;

	dato = 'e';
	lista.insLista(dato,pos);

	dato = 'f';
	lista.insLista(dato,pos);

	dato = 'x';
	lista.insLista(dato,pos);

	dato = 'k';
	lista.insLista(dato,pos);

	dato = 'c';
	lista.insLista(dato,pos);

	dato = 'd';
	lista.insLista(dato,pos);

	dato = 'b';
	lista.insLista(dato,pos);
}

template<class tipoElem, class posizione>
void stampaLista(Lista<tipoElem,posizione> &lista){
	posizione pos = lista.primoLista();
		if(!lista.listaVuota()){
			cout<<"List: ";
			while(!lista.fineLista(pos)){
				cout<<lista.leggiLista(pos)<<" ";
				pos = lista.succLista(pos);
			}
			cout<<endl;
		}else{
			cout<<"La lista e' vuota"<<endl;
		}
}

template<class tipoElem, class posizione>
int numeroElem(Lista<tipoElem,posizione> &lista){
	if(!lista.listaVuota()){
	int i = 1;
		posizione pos = lista.primoLista();
		while(pos!=lista.ultimoLista() && !lista.fineLista(pos)){ //i viene incrementato fin quando non si arriva
			pos=lista.succLista(pos);					//alla fine della lista e si è raggiunto l'ultimo elemento
			i++;
		}
		return i;
	}else{
		return 0;
	}
}

template<class tipoElem, class posizione>
void insListap(Lista<tipoElem,posizione> &lista, int i, tipoElem dato){	//metodo che permette di inserire tramite
	posizione p = lista.primoLista();									//un intero, si parte da 0
		int j =0;
		int lunghezza = numeroElem(lista);
	if(!lista.listaVuota()){
		if(i==lunghezza){				//inserire al posto dell'ultimo elemento che si trova
			p = lista.ultimoLista();
			lista.insLista(dato,p);
		}else if(i==lunghezza+1){		//inserimento dopo l'ultimo elemento
			p = lista.succLista(lista.ultimoLista());
			lista.insLista(dato,p);
		}else if(i==0){					//inserire come primo elemento
			lista.insLista(dato,lista.primoLista());
		}else{
			while(j!=i){
				p = lista.succLista(p);
				j++;
			}
			lista.insLista(dato,p);
		}
	}else{
		if(i!=0)
			cout<<"posizione non valida"<<endl;
		else
			lista.insLista(dato,lista.primoLista());
	}
}

template<class tipoElem, class posizione>
void canc(Lista<tipoElem,posizione> &lista,int i){ //metodo che permette di cancellare un elemento mediante un intero
	int j = 0;										//si parte da 0
	int lunghezza = numeroElem(lista);

	if(i==lunghezza){							//cancella ultimo elemento
		lista.cancLista(lista.ultimoLista());

	}else if(i==0){								//cancella primo elemento
		lista.cancLista(lista.primoLista());
	}else{										//cancella elemento in posizione qualsiasi
		posizione pos = lista.primoLista();
		while(j!=i){
			pos = lista.succLista(pos);
			j++;
		}
		lista.cancLista(pos);
	}
}

template<class tipoElem, class posizione>
posizione cerca(Lista<tipoElem,posizione> &lista,tipoElem elem){  //cerca un elemento restituendo la posizione
	posizione pos = new Nodo<tipoElem>();
	pos = NULL;
	boolean trovato = false;
	int i = 0;
	pos = lista.primoLista();
	if (!lista.listaVuota()) {
		while (!lista.fineLista(pos) && !trovato) {
			i++;
			if (lista.leggiLista(pos) == elem)
				trovato = true;
			else
				pos = lista.succLista(pos);
		}
	}
	cout << "L'elemento "<<elem;
	if (trovato)
		cout << " e' ";
	else
		cout << " non e' ";
	cout << " presente nella lista" << endl;
	return pos;
}

template<class tipoElem, class posizione>
void svuotaLista(Lista<tipoElem,posizione> &lista){		//svuota una lista
	if(lista.listaVuota()){
		cout<<"Impossibile svuotare lista vuota"<<endl;
	}else{
		posizione pos = lista.primoLista();
		while(!lista.listaVuota() && !lista.fineLista(pos)){
			posizione pos = lista.primoLista();
			lista.cancLista(pos);
		}
	}
}

template<class tipoElem, class posizione>
Lista<tipoElem,posizione> copia(Lista<tipoElem,posizione> &lista){		//copia una lista
	Lista<tipoElem,posizione> listaTemp;
	posizione pos1,pos2;
	tipoElem elem;
	pos2 = listaTemp.primoLista();
	pos1 = lista.primoLista();
	while(!lista.fineLista(pos1)){
		elem = lista.leggiLista(pos1);
		pos1 = lista.succLista(pos1);
		listaTemp.insLista(elem,pos2);
	}
	return listaTemp;
}

template<class tipoElem, class posizione>
Lista<tipoElem,posizione> dividiLista(Lista<tipoElem,posizione> &lista){		//divide una lista in due parti
	Lista<tipoElem,posizione> listTemp;
	listTemp.creaLista();
	int i = numeroElem(lista);
	posizione pos1 = lista.ultimoLista();
	if(!lista.listaVuota()){
		if(numeroElem(lista)>=2){
			int center = numeroElem(lista)/2;
			while(center<i){
				listTemp.insLista(lista.leggiLista(pos1),listTemp.primoLista());
				lista.cancLista(pos1);
				pos1 = lista.precLista(pos1);
				i--;
			}
		}
	}
	return listTemp;
}

template<class tipoElem,class posizione>
void epurazione(Lista<tipoElem,posizione> &lista){   //cancella i doppioni
	posizione p,q;
	tipoElem a,b;
	p = lista.primoLista();
	while(!lista.fineLista(p)){
		a = lista.leggiLista(p);
		q = lista.succLista(p);
		while(!lista.fineLista(q)){
			b = lista.leggiLista(q);
			if(a==b)
				lista.cancLista(q);
			else
				q = lista.succLista(q);
		}
		p = lista.succLista(p);
	}
}

template<class tipoElem,class posizione>
Lista<tipoElem,posizione> merge(Lista<tipoElem,posizione> &left, Lista<tipoElem,posizione> &right){
	Lista<tipoElem,posizione> result;
	while((int)numeroElem(left)>0 || (int)numeroElem(right)>0){
		if((int)numeroElem(left)>0 && (int)numeroElem(right)>0){
			if((int)left.leggiLista(left.primoLista()) <= (int)right.leggiLista(right.primoLista())){
				insUltimo(result,left.leggiLista(left.primoLista()));
				left.cancLista(left.primoLista());
			}
			else{
				insUltimo(result,right.leggiLista(right.primoLista()));
				right.cancLista(right.primoLista());
			}
		}
		else if((int)numeroElem(left)>0){
				for(int i = 0; i<(int)numeroElem(left);i++)
					insUltimo(result,letturaNodo(left,i));
				break;
			}else if((int)numeroElem(right)>0){
				for(int i = 0; i<(int)numeroElem(right);i++)
					insUltimo(result,letturaNodo(right,i));
				break;
			}
		}
	return result;
}

template<class tipoElem,class posizione>
Lista<tipoElem,posizione> mergeSort(Lista<tipoElem,posizione> &lista){
	if(numeroElem(lista)<=1)
		return lista;
	Lista<tipoElem,posizione> left,right,result;
	int middle = ((int) numeroElem(lista)+1)/2;
	for (int i = 0; i <middle; i++) {
		insUltimo(left,letturaNodo(lista,i));
	  	 }
	for(int i = middle; i<numeroElem(lista); i++){
		insUltimo(right,letturaNodo(lista,i));
	}
	left = mergeSort(left);
	right = mergeSort(right);
	result = merge(left,right);
	return result;
}

template<class tipoElem,class posizione>
tipoElem letturaNodo(Lista<tipoElem,posizione> &list, int i){ //legge un nodo mediante un intero passato
	tipoElem dato = 0;										 //come posizione
	int j = 0;
		int lunghezza = numeroElem(list);

		if(i==lunghezza){
			dato = list.leggiLista(list.ultimoLista());

		}else if(i==0){
			dato =  list.leggiLista(list.primoLista());
		}
		else if(i>numeroElem(list)){
			dato = 0;
		}else{
			posizione pos = list.primoLista();
			while(j!=i){
				pos = list.succLista(pos);
				j++;
			}
			dato =  list.leggiLista(pos);
		}
		return dato;
}

template<class tipoElem,class posizione>
void insUltimo(Lista<tipoElem,posizione> &lista,tipoElem value){	//inserimento in ultima posizione
	if(lista.listaVuota())
		lista.insLista(value,lista.primoLista());
	else{
		int x = numeroElem(lista);
		insListap(lista,x+1,value);
	}
}

#endif /* SERVIZILISTATEMPLATE_H_ */
