#include "archivo.h"


Archivo::Archivo(){
}

void Archivo::abrir_archivo(string nombre) {

    archivo.open(nombre);

    if(archivo.fail()) {
        cout << "\nError al abrir el archivo" << endl;
        exit(1);
    }
}

string Archivo::leer_linea() {
    getline(archivo, linea);
    return linea;
}

void Archivo::cerrar_archivo() {
    archivo.close();
}

bool Archivo::fin_de_archivo() {
    return archivo.eof();
}