#include "carga_grafo.h"

Carga_grafo::Carga_grafo(Lista<Lectura>* lecturas) {
    grafo = new Grafo;
    for(int i = 1; i < lecturas -> obtener_cantidad()+1; i++){
        if(!(lecturas ->obtener_dato_en(i)->obtener_leida())){
            grafo ->agregar_vertice(lecturas ->obtener_dato_en(i));
        }
    }
}

Grafo* Carga_grafo::obtener_grafo() {
    return grafo;
}