#include "lectura.h"

Lectura::Lectura(){};

Lectura::Lectura(const string titulo, const int minutos, const int anio, Escritor* autor){
    this->titulo = titulo;
    this->minutos = minutos;
    this->anio = anio;
    this->autor = autor;
    leida = false;
}

string Lectura::obtener_titulo(){
    return titulo;
}

int Lectura::obtener_minutos(){
    return minutos;
}

int Lectura::obtener_anio(){
    return anio;
}

Escritor* Lectura::obtener_autor(){
    return autor;
}

int Lectura::comparar (Lectura otra_lectura){
    int comparacion = MAYOR;

    if (anio < otra_lectura.anio){
        comparacion = MENOR;
    }else if (anio == otra_lectura.anio){
        comparacion = IGUAL;
    }

    return comparacion;
}

int Lectura::comparar(Lectura otra_lectura, int a) {
    int comparacion = MAYOR;

    if (minutos < otra_lectura.obtener_minutos()){
        comparacion = MENOR;
    }else if (minutos == otra_lectura.obtener_minutos()){
        comparacion = IGUAL;
    }

    return comparacion;
}

int Lectura::obtener_genero() {
    return -1;
}

void Lectura::leer() {
    leida = true;
}

bool Lectura::obtener_leida() {
    return leida;
}

void Lectura::mostrar(){
    cout << "\nLECTURA:" << endl;
    cout << "- titulo: " << titulo << endl;
    cout << "- minutos en leerse: " << minutos << endl;
    cout << "- anio de publicacion: " << anio << endl;
    cout << "- autor: ";
    if (autor != NULL){
        autor->mostrar();
    }else{
        cout << "ANONIMO" << endl;
    }
}

Lectura::~Lectura(){
}
