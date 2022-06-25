#include "cuento.h"


Cuento::Cuento(std::string titulo, int minutos, int anio, Escritor *autor, std::string libro) : Lectura(titulo,minutos,anio,autor){
    this->libro = libro;
}

std::string Cuento::obtener_libro() {
    return libro;
}

void Cuento::mostrar() {
    Lectura::mostrar();
    cout << "-Tipo: Cuento" << endl;
    cout << " -Libro: " << libro << endl;
}

Cuento::~Cuento(){
}