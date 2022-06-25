#ifndef LISTAS_CARGA_LECTURAS_H
#define LISTAS_CARGA_LECTURAS_H
#include <iostream>
#include <string>
#include "lista.h"
#include "archivo.h"
#include "lectura.h"
#include "novela.h"
#include "cuento.h"
#include "poema.h"
#include "historica.h"

const string CUENTO = "C";
const string POEMA = "P";
const string NOVELA = "N";


class Carga_lecturas {
//atributos
private:
    Archivo archivo;
    Lista<Lectura>* lista;
    Lista<Escritor>* lista_escritores;
    string tipo;
    Lectura* lectura;

//metodos
public:

    // Pre: 
    // Post: Constructor de la clase carga_lecturas
    explicit Carga_lecturas(string nombre_archivo, Lista<Escritor>* escritores);

    // Pre: 
    // Post: Carga una lista de lectura
    void cargar_lista(string nombre_archivo);

    // Pre: -
    // Post: Devuelve la lista de lecturas
    Lista<Lectura>* obtener_lista();

private:

    // Pre: -
    // Post: Crea una lectura
    void crear_lectura();

    // Pre: -
    //Post: Le asigna el escritor a la lectura
    Escritor* asignar_escritor(string escritor_str);

    // Pre: -
    // Post: Asigna el genero de la novela
    Novela::Genero asignar_genero(string genero_str);
};



#endif //LISTAS_CARGA_LECTURAS_H
