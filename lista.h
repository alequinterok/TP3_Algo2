#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

using namespace std;
#include "nodo.h"

const int PRIMERA_POSICION = 1;

template <typename Dato>

class Lista{

private:

    Nodo<Dato>* primero;
    int cantidad;
    Nodo<Dato>* cursor;

public:


    // Pre: -
    // Post: Construye una lista vacia
    Lista();


    // Pre: dato es un dato valido y la posicion se encuentra dentro de la PRIMERA_POSICION y la ultima posicion + 1
    // Post: Inserta el dato en la posicion pedida
    void alta (Dato* dato, int posicion);


    // Pre: La posicion se encuentra dentro de la PRIMERA_POSICION y la ultima posicion + 1
    // Post: Quita el dato de la posicion pedida de la lista
    void baja (int posicion);


    // Pre: La posicion se encuentra dentro de la PRIMERA_POSICION y la ultima posicion + 1
    // Post: Devuelve el dato en la posicion pedida
    Dato* obtener_dato_en (int posicion);


    // Pre: -
    // Post: Devuelve true si la lista esta vacia y false en caso contrario
    bool vacia ();


    // Pre: -
    // Post: Devuelve la cantidad de datos que tiene la lista
    int obtener_cantidad ();

    // Pre: -
    // Post: Destructor de la lista
    ~Lista();

private:


    // Pre: La posicion se encuentra dentro de la PRIMERA_POSICION y la ultima posicion + 1
    // Post: Devuelve la direccion del nodo en la posicion pedida
    Nodo<Dato>* obtener_nodo (int posicion);

};

template <typename Dato>
Lista<Dato>::Lista(){
    primero = 0;
    cantidad = 0;
}

template <typename Dato>
bool Lista<Dato>::vacia(){
    return (cantidad == 0);
}

template <typename Dato>
int Lista<Dato>::obtener_cantidad(){
    return cantidad;
}

template <typename Dato>
Dato* Lista<Dato>::obtener_dato_en(int posicion){

    Nodo<Dato>* aux = obtener_nodo(posicion);

    return (aux->obtener_dato());
}

template <typename Dato>
Nodo<Dato>* Lista<Dato>::obtener_nodo(int posicion){
    Nodo<Dato>* buscado = primero;
    int contador = PRIMERA_POSICION;
    while (contador < posicion){
        buscado = buscado->obtener_siguiente();
        contador++;
    }
    return buscado;
}

template <typename Dato>
void Lista<Dato>::alta(Dato* dato, int posicion){
    Nodo<Dato>* nuevo = new Nodo<Dato>(dato);

    if (posicion == PRIMERA_POSICION){
        nuevo->cambiar_siguiente(primero);
        primero = nuevo;
    }else{
        Nodo<Dato>* anterior = obtener_nodo(posicion - 1);
        nuevo->cambiar_siguiente(anterior->obtener_siguiente());
        anterior->cambiar_siguiente(nuevo);

    }
    cantidad++;
}

template <typename Dato>
void Lista<Dato>::baja(int posicion){
    Nodo<Dato>* borrar = primero;

    if(posicion == PRIMERA_POSICION){
        primero = primero->obtener_siguiente();
    }
    else{
        Nodo<Dato>* anterior = obtener_nodo(posicion -1);
        borrar = anterior->obtener_siguiente();

        anterior->cambiar_siguiente(borrar->obtener_siguiente());
    }
    cantidad--;

    delete borrar;
}

template <typename Dato>
Lista<Dato>::~Lista(){
    while (!vacia()){
        baja(PRIMERA_POSICION);
    }
}


#endif // LISTA_H_INCLUDED
