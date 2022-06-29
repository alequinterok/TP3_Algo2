#ifndef ARISTA_H_INCLUDED
#define ARISTA_H_INCLUDED

#include "lectura.h"

class Arista{

private:

    int peso;
    int vertice_a;
    int vertice_b;
    
public:
    // Pre: -
    // Post: Constructor de la clase Arista
    Arista(int, int, int);

    // Pre: -
    // Post: Devuelve el peso
    int obtener_peso();
    
    // Pre: -
    // Post: Devuelve el vertice a
    int obtener_vertice_a();


    // Pre: otra_arista previamente inicializada
    /* Post: compara la arista con otra_arista segun el peso.
    * --> si el peso es mayor, devuelve MAYOR
    * --> si el peso es menor, devuelve MENOR
    * --> si son iguales devuelve IGUAL */
    int comparar(Arista otra_arista);


    // Pre: -
    // Post: Devuelve el vertice b
    int obtener_vertice_b();

};

#endif // ARISTA_H_INCLUDED