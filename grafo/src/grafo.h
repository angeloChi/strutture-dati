/*
 * grafo.h
 *
 *  Created on: 17 feb 2017
 *      Author: angelo
 */

#ifndef GRAFO_H_
#define GRAFO_H_
#include"lista/listaTemplate.h"
#include"lista/serviziListaTemplate.h"
#include"arcoGrafo.h"

class Grafo{
public:
	typedef CellaGrafo nodoGrafo;
	typedef ArcoGrafo arcoGrafo;


	Lista<arcoGrafo*, Nodo<arcoGrafo*>*> listaArchi;
	Lista<nodoGrafo*, Nodo<nodoGrafo*>*> listaNodi;

	Grafo();
	~Grafo();
	void creaGrafo();
	boolean grafoVuoto();
	void insNodo(nodoGrafo*, tipoNodo);
	void insArco(nodoGrafo*, nodoGrafo*, arcoGrafo*, tipoArco);
	void cancNodo(nodoGrafo*);
	void cancArco(nodoGrafo*, nodoGrafo*);
	boolean esisteNodo(nodoGrafo*);
	boolean esisteArco(nodoGrafo*, nodoGrafo*);
	Lista<CellaGrafo*, Nodo<CellaGrafo*>*> adiacenti(nodoGrafo*);


	//SUPPORTO
	Nodo<ArcoGrafo*>* posizioneArco(nodoGrafo*, nodoGrafo*);
	Nodo<CellaGrafo*>* posizioneNodo(nodoGrafo*);


};

Grafo::Grafo(){
	creaGrafo();
}
Grafo::~Grafo(){}

void Grafo::creaGrafo(){
	listaArchi.creaLista();
	listaNodi.creaLista();
}

boolean Grafo::grafoVuoto(){
	boolean vuoto;
	if(listaNodi.listaVuota())
		vuoto = true;
	else
		vuoto = false;
	return vuoto;
}

void Grafo::insNodo(nodoGrafo* u, tipoNodo x){
	Nodo<nodoGrafo*>* pos = listaNodi.primoLista();
	u->setInfoNodo(x);
	listaNodi.insLista(u,pos);
}

void Grafo::insArco(nodoGrafo* u, nodoGrafo* v,arcoGrafo* arco, tipoArco valore){
	if(esisteNodo(u) && esisteNodo(v)){
		if(!esisteArco(u,v)){
			arco->setInfoArco(valore);
			arco->setNodoPartenza(u);
			arco->setNodoArrivo(v);
			Nodo<ArcoGrafo*>* pos = listaArchi.primoLista();
			listaArchi.insLista(arco,pos);
		}else{
			cout<<"Errore: Impossibile inserire l'arco, esiste già un arco"<<endl;
		}

	}else{
		cout<<"Errore: Impossibile inserire l'arco, nodi non esistenti"<<endl;
	}
}

void Grafo::cancNodo(nodoGrafo* u){
	if(!listaNodi.listaVuota()){
		if(esisteNodo(u)){
			Nodo<ArcoGrafo*>* pos = listaArchi.primoLista();
			CellaGrafo* partenza;
			CellaGrafo* arrivo;
			while(!listaArchi.fineLista(pos)){
				partenza = listaArchi.leggiLista(pos)->getNodoPartenza();
				arrivo = listaArchi.leggiLista(pos)->getNodoArrivo();
				if((u->getInfoNodo()== partenza->getInfoNodo()) || (u->getInfoNodo() == arrivo->getInfoNodo())){
					listaArchi.cancLista(pos);
					pos = listaArchi.primoLista();
				}
				pos = listaArchi.succLista(pos);
			}
			Nodo<nodoGrafo*>* pos_v = listaNodi.primoLista();
			CellaGrafo* x;
			while(!listaNodi.fineLista(pos_v) && esisteNodo(u)){
				x = listaNodi.leggiLista(pos_v);
				if(u->getInfoNodo() == x->getInfoNodo())
					listaNodi.cancLista(pos_v);
				pos_v = listaNodi.succLista(pos_v);
			}
		}else{
			cout<<"ERRORE: il nodo non esiste"<<endl;
		}

	}else{
		cout<<"ERRORE: ListaNodi vuota"<<endl;
	}

}

void Grafo::cancArco(nodoGrafo* u, nodoGrafo* v){
	if(!listaArchi.listaVuota()){
		if(esisteArco(u,v)){
			Nodo<arcoGrafo*>* pos = posizioneArco(u,v);
			listaArchi.cancLista(pos);
		}else{
			cout<<"ERRORE: non esiste l'arco"<<endl;
		}
	}else{
		cout<<"ERRORE: listaArchi vuota"<<endl;
	}

}
boolean Grafo::esisteNodo(nodoGrafo* u){
		boolean trovato = false;
		if (!listaNodi.listaVuota()) {
			Nodo<nodoGrafo*>* pos = listaNodi.primoLista();
			while (!listaNodi.fineLista(pos) && !trovato) {
				if (pos->getElemento() == u)
					trovato = true;
				else
					pos = listaNodi.succLista(pos);
			}
		}
		return trovato;
}

boolean Grafo::esisteArco(nodoGrafo* u, nodoGrafo* v){
	boolean trovato = false;
	arcoGrafo* arco;
	if(!listaArchi.listaVuota()){
		if(esisteNodo(u) && esisteNodo(v)){
			Nodo<arcoGrafo*>* pos = listaArchi.primoLista();
			while(!listaArchi.fineLista(pos) && !trovato){
				arco = pos->getElemento();

				if(arco->getNodoPartenza() == u && arco->getNodoArrivo() == v)
					trovato = true;
				else{
					trovato = false;
					pos = listaArchi.succLista(pos);
				}
			}
		}else{
			cout<<"ERRORE: non esistono i nodi"<<endl;
		}
	}

	return trovato;
}

Nodo<ArcoGrafo*>* Grafo::posizioneArco(nodoGrafo* u, nodoGrafo* v){
	boolean trovato = false;
	Nodo<arcoGrafo*>* pos = NULL;
		arcoGrafo* arco;
		if(!listaArchi.listaVuota()){
			if(esisteNodo(u) && esisteNodo(v)){
				pos = listaArchi.primoLista();
				while(!listaArchi.fineLista(pos) && !trovato){
					arco = pos->getElemento();

					if(arco->getNodoPartenza() == u && arco->getNodoArrivo() == v){

						return pos;
						trovato = true;
					}
					else{
						trovato = false;
						pos = listaArchi.succLista(pos);
					}
				}
			}else{
				cout<<"ERRORE: non esistono i nodi"<<endl;
			}
		}

		return pos;

}


Nodo<CellaGrafo*>* Grafo::posizioneNodo(nodoGrafo* u){
	Nodo<nodoGrafo*>* pos = NULL;
	boolean trovato = false;
			if (!listaNodi.listaVuota()) {
				pos = listaNodi.primoLista();
				while (!listaNodi.fineLista(pos) && !trovato) {
					if (pos->getElemento() == u)
						trovato = true;
					else
						pos = listaNodi.succLista(pos);
				}
			}
			return pos;


}


Lista<CellaGrafo*, Nodo<CellaGrafo*>*> Grafo::adiacenti(nodoGrafo* u){
	Lista<CellaGrafo*, Nodo<CellaGrafo*>*> listaTemp;
	listaTemp.creaLista();
	if(!listaNodi.listaVuota()){
		if(esisteNodo(u)){
			Nodo<ArcoGrafo*>* pos = listaArchi.primoLista();
			CellaGrafo* partenza;
			CellaGrafo* arrivo;
			while(!listaArchi.fineLista(pos)){
				partenza = listaArchi.leggiLista(pos)->getNodoPartenza();
				arrivo = listaArchi.leggiLista(pos)->getNodoArrivo();
				if(u->getInfoNodo() == partenza->getInfoNodo()){
					listaTemp.insLista(arrivo,listaTemp.primoLista());
				}
				pos = listaArchi.succLista(pos);
			}
		}else{
			cout<<"ERRORE: il nodo non esiste"<<endl;
		}

	}else{
		cout<<"ERRORE: ListaNodi vuota"<<endl;
	}
	return listaTemp;
}




#endif /* GRAFO_H_ */
