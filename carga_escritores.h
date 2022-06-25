#ifndef LISTAS_CARGA_ESCRITORES_H
#define LISTAS_CARGA_ESCRITORES_H
#include "escritores.h"
#include "lectura.h"
#include "archivo.h"
#include "lista.h"

class Carga_escritores {
//atributos
private:
    Archivo archivo;
    Escritor* escritor;
    int posicion;
    Lista<Escritor>* lista;

//metodos
public:
    // Pre: 
    // Post: Constructor de la clase carga_escritores
    Carga_escritores(string nombre_archivo);

    // Pre: 
    // Post: Carga una lista de escritores
    void cargar_lista(string nombre_archivo);

    // Pre: -
    // Post: Crea una lista de escritores
    void crear_escritor();

    // Pre: -
    // Post: Devuelve la lista de escritores
    Lista<Escritor>* obtener_lista();
};


#endif //LISTAS_CARGA_ESCRITORES_H
