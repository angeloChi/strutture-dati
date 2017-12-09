/*
 * serviziGrafoTemplate.h
 *
 *  Created on: 18 feb 2017
 *      Author: angelo
 */

#ifndef SERVIZIGRAFOTEMPLATE_H_
#define SERVIZIGRAFOTEMPLATE_H_
#include"grafoTemplate.h"
#include"coda/queueTemplate.h"

template<class tipoArco,class tipoNodo>
void acquisisciGrafo(Grafo<tipoArco,tipoNodo> &grafo){
	grafo.creaGrafo();
	CellaGrafo<tipoNodo>* a = new CellaGrafo<tipoNodo>();
	CellaGrafo<tipoNodo>* b = new CellaGrafo<tipoNodo>();
	CellaGrafo<tipoNodo>* c = new CellaGrafo<tipoNodo>();
	CellaGrafo<tipoNodo>* d = new CellaGrafo<tipoNodo>();
	CellaGrafo<tipoNodo>* f = new CellaGrafo<tipoNodo>();
	CellaGrafo<tipoNodo>* g = new CellaGrafo<tipoNodo>();

	ArcoGrafo<tipoArco,tipoNodo>* arco1 = new ArcoGrafo<tipoArco,tipoNodo>();
	ArcoGrafo<tipoArco,tipoNodo>* arco2 = new ArcoGrafo<tipoArco,tipoNodo>();
	ArcoGrafo<tipoArco,tipoNodo>* arco3 = new ArcoGrafo<tipoArco,tipoNodo>();
	ArcoGrafo<tipoArco,tipoNodo>* arco4 = new ArcoGrafo<tipoArco,tipoNodo>();
	ArcoGrafo<tipoArco,tipoNodo>* arco5 = new ArcoGrafo<tipoArco,tipoNodo>();
	ArcoGrafo<tipoArco,tipoNodo>* arco6 = new ArcoGrafo<tipoArco,tipoNodo>();
	ArcoGrafo<tipoArco,tipoNodo>* arco7 = new ArcoGrafo<tipoArco,tipoNodo>();
	ArcoGrafo<tipoArco,tipoNodo>* arco8 = new ArcoGrafo<tipoArco,tipoNodo>();
	ArcoGrafo<tipoArco,tipoNodo>* arco9 = new ArcoGrafo<tipoArco,tipoNodo>();


	grafo.insNodo(a,"A");
	grafo.insNodo(b,"B");
	grafo.insNodo(c,"C");
	grafo.insNodo(d,"D");
	grafo.insNodo(f,"F");
	grafo.insNodo(g,"G");

	grafo.insArco(a,b,arco1,"(A,B)");
	grafo.insArco(a,d,arco2,"(A,D)");
	grafo.insArco(b,c,arco3,"(B,C)");
	grafo.insArco(c,a,arco4,"(C,A)");
	grafo.insArco(d,c,arco5,"(D,C)");
	grafo.insArco(c,f,arco6,"(C,F)");
	grafo.insArco(c,g,arco7,"(C,G)");
	grafo.insArco(f,g,arco8,"(F,G)");
	grafo.insArco(g,d,arco9,"(G,D)");
}

template<class tipoArco,class tipoNodo>
void stampaListaNodi(Grafo<tipoArco,tipoNodo> &grafo){
	CellaGrafo<tipoNodo>* posizione;
	    Nodo<CellaGrafo<tipoNodo>*>* pos = grafo.listaNodi.primoLista();
	    Nodo<CellaGrafo<tipoNodo>*>* pos_adi;
	    Lista<CellaGrafo<tipoNodo>*, Nodo<CellaGrafo<tipoNodo>*>*> Adiacenti;
	    while (pos != NULL) {
	    	Adiacenti.creaLista();
	    	posizione = pos->getElemento();
	    	Adiacenti = grafo.adiacenti(posizione);
	    	cout << endl;
	    	cout << "Nodo# " << pos->getElemento()->getInfoNodo() << " ";
	    	pos_adi = Adiacenti.primoLista();
	    	while (pos_adi != NULL) {
	    		cout << "adiacenti# " << pos_adi->getElemento()->getInfoNodo() << " ";
	                     pos_adi = Adiacenti.succLista(pos_adi);
	    	}
	    	cout << "   " << endl;
	    	pos = grafo.listaNodi.succLista(pos);
	    }
	    cout << endl << endl;
}

template<class tipoArco,class tipoNodo>
void stampaArchi(Grafo<tipoArco,tipoNodo> &grafo) {
    Nodo<ArcoGrafo<tipoArco,tipoNodo>*>* pos = grafo.listaArchi.primoLista();
    while (pos != NULL) {
    	cout << "Arco#" << pos->getElemento()->getInfoArco() << " "
                            << pos->getElemento()->getNodoPartenza()->getInfoNodo() << "->"
                            << pos->getElemento()->getNodoArrivo()->getInfoNodo() << endl;
    	pos = grafo.listaArchi.succLista(pos);
    }
    cout << endl << endl;

}


template<class tipoArco,class tipoNodo>
int numVertici(Grafo<tipoArco,tipoNodo> &grafo){
	int i = 0;
	Nodo<CellaGrafo<tipoNodo>*>* pos = grafo.listaNodi.primoLista();
	while(!grafo.listaNodi.fineLista(pos)){
		pos = grafo.listaNodi.succLista(pos);
		i++;
	}
	return i;
}

template<class tipoArco,class tipoNodo>
int numArchi(Grafo<tipoArco,tipoNodo> &grafo){
	int i = 0;
		Nodo<ArcoGrafo<tipoArco,tipoNodo>*>* pos = grafo.listaArchi.primoLista();
		while(!grafo.listaArchi.fineLista(pos)){
			pos = grafo.listaArchi.succLista(pos);
			i++;
		}
		return i;
}


template<class tipoArco, class tipoNodo>
void esaminaNodo(Grafo<tipoArco,tipoNodo> &grafo, CellaGrafo<tipoNodo>* u){
	cout<<u->getInfoNodo()<<"  ";
}

template<class tipoArco, class tipoNodo>
void azzeraVertici(Grafo<tipoArco,tipoNodo> &grafo){
	CellaGrafo<tipoNodo>* u;
	Nodo<CellaGrafo<tipoNodo>*>* pos;
	if(!grafo.listaNodi.listaVuota()){
		pos = grafo.listaNodi.primoLista();
		while(!grafo.listaNodi.fineLista(pos)){
			u = grafo.listaNodi.leggiLista(pos);
			u->setVisitato(false);
			pos = grafo.listaNodi.succLista(pos);
		}
	}
}


template<class tipoArco,class tipoNodo>
void visitaAmpiezza(Grafo<tipoArco,tipoNodo> &grafo, CellaGrafo<tipoNodo>* u){
	azzeraVertici(grafo);			//MARCA TUTTI I VERTICI COME INESPLORATI
	Queue<CellaGrafo<tipoNodo>*> coda;
	Nodo<CellaGrafo<tipoNodo>*>* pos; 		//PUNTATORE PER LISTA ADIACENZA
	CellaGrafo<tipoNodo>* adiacente;		//CELLA ADIACENTE AL GENERICO NODO
	coda.createQueue();
	coda.enqueue(u);
	u->setVisitato(true);
	u->setDistanza(0);
	esaminaNodo(grafo,u);
	while(!coda.isEmpty()){
		u = coda.first();
		coda.dequeue();
		pos = grafo.adiacenti(u).primoLista();
		while(!grafo.adiacenti(u).fineLista(pos)){
			adiacente = grafo.adiacenti(u).leggiLista(pos);
			if(adiacente->getVisitato()==false){
				adiacente->setVisitato(true);
				adiacente->setDistanza(u->getDistanza()+1);
				coda.enqueue(adiacente);
				esaminaNodo(grafo,adiacente);
			}
			pos = grafo.adiacenti(u).succLista(pos);
		}

	}

}

template <class tipoArco,class tipoNodo>
void dfs(Grafo<tipoArco,tipoNodo> &grafo, CellaGrafo<tipoNodo>* u){
	azzeraVertici(grafo);
	DfsVisita(grafo,u);
}

template<class tipoArco,class tipoNodo>
void DfsVisita(Grafo<tipoArco,tipoNodo> &grafo, CellaGrafo<tipoNodo>* u){
	u->setVisitato(true);
	esaminaNodo(grafo,u);
	Nodo<CellaGrafo<tipoNodo>*>* pos;
	CellaGrafo<tipoNodo>* adiacente;
	pos = grafo.adiacenti(u).primoLista();
	while(!grafo.adiacenti(u).fineLista(pos)){
		adiacente = grafo.adiacenti(u).leggiLista(pos);
		if(adiacente->getVisitato()==false){
			DfsVisita(grafo,adiacente);
		}
		pos = grafo.adiacenti(u).succLista(pos);
	}

}






#endif /* SERVIZIGRAFOTEMPLATE_H_ */
