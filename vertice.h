#ifndef MAIN___TP2_VERTICE_H
#define MAIN___TP2_VERTICE_H

#include <string>
#include "lectura.h"
using namespace std;

class Vertice {
/*ATRIBUTOS*/
private:
    Lectura* lectura;

/*MÉTODOS*/
public:
    Vertice(Lectura* lectura);

    //post: obtiene la lectura en el vertice
    Lectura* obtener_lectura();

    ~Vertice();
};


#endif //MAIN___TP2_VERTICE_H
