#include "posicion.h"

Posicion::Posicion(){

    this->fila = 1;

    this->columna = 1;
}

Posicion::Posicion(int fila, int columna){

    this->fila = fila;

    this->columna = columna;

}

void Posicion::cambiar_fila(int fil){

    this->fila = fil;

}

void Posicion::cambiar_columna(int col){

    this->columna = col;

}

int Posicion::obtener_fila(){

    return fila;

}

int Posicion::obtener_columna(){

    return columna;

}


