#include "orden_lecturas.h"

Orden_lecturas::Orden_lecturas(Lista<Lectura>* lecturas, Diccionario* escritores, Grafo* grafo):Opcion(lecturas,escritores){

    this-> grafo = grafo;
    kruskal = new Kruskal(grafo->obtener_matriz(),grafo->obtener_vertices());
    arbol_minimo = nullptr;

}

void Orden_lecturas::ejecutar_opcion(){

    introduccion("ARBOL MINIMO DE TODAS LAS LECTURAS");

    if (arbol_minimo == nullptr)
        buscar_orden();
    kruskal -> mostrar();

}

void Orden_lecturas::buscar_orden() {
    kruskal -> buscar_arbol_minimo();
    arbol_minimo = kruskal->obtener_arbol_minimo();

}

Orden_lecturas::~Orden_lecturas(){
    delete kruskal;
}
