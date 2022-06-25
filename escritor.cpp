#include "escritor.h"
#include <iostream>

using namespace std;

Escritor::Escritor(string nombre_apellido, string nacionalidad, int anio_nacimiento, int anio_fallecimiento, int isni) {

    this->nombre_apellido = nombre_apellido;

    this->nacionalidad = nacionalidad;

    this->anio_nacimiento = anio_nacimiento;

    this->anio_fallecimiento = anio_fallecimiento;

    this->isni = isni;

}

void Escritor::modificar_anio_fallecimiento(int anio_fallecimiento) {

    this->anio_fallecimiento = anio_fallecimiento;

}

string Escritor::obtener_nombre_apellido(){
    return nombre_apellido;
}

string Escritor::obtener_nacionalidad() {

    return nacionalidad;

}

int Escritor::obtener_anio_nacimiento() {

    return anio_nacimiento;

}

int Escritor::obtener_anio_fallecimiento() {

    return anio_fallecimiento;

}

int Escritor::obtener_isni(){
    return isni;
}

void Escritor::mostrar(){
    cout << nombre_apellido << endl;
    cout << "  - nacionalidad: " << nacionalidad << endl;
    cout << "  - anio de nacimiento: ";
    if (anio_nacimiento != ANIO_DESCONOCIDO){
        cout << anio_nacimiento << endl;
    }else{
        cout << "desconocido" << endl;
    }
    if (anio_fallecimiento != SIGUE_VIVO){
        cout << "  - anio de fallecimiento: " << anio_fallecimiento << endl;
    }
}

