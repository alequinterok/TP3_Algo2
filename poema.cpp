#include "poema.h"

Poema::Poema(std::string titulo, int minutos, int anio, Escritor* autor, int versos ) : Lectura(titulo,minutos,anio,autor) {
    this->versos = versos;
}

int Poema::obtener_versos() {
    return versos;
}

string Poema::obtener_tipo() {
    return "P";
}

void Poema::mostrar() {
    Lectura::mostrar();
    cout << "- tipo: Poema" << endl;
    cout << "- versos: " << versos << endl;
}

Poema::~Poema(){

}
