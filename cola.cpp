#include "cola.h"

Cola::Cola() {
    frente = NULL;
    fin = NULL;
}


Cola::~Cola() {
    while(!cola_vacia()){
        quitar();
    }
}


void Cola::insertar_cola(Lectura** _dato) {
    auto *nuevo_nodo = new Nodo<Lectura*>(_dato);

    if(cola_vacia()) {
        frente = nuevo_nodo;
    }
    else {
        fin->cambiar_siguiente(nuevo_nodo);
    }

    fin = nuevo_nodo;
}


void Cola::mostrar() {
    Nodo<Lectura*> *aux = frente;
    while(aux != NULL) {
        Lectura** dato_aux = aux->obtener_dato();
        (*dato_aux)->mostrar();
        aux = aux->obtener_siguiente();
    }
}

Lectura** Cola::obtener_primero() {
    return frente->obtener_dato();
}



void Cola::quitar() {
    if(frente != NULL) {

        Nodo<Lectura*> *aux = frente;
        frente = frente->obtener_siguiente();
        delete aux;
    }
}



bool Cola::cola_vacia() {
    if(frente == NULL)
        return true;

    else
        return false;
}