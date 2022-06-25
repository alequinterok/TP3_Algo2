#include "opcion.h"

Opcion::Opcion(Lista<Lectura> *lecturas, Diccionario *escritores) {
    this -> lecturas = lecturas;
    this -> escritores = escritores;
}

void Opcion::imprimir_opciones() {
    cout << "+-----------------------------------------------------------------------------------+" << endl;
    cout << "| Menu principal:                                                                   |" << endl;
    cout << "|                                                                                   |" << endl;
    cout << "| 1) Agregar una nueva lectura a la lista.                                          |" << endl;
    cout << "| 2) Quitar una lectura de la lista.                                                |" << endl;
    cout << "| 3) Agregar un escritor.                                                           |" << endl;
    cout << "| 4) Cambiar dato de un escritor.                                                   |" << endl;
    cout << "| 5) Listar los escritores.                                                         |" << endl;
    cout << "| 6) Sortear una lectura random para leer.                                          |" << endl;
    cout << "| 7) Listar todas las lecturas.                                                     |" << endl;
    cout << "| 8) Listar las lecturas entre determinados años.                                   |" << endl;
    cout << "| 9) Listar las lecturas de un determinado escritor.                                |" << endl;
    cout << "| 10) Listar las novelas de determinado género.                                     |"  << endl;
    cout << "| 11) Cola de lecturas no leidas ordenada por tiempo de lectura, de menor a mayor.  |" << endl;
    cout << "| 12) Leer la primera lectura de la cola.                                           |" << endl;
    cout << "| 13) Ver orden y tiempo minimo para leer todas las lecturas                        |" << endl;
    cout << "| 14) Salir.                                                                        |" << endl;
    cout << "|                                                                                   |"<< endl;
    cout << "+-----------------------------------------------------------------------------------+" << endl;
}

bool Opcion::entrada_valida(string cadena) {
    bool es_numerico = true;

    for(char i : cadena){
        if( '0' > i || '9' < i )
            es_numerico = false;
    }

    return es_numerico;
}

int Opcion::input_numero(string texto) {
    string numero_str;

    cout << texto << ": ";
    cin >> numero_str;

    while(!entrada_valida(numero_str)){
        cout << "entrada inválida" << endl;
        cout << "Ingrese " << texto << ": ";
        cin >> numero_str;
    }

    return stoi(numero_str);
}

int Opcion::input_isni(){

    string isni_str;

    cout << "ISNI: ";
    cin >> isni_str;

    if (isni_str.length() != CANT_DIGITOS_ISNI ||
        !entrada_valida(isni_str)){
        cout << "Recuerde que el ISNI es un numero de 4 digitos" << endl;
        cout << "Ingrese ISNI: ";
        cin >> isni_str;
    }

    return stoi(isni_str);
}

void Opcion::introduccion(string opcion) {
    cout << "\n"<<opcion<<"\n" << endl;
}

void Opcion::ejecutar_opcion() {}

Opcion::~Opcion() {};
