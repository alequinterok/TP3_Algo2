#include "arista.h"

Arista::Arista(int _peso, int _vertice_a, int _vertice_b) {
    this->peso = _peso;
    this->vertice_a = _vertice_a;
    this->vertice_b = _vertice_b;
}

int Arista::obtener_peso() {
    return peso;
}

int Arista::obtener_vertice_a() {
    return vertice_a;
}

int Arista::obtener_vertice_b() {
    return vertice_b;
}


int Arista::comparar(Arista otra_arista) {
    if(otra_arista.obtener_peso() > peso)
        return MENOR;
    else if(otra_arista.obtener_peso() < peso)
        return MAYOR;
    else
        return IGUAL;
}