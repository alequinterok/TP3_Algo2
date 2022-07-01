#ifndef TP3_CAMBIA_DATO_H
#define TP3_CAMBIA_DATO_H

#include "opcion.h"

class Cambia_dato: public Opcion{
//Atributos
private:
    int isni;
    int nuevo_fallecimiento;

//Métodos

    //Pre: -
    //Post: Imprime por pantalla la introducción a la opción elegida.
    void introduccion(string opcion) override;


    // Pre: -
    // Post: Pide al usuario que ingrese lo que esta en tipo hasta que el ingreso sea válido.
    void input_numero(string texto);

public:

    // Pre: -
    // Post: Constructor de la clase
    Cambia_dato(Lista<Lectura>* lecturas, Diccionario* escritores);

    // Pre: -
    // Post: Ejecuta la opción.
    void ejecutar_opcion() override;
};


#endif //TP3_CAMBIA_DATO_H
