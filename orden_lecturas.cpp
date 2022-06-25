#include "orden_lecturas.h"

Orden_lecturas::Orden_lecturas(Lista<Lectura>* lecturas, Diccionario* escritores, Grafo* grafo):Opcion(lecturas,escritores){

    this-> grafo = grafo;

}

void Orden_lecturas::ejecutar_opcion(){

    introduccion("ORDEN Y TIEMPO MINIMO PARA LEER TODAS LAS LECTURAS");

}
