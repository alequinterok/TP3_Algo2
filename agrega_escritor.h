#ifndef TP3_AGREGA_ESCRITOR_H
#define TP3_AGREGA_ESCRITOR_H

#include "opcion.h"

class Agrega_escritor: public Opcion{
//Atributos
protected:
    Escritor* nuevo;
    string nombre;
    string nacionalidad;
    int nacimiento;
    int fallecimiento;
    bool existe;


//Métodos
public:
    // Pre: -
    // Post: Constructor de la clase
    Agrega_escritor(Lista<Lectura>* lecturas, Lista<Escritor>* escritores);

    // Pre: -
    // Post: asigna el nombre ingresado por el usuario
    void ingreso_nombre();

    // Pre: -
    // Post: asigna la nacionalidad ingresada por el usuario
    void ingreso_nacionalidad();

    // Pre: -
    // Post: asigna el anio de nacimiento ingresado por el usuario
    void ingreso_nacimiento();

    // Pre: -
    // Post: asigna el anio de fallecimiento ingresado por el usuario
    void ingreso_fallecimiento();

    // Pre: -
    // Post: True si el escritor ya esta en la lista, False si no.
    void escritor_existente();

    // Pre: -
    // Post: Devuelve un puntero a un escritor nuevo creado por el usuario
    Escritor* nuevo_escritor();

    // Pre: -
    // Post: Ejecuta la opción.
    void ejecutar_opcion() override;
};


#endif //TP3_AGREGA_ESCRITOR_H
