#include "cuento.h"


Cuento::Cuento(std::string titulo, int minutos, int anio, Escritor *autor, std::string libro) : Lectura(titulo,minutos,anio,autor){
    this->libro = libro;
}

std::string Cuento::obtener_libro() {
    return libro;
}

string Cuento::obtener_tipo() {
    return "CUENTO";
}

void Cuento::mostrar() {
    Lectura::mostrar();
    cout << "- tipo: Cuento" << endl;
    cout << "- libro: " << libro << endl;
}

Cuento::~Cuento(){
}