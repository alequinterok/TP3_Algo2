#ifndef HISTORICA_H_INCLUDED
#define HISTORICA_H_INCLUDED

#include "novela.h"

class Historica: public Novela{
//atributos
private:
    char* tema;
//metodos
public:

    // Pre: -
    // Post: Constructor de la clase historica
    Historica (std::string titulo, int minutos, int anio, Escritor* autor, char* tema_);

    // Pre: -
    //Post: Devuelve el tema de la novela historica
    char* obtener_tema();

    // Pre: -
    // Post: Imprime por pantalla la informacion de la novela historica
    void mostrar();

    // Pre: -
    // Post: Destructor de historica
    ~Historica();
};


#endif // HISTORICA_H_INCLUDED
