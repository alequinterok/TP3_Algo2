#ifndef TP3_LISTAR_H
#define TP3_LISTAR_H

#include "opcion.h"

const int CANTIDAD_GENEROS = 7;

class Listar: public Opcion{
//Atributos
private:
    int tipo;
//Métodos

    // Pre: -
    // Post: Imprime por pantalla los escritores de la lista.
    void listar_escritores();

    // Pre: -
    // Post: Imprime por pantalla las lecturas de la lista.
    void listar_lecturas();

    // Pre: -
    // Post: Imprime por pantalla las lecturas entre determinados años ingresados por el usuario.
    void lecturas_entre_anios();

    // Pre: -
    // Post: Imprime por pantalla las novelas de un determinado género ingresado por el usuario.
    void novela_de_genero();

    //Pre:-
    //Post: Devueve el ISNI del escritor elegido por el usuario
    int elegir_escritor();

    // Pre: -
    // Post: Imprime por pantalla las lecturas de un determinado escritor ingresado por el usuario.
    void lecturas_del_escritor();

    // Pre: -
    // Post: Imprime por pantalla una lectura de manera aleatoria y la marca como leida.
    void lectura_al_azar();

public:

    // Pre: -
    // Post: Constructor de la clase
    Listar(Lista<Lectura>* lecturas, Diccionario* escritores,int tipo);

    // Pre: -
    // Post: Ejecuta la opción.
    void ejecutar_opcion() override;

};


#endif //TP3_LISTAR_H
