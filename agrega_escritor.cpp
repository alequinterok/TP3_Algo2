#include "agrega_escritor.h"

Agrega_escritor::Agrega_escritor(Lista<Lectura> *lecturas, Diccionario *escritores): Opcion(lecturas,escritores) {
    nuevo = NULL;
    existe = false;
}

void Agrega_escritor::ingreso_nombre() {
    cout << "Nombre del escritor: ";
    cin.ignore();
    getline(cin, nombre);

}

void Agrega_escritor::escritor_existente() {

    Escritor* aux = escritores->obtener_elemento(isni);

    if (aux != NULL){
        existe = true;

        cout << " -- escritor reconocido -- " << endl;
        cout << aux->obtener_nombre_apellido() << endl;


    }
}

void Agrega_escritor::ingreso_nacionalidad() {
    cout << "Nacionalidad: ";
    cin >> nacionalidad;
}

void Agrega_escritor::ingreso_nacimiento() {
    nacimiento = input_numero("Anio de nacimiento (En caso de no tener dato, ingrese 1)");
    if (nacimiento == 1){
        nacimiento = ANIO_DESCONOCIDO;
    }
}

void Agrega_escritor::ingreso_fallecimiento() {
    fallecimiento = input_numero("Anio de fallecimiento (En caso de no tener dato, ingrese 1)");
    if (fallecimiento == 1){
        fallecimiento = SIGUE_VIVO;
    }

    if (nacimiento != ANIO_DESCONOCIDO){
        while (fallecimiento != SIGUE_VIVO && fallecimiento < nacimiento) {
            cout << "\nEl año de fallecimiento no puede ser menor que el año de nacimiento." << endl;
            fallecimiento = input_numero("Anio de fallecimiento");
            if (fallecimiento == 1){
                fallecimiento = SIGUE_VIVO;
            }
        }
    }
}

void Agrega_escritor::ingreso_isni(){

    isni = input_isni();

}

Escritor *Agrega_escritor::nuevo_escritor() {

    ingreso_isni();

    escritor_existente();

        if (!existe){

            ingreso_nombre();

            ingreso_nacionalidad();

            ingreso_nacimiento();

            ingreso_fallecimiento();

            nuevo = new Escritor(nombre, nacionalidad, nacimiento, fallecimiento, isni);
            escritores->agregar_escritor(nuevo);
        }

    return nuevo;
}

void Agrega_escritor::ejecutar_opcion() {
    introduccion("NUEVO ESCRITOR");
    nuevo_escritor();
    if(!existe)
        cout << "\n -- Nuevo escritor agregado -- \n" << endl;
}
