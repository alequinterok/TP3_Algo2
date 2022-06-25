#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include <iostream>
#include <string>
#include "lectura.h"
#include "nodo.h"
using namespace std;

class Cola {

private:
    
    Nodo<Lectura*> *frente;
    Nodo<Lectura*> *fin;

public:
    // Pre: -
    // Post: Constructor de la clase cola
    Cola();
    
    // Pre: -
    // Post: Destructor de la cola
    ~Cola();

    // Pre: El nodo a insertar no debe estar en la cola
    // Post: Inserta un elemento en la cola
    void insertar_cola(Lectura**);

    // Pre: -
    // Post: Muestra los elementos de la cola
    void mostrar();

    // Pre: -
    // Post: Muestra el primer elemento de la cola
    Lectura** obtener_primero();

    // Pre: -
    // Post: Quita el primer elemento de la cola
    void quitar();


    // Pre: -
    // Post: Devuelve true si la cola esta vacia
    bool cola_vacia();
};

#endif // COLA_H_INCLUDED 