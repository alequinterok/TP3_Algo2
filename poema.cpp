#include "poema.h"

Poema::Poema(std::string titulo, int minutos, int anio, Escritor* autor, int versos ) : Lectura(titulo,minutos,anio,autor) {
    this->versos = versos;
}

int Poema::obtener_versos() {
    return versos;
}

void Poema::mostrar() {
    Lectura::mostrar();
    cout << "-Tipo: Poema" << endl;
    cout << " -Versos: " << versos << endl;
}

Poema::~Poema(){

}
