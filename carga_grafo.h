#ifndef TP3_CARGA_GRAFO_H
#define TP3_CARGA_GRAFO_H

#include <iostream>
#include <string>
#include "lista.h"
#include "lectura.h"
#include "vertice.h"
#include "grafo.h"

class Carga_grafo {

private:
    Grafo* grafo;
public:
    Carga_grafo(Lista<Lectura>* lecturas);

    Grafo* obtener_grafo();
};


#endif //TP3_CARGA_GRAFO_H
