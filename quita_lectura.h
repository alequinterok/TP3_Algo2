#ifndef TP3_QUITA_LECTURA_H
#define TP3_QUITA_LECTURA_H

#include "opcion.h"



class Quita_lectura: public Opcion{
//Atributos
private:
    int posicion;

//Métodos
public:
    // Pre: -
    // Post: Constructor de la clase
    Quita_lectura(Lista<Lectura>* lecturas, Lista<Escritor>* escritores);

    // Pre: -
    // Post: Pide al usuario que ingrese lo que esta en tipo hasta que el ingreso sea válido.
    int input_numero(string texto);

    //Pre: -
    //Post: Imprime por pantalla la introducción a la opción elegida.
    void introduccion(string opcion) override;

    //Pre: -
    //Post: True si si confirma que se quiere quitar la lectura, False si no.
    bool confirmacion();

    // Pre: -
    // Post: Ejecuta la opción.
    void ejecutar_opcion() override;


};


#endif //TP3_QUITA_LECTURA_H
