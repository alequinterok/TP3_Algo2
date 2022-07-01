#ifndef ORDEN_LECTURAS_H_INCLUDED
#define ORDEN_LECTURAS_H_INCLUDED

#include "opcion.h"

class Orden_lecturas: public Opcion{

private:

    Grafo* grafo;
    Kruskal* kruskal;
    Grafo* arbol_minimo;

    //pre: -
    //post: Busca el arbol minimo.
    void buscar_orden();

public:

    // Pre: -
    // Post: Constructor de clase.
    Orden_lecturas(Lista<Lectura>* lecturas, Diccionario* escritores, Grafo* grafo);

    // Pre: -
    // Post: Ejecuta la opción.
    void ejecutar_opcion() override;

    // Pre: -
    // Post: destructor de clase.
    ~Orden_lecturas() override;
};

#endif // ORDEN_LECTURAS_H_INCLUDED
