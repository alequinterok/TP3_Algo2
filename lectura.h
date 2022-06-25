#ifndef LECTURA_H_INCLUDED
#define LECTURA_H_INCLUDED

#include <iostream>
#include <string.h>
#include "escritores.h"

const int MAYOR = 1;
const int MENOR = -1;
const int IGUAL = 0;

class Lectura{

protected:
    string titulo;
    int minutos;
    Escritor* autor;
    bool leida;

    // Pre: -
    // Post: Constructor de la clase lectura
    Lectura();

    
    // Pre: -
    // Post: Constructor de la clase lectura
    Lectura (const string titulo, const int minutos, const int anio, Escritor* autor);


public:
    int anio;
    
    // Pre: -
    // Post: Devuelve el nombre del titulo de la lectura
    string obtener_titulo();
    
    // Pre: -
    // Post: Devuelve los minutos que tarda en leerse la lectura
    int obtener_minutos();
    
    // Pre: -
    // Post: Devuelve el anio en que salio la lectura
    int obtener_anio();

    // Pre: -
    // Post: Devuelve el puntero al escritor de la lectura
    Escritor* obtener_autor();
    
    // Pre: -
    // Post: Imprime por pantalla la informacion de la lectura
    virtual void mostrar();

    // Pre: -
    // Post: Devuelve el genero de la lectura
    virtual int obtener_genero();

    // Pre: -
    // Post: Le asigna true a leida
    void leer();

    // Pre: -
    // Post: Devuelve el valor de leida
    bool obtener_leida();
    
    // Pre: -
    // Post: Destructor virtual de la clase lectura
    virtual ~Lectura();
    
    // Pre: otra_lectura previamente inicializada
    /* Post: compara la lectura con otra_lectura segun en anio en que salieron.
    * --> si el anio de lectura es mayor, devuelve MAYOR
    * --> si el anio de lectura es menor, devuelve MENOR
    * --> si son iguales devuelve IGUAL */
    int comparar (Lectura otra_lectura);

    // Pre: otra_lectura previamente inicializada
    /* Post: compara la lectura con otra_lectura segun el tiempo
    * de lectura.
    * --> si el tiempo de lectura es mayor, devuelve MAYOR
    * --> si el tiempo de lectura es menor, devuelve MENOR
    * --> si son iguales devuelve IGUAL */
    int comparar (Lectura otra_lectura, int a);

};

#endif // LECTURA_H_INCLUDED
