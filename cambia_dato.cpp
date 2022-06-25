#include "cambia_dato.h"

Cambia_dato::Cambia_dato(Lista<Lectura> *lecturas, Lista<Escritor> *escritores): Opcion(lecturas,escritores) {
    posicion = -1;
    nuevo_fallecimiento = -1;
}

void Cambia_dato::introduccion(string opcion) {
    Opcion::introduccion(opcion);
    for (int i = 1; i <= escritores->obtener_cantidad(); i++){

        cout << i << ") ";
        Escritor esc = *(escritores->obtener_dato_en(i));
        cout << esc.obtener_nombre_apellido() << endl;
    }
}

void Cambia_dato::input_numero(string texto) {
    posicion = Opcion::input_numero(texto);

    while (posicion > escritores->obtener_cantidad()){
        cout << "Ese no es un escritor valido. Intentelo de nuevo."<<endl;
        posicion = Opcion::input_numero(texto);
    }
}

void Cambia_dato::input_numero(string texto, int f) {
    nuevo_fallecimiento = Opcion::input_numero(texto);

    int anio_nacimiento = escritores->obtener_dato_en(posicion)->obtener_anio_nacimiento();
    if (anio_nacimiento != ANIO_DESCONOCIDO){
        while (nuevo_fallecimiento < anio_nacimiento) {
            cout << "\nEl año de fallecimiento no puede ser menor que el año de nacimiento." << endl;
            nuevo_fallecimiento = Opcion::input_numero(texto);
        }
    }
}

void Cambia_dato::ejecutar_opcion() {

    introduccion("CAMBIAR DATO DE ESCRITOR");
    input_numero("Ingrese el numero del escritor que quiere modificar: ");

    cout << "\nPuede modificar el anio de fallecimiento \n" << endl;
    input_numero("Ingrese el anio de fallecimiento",0);

    escritores->obtener_dato_en(posicion)->modificar_anio_fallecimiento(nuevo_fallecimiento);

    cout << "\n-- fecha de fallecimiento modificada QEPD --" << endl;


}