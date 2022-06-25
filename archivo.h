#ifndef LISTAS_ARCHIVO_H
#define LISTAS_ARCHIVO_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Archivo {
//atributos
protected:
    ifstream archivo;
    string linea;

//metodos
public:
    // Pre: -
    // Post: Constructor de la clase archivo
    Archivo();

    // Pre: Debe existir el archivo y al pasarlo por parametro debe ser un string
    //Post: Abre el archivo
    void abrir_archivo(string nombre);

    // Pre: -
    // Post: Lee una linea del archivo y la retorna
    string leer_linea();

    // Pre: Debe haberse abierto el archivo
    // Post: Cierra el archivo
    void cerrar_archivo();

    // Pre: -
    //Post: Devuelve true si llego al fin del archivo
    bool fin_de_archivo();
};

#endif //LISTAS_ARCHIVO_H
