#ifndef POEMA_H_INCLUDED
#define POEMA_H_INCLUDED

#include "lectura.h"

class Poema: public Lectura{
//atributos
private:
    int versos;
//metodos
public:
    // Pre: -
    // Post: Constructor de la clase poema
    Poema(std::string titulo, int minutos, int anio, Escritor* autor, int versos);

    // Pre: -
    // Post: Devuelve la cantidad de versos del poema
    int obtener_versos();

    // Pre: -
    // Post: Imprime por pantalla la informacion del poema
    void mostrar();

    // Pre: -
    // Post: Destructor de poema
    ~Poema();
};

#endif // POEMA_H_INCLUDED
