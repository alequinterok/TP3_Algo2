#ifndef LISTAS_CARGA_ESCRITORES_H
#define LISTAS_CARGA_ESCRITORES_H
#include "escritor.h"
#include "lectura.h"
#include "archivo.h"
#include "lista.h"
#include "diccionario.h"

class Carga_escritores {
//atributos
private:
    Archivo archivo;
    Escritor* escritor;
    Diccionario* diccionario_escritores;

//metodos
public:
    // Pre:
    // Post: Constructor de la clase carga_escritores
    Carga_escritores(string nombre_archivo);

    int identificar_isni (string isni_bruto);

    // Pre:
    // Post: Carga una lista de escritores
    void cargar_diccionario(string nombre_archivo);

    // Pre: -
    // Post: Crea una lista de escritores
    void crear_escritor();

    // Pre: -
    // Post: Devuelve la lista de escritores
    Diccionario* obtener_diccionario();
};


#endif //LISTAS_CARGA_ESCRITORES_H
