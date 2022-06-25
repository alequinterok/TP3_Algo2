#include "agrega_escritor.h"

Agrega_escritor::Agrega_escritor(Lista<Lectura> *lecturas, Lista<Escritor> *escritores): Opcion(lecturas,escritores) {
    nuevo = NULL;
    existe = false;
}

void Agrega_escritor::ingreso_nombre() {
    cout << "Nombre del escritor: ";
    cin.ignore();
    getline(cin, nombre);

}

void Agrega_escritor::escritor_existente() {

    int i = 1;
    while (!existe && (i <= escritores->obtener_cantidad())){
        if (nombre == escritores->obtener_dato_en(i)->obtener_nombre_apellido()){
            existe = true;
            nuevo = escritores -> obtener_dato_en(i);
            cout << "\n" << "-- escritor reconocido --" << "\n" << endl;
            nuevo -> mostrar();
        }
        i++;
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

Escritor *Agrega_escritor::nuevo_escritor() {

    ingreso_nombre();
    escritor_existente();
        if (!existe){

            ingreso_nacionalidad();

            ingreso_nacimiento();

            ingreso_fallecimiento();

            nuevo = new Escritor(nombre, nacionalidad, nacimiento, fallecimiento);
            escritores->alta(nuevo, escritores->obtener_cantidad() + 1);
        }

    return nuevo;
}

void Agrega_escritor::ejecutar_opcion() {
    introduccion("NUEVO ESCRITOR");
    nuevo_escritor();
    if(!existe)
        cout << "\n -- Nuevo escritor agregado -- \n" << endl;
}
