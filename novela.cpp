#include "novela.h"

Novela::Novela(std::string titulo, int minutos, int anio, Escritor* autor, Genero genero ) : Lectura(titulo,minutos,anio,autor) {
    this->genero = genero;
};

int Novela::obtener_genero() {
    return genero;
}

string Novela::obtener_tipo() {
    return "NOVELA";
}

void Novela::mostrar(){
    Lectura::mostrar();
    cout << "- tipo: Novela" << endl;
    cout << "- genero: ";
    switch (genero) {
        case DRAMA:
            cout << "Drama" << endl;
            break;
        case COMEDIA:
            cout << "Comedia" << endl;
            break;
        case FICCION:
            cout << "Ficción" << endl;
            break;
        case SUSPENSO:
            cout << "Suspenso" << endl;
            break;
        case TERROR:
            cout << "Terror" << endl;
            break;
        case ROMANTICA:
            cout << "Romántica" << endl;
            break;
        case HISTORICA:
            cout << "Histórica" << endl;
            break;

    }

}

Novela::~Novela(){
}