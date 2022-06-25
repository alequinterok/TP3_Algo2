#include "historica.h"

Historica::Historica(std::string titulo, int minutos, int anio, Escritor* autor, char* tema): Novela(titulo,minutos,anio,autor,HISTORICA) {
    this->tema = tema;
};

char* Historica::obtener_tema() {
    return tema;
}

void Historica::mostrar() {
    Novela::mostrar();
    cout << " -Tema: " << tema << endl;
}

Historica::~Historica(){
    delete [] tema;
}
