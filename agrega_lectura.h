#ifndef TP3_AGREGAR_LECTURA_H
#define TP3_AGREGAR_LECTURA_H

#include "agrega_escritor.h"

class Agrega_lectura: public Agrega_escritor{
//Atributos
private:
    Lectura* nueva;
    string tipo;
    string titulo;
    int minutos;
    int publicacion;

//Métodos
public:
    // Pre: -
    // Post: Constructor de la clase
    Agrega_lectura(Lista<Lectura>* lecturas, Lista<Escritor>* escritores);

    // Pre:
    // Post: Devuelve true si el tipo es CUENTO o POEMA o NOVELA, devuelve false en caso contrario
    bool tipo_valido();

    // Pre:
    // Post: Devuelve true si el genero es valido y false en caso contrario
    bool genero_valido(string genero);

    // Pre: -
    // Post: Devuelve un genero valido
    Novela::Genero asignar_genero();

    // Pre: -
    // Post: Pregunta al usuario, y devuelve True si el escritor es anónimo, false si no.
    bool escritor_anonimo();

    // Pre: -
    // Post: asigna el tipo ingresado por el usuario
    void ingreso_tipo();

    // Pre: -
    // Post: asigna el titulo ingresado por el usuario
    void ingreso_titulo();

    //Pre: -
    //Post: Crea una nueva lectura de tipo poema
    void tipo_poema();

    //Pre: -
    //Post: Crea una nueva lectura de tipo cuento
    void tipo_cuento();

    //Pre: -
    //Post: Crea una nueva lectura de tipo novela
    void tipo_novela();

    // Pre: -
    // Post: Ejecuta la opción.
    void ejecutar_opcion() override;
};


#endif //TP3_AGREGAR_LECTURA_H
