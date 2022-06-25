#ifndef NOVELA_H_INCLUDED
#define NOVELA_H_INCLUDED

#include "lectura.h"

//const string HISTORICA = "HISTORICA";

class Novela: public Lectura{
//atributos
public:
    enum Genero{DRAMA, COMEDIA, FICCION, SUSPENSO,TERROR, ROMANTICA, HISTORICA};
    Genero genero;
//metodos

    // Pre: -
    // Post: Constructor de la clase novela
    Novela(std::string titulo, int minutos, int anio, Escritor* autor, Genero genero );

    // Pre: -
    // Post: Devuelve el genero de la novela
    int obtener_genero() override;

    // Pre: -
    // Post: Imprime por pantalla la informaciòn de la novela
    void mostrar();

    // Pre: -
    // Post: Destructor de novela
    ~Novela();
};


#endif // NOVELA_H_INCLUDED
