#ifndef CUENTO_H_INCLUDED
#define CUENTO_H_INCLUDED

#include "lectura.h"

class Cuento: public Lectura{
//atributos
private:
    string libro;
//metodos
public:
    // Pre: -
    // Post: Constructor de la clase cuento
    Cuento(string titulo, int minutos, int anio, Escritor* autor, string libro);

    // Pre: -
    // Post: Devuelve el libro al que pertenece el cuento
    std::string obtener_libro();

    // Pre: -
    // Post: Imprime por pantalla la informacion del cuento
    void mostrar();

    // Pre: -
    // Post: Destructor de cuento
    ~Cuento();
};


#endif // CUENTO_H_INCLUDED
