#ifndef DICCIONARIO_H_INCLUDED
#define DICCIONARIO_H_INCLUDED

#include <iostream>
using namespace std;

#include "escritor.h"
#include "posicion.h"
#include "lista.h"

const int TAMANIO_TABLA = 27;

class Diccionario{
private:

    Lista<Escritor>** escritores;

public:

    /*
    *pre:
    *pos: constructor de diccionario
    */
    Diccionario();

    /*
    *pre:
    *pos: muestra todos los nombres de los escritores del diccionario con su respectivo isni
    */
    void mostrar();

    /*
    *pre:
    *pos: lista todos los escritores del diccionario
    */
    void listar_escritores();

    /*
    *pre:
    *pos: agrega un nuevo puntero a Escritor al diccionario
    *     si hay un escritor de misma clave, lo sobreescribe
    */
    void agregar_escritor(Escritor* nuevo_escritor);

    /*
    *pre:
    *pos: devuelve el puntero al escritor buscado. Si no existe devuelve NULL
    */
    Escritor* obtener_elemento(int clave);

    /*
    *pre:
    *pos: elimina el escritor requerido
    *     en caso de no existir el nombre, no hace nada.
    */
    void eliminar_elemento(int clave);

    ~Diccionario();

private:

    /*
    *pre:
    *pos: devuelve una posicion deducida de la ecuacion de hash
    */
    int obtener_fila (int clave);

    /*
    *pre:
    *pos: devuelve una posicion valida correspondiente a la clave
    */
    Posicion obtener_posicion (int clave);

    /*
    *pre:
    *pos: resuelve las colisiones, devolviendo una columna valida
    */
    int colision (int clave, int i);

    /*
    *pre: pos es una posicion valida
    *post: devuelve el isni del escritor guardado en esa posicion
    */
    int obtener_isni_en (Posicion pos);

};

#endif // DICCIONARIO_H_INCLUDED
