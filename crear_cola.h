#ifndef TP3_CREAR_COLA_H
#define TP3_CREAR_COLA_H

#include "opcion.h"

class Crear_cola: public Opcion {
//Atributos
private:
    Cola* cola;
    int tipo;

//Métodos

    // Pre: -
    // Post: Crea la cola de lecturas
    void crear_cola();

    // Pre: -
    // Post: Ejecuta la opción leer lectura
    void leer_una_lectura();

public:

    // Pre: -
    // Post: Constructor de la clase
    Crear_cola(Lista<Lectura>* lecturas, Diccionario* escritores, Cola* cola, int tipo);

    // Pre: -
    // Post: Ejecuta la opción.
    void ejecutar_opcion() override;


};


#endif //TP3_CREAR_COLA_H
