#include "cambia_dato.h"

Cambia_dato::Cambia_dato(Lista<Lectura> *lecturas, Diccionario *escritores): Opcion(lecturas,escritores) {
    isni = -1;
    nuevo_fallecimiento = -1;
}

void Cambia_dato::introduccion(string opcion) {
    Opcion::introduccion(opcion);
    escritores->mostrar();
}


void Cambia_dato::input_numero(string texto) {
    nuevo_fallecimiento = Opcion::input_numero(texto);

    int anio_nacimiento = escritores->obtener_elemento(isni)->obtener_anio_nacimiento();
    if (anio_nacimiento != ANIO_DESCONOCIDO){
        while (nuevo_fallecimiento < anio_nacimiento) {
            cout << "\nEl año de fallecimiento no puede ser menor que el año de nacimiento." << endl;
            nuevo_fallecimiento = Opcion::input_numero(texto);
        }
    }
}

void Cambia_dato::ejecutar_opcion() {

    introduccion("CAMBIAR DATO DE ESCRITOR");
    cout << "Ingrese el ISNI del escritor que quiere modificar" << endl;
    isni = input_isni();

    Escritor* escritor = escritores->obtener_elemento(isni);

    if (escritor != NULL){

        cout << "\nPuede modificar el anio de fallecimiento \n" << endl;

        input_numero("Ingrese el anio de fallecimiento");

        escritor->modificar_anio_fallecimiento(nuevo_fallecimiento);

        cout << "\n-- fecha de fallecimiento modificada QEPD --" << endl;

    }else{
        cout << "No existe tal escritor" << endl;
    }



}
