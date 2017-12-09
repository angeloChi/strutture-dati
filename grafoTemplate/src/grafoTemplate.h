/*
 * grafoTemplate.h
 *
 *  Created on: 18 feb 2017
 *      Author: angelo
 */

#ifndef GRAFOTEMPLATE_H_
#define GRAFOTEMPLATE_H_

#include"lista/listaTemplate.h"
#include"lista/serviziListaTemplate.h"
#include"arcoGrafoTemplate.h"

template<class tipoArco,class tipoNodo>
class Grafo{
public:
	typedef CellaGrafo<tipoNodo> nodoGrafo;
	typedef ArcoGrafo<tipoArco,tipoNodo> arcoGrafo;

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
	Lista<CellaGrafo<tipoNodo>*, Nodo<CellaGrafo<tipoNodo>*>*> adiacenti(nodoGrafo*); //restituisce una lista dei nodi
																						//adiacenti
	//SUPPORTO
	Nodo<ArcoGrafo<tipoArco,tipoNodo>*>* posizioneArco(nodoGrafo*, nodoGrafo*);
	Nodo<CellaGrafo<tipoNodo>*>* posizioneNodo(nodoGrafo*);
};

template<class tipoArco,class tipoNodo>
Grafo<tipoArco,tipoNodo>::Grafo(){
	creaGrafo();
}

template<class tipoArco,class tipoNodo>
Grafo<tipoArco,tipoNodo>::~Grafo(){}

template<class tipoArco,class tipoNodo>
void Grafo<tipoArco,tipoNodo>::creaGrafo(){
	listaArchi.creaLista();
	listaNodi.creaLista();
}

template<class tipoArco,class tipoNodo>
boolean Grafo<tipoArco,tipoNodo>::grafoVuoto(){
	boolean vuoto;
	if(listaNodi.listaVuota())
		vuoto = true;
	else
		vuoto = false;
	return vuoto;
}

template<class tipoArco,class tipoNodo>
void Grafo<tipoArco,tipoNodo>::insNodo(nodoGrafo* u, tipoNodo x){
	Nodo<nodoGrafo*>* pos = listaNodi.primoLista();
	u->setInfoNodo(x);
	listaNodi.insLista(u,pos);
}

template<class tipoArco,class tipoNodo>
void Grafo<tipoArco,tipoNodo>::insArco(nodoGrafo* u, nodoGrafo* v,arcoGrafo* arco, tipoArco valore){
	if(esisteNodo(u) && esisteNodo(v)){
		if(!esisteArco(u,v)){
			arco->setInfoArco(valore);
			arco->setNodoPartenza(u);
			arco->setNodoArrivo(v);
			Nodo<ArcoGrafo<tipoArco,tipoNodo>*>* pos = listaArchi.primoLista();
			listaArchi.insLista(arco,pos);
		}else{
			cout<<"Errore: Impossibile inserire l'arco, esiste già un arco"<<endl;
		}
	}else{
		cout<<"Errore: Impossibile inserire l'arco, nodi non esistenti"<<endl;
	}
}

template<class tipoArco,class tipoNodo>
void Grafo<tipoArco,tipoNodo>::cancNodo(nodoGrafo* u){
	if(!listaNodi.listaVuota()){
		if(esisteNodo(u)){
			Nodo<ArcoGrafo<tipoArco,tipoNodo>*>* pos = listaArchi.primoLista();
			CellaGrafo<tipoNodo>* partenza;
			CellaGrafo<tipoNodo>* arrivo;
			while(!listaArchi.fineLista(pos)){									//Cancellazione dell'arco
				partenza = listaArchi.leggiLista(pos)->getNodoPartenza();		//Nodo di partenza
				arrivo = listaArchi.leggiLista(pos)->getNodoArrivo();			//Nodo di arrivo
				if((u->getInfoNodo() == partenza->getInfoNodo()) || (u->getInfoNodo() == arrivo->getInfoNodo())){
					listaArchi.cancLista(pos);
					pos = listaArchi.primoLista();
				}
				pos = listaArchi.succLista(pos);
			}
			Nodo<nodoGrafo*>* pos_v = listaNodi.primoLista();
			CellaGrafo<tipoNodo>* x;
			while(!listaNodi.fineLista(pos_v) && esisteNodo(u)){	//Cancellazione del nodo
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

template<class tipoArco,class tipoNodo>
void Grafo<tipoArco,tipoNodo>::cancArco(nodoGrafo* u, nodoGrafo* v){
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

template<class tipoArco,class tipoNodo>
boolean Grafo<tipoArco,tipoNodo>::esisteNodo(nodoGrafo* u){
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

template<class tipoArco,class tipoNodo>
boolean Grafo<tipoArco,tipoNodo>::esisteArco(nodoGrafo* u, nodoGrafo* v){
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

template<class tipoArco,class tipoNodo>
Nodo<ArcoGrafo<tipoArco,tipoNodo>*>* Grafo<tipoArco,tipoNodo>::posizioneArco(nodoGrafo* u, nodoGrafo* v){
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

template<class tipoArco,class tipoNodo>
Nodo<CellaGrafo<tipoNodo>*>* Grafo<tipoArco,tipoNodo>::posizioneNodo(nodoGrafo* u){
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

template<class tipoArco,class tipoNodo>
Lista<CellaGrafo<tipoNodo>*, Nodo<CellaGrafo<tipoNodo>*>*> Grafo<tipoArco,tipoNodo>::adiacenti(nodoGrafo* u){
	Lista<CellaGrafo<tipoNodo>*, Nodo<CellaGrafo<tipoNodo>*>*> listaTemp;
	listaTemp.creaLista();
	if(!listaNodi.listaVuota()){
		if(esisteNodo(u)){
			Nodo<ArcoGrafo<tipoArco,tipoNodo>*>* pos = listaArchi.primoLista();
			CellaGrafo<tipoNodo>* partenza;
			CellaGrafo<tipoNodo>* arrivo;
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
#endif /* GRAFOTEMPLATE_H_ */
