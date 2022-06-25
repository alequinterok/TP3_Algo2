#include "quita_lectura.h"

Quita_lectura::Quita_lectura(Lista<Lectura> *lecturas, Diccionario *escritores): Opcion(lecturas,escritores) {
    posicion = -1;
}

int Quita_lectura::input_numero(string texto) {

    int numero = Opcion::input_numero(texto);

    while (numero > lecturas->obtener_cantidad()){
        cout << "Ingreso inválido"<< endl;
        numero = Opcion::input_numero(texto);
    }
    return numero;
}

bool Quita_lectura::confirmacion() {
    char confirmacion;
    cout << "Esta seguro que quiere borrar ";
    cout << lecturas->obtener_dato_en(posicion)->obtener_titulo();

    if (lecturas->obtener_dato_en(posicion)->obtener_autor() != NULL)
    cout << " de " << lecturas->obtener_dato_en(posicion)->obtener_autor()->obtener_nombre_apellido();

    cout << "? (ingrese s para si o n para no) ";
    cin >> confirmacion;
    while (confirmacion!= SI && confirmacion!= NO){
        cout << "(ingrese s para si o n para no)" << endl;
        cin >> confirmacion;
    }
    return (confirmacion == SI);
}

void Quita_lectura::introduccion(string opcion) {
    Opcion::introduccion(opcion);
    for (int i = 1; i <= lecturas->obtener_cantidad(); i++){
        cout << i << ") ";
        cout << lecturas->obtener_dato_en(i)->obtener_titulo();

        if (lecturas->obtener_dato_en(i)->obtener_autor() != NULL){
            cout << " de " << lecturas->obtener_dato_en(i)->obtener_autor()->obtener_nombre_apellido() << endl;
        }else{
            cout << endl;
        }
    }

    cout << "\n";
}

void Quita_lectura::ejecutar_opcion() {

    introduccion("QUITAR LECTURA");

    posicion = input_numero("numero de lectura que quiere borrar");

    if (confirmacion()) {
        lecturas->baja(posicion);
        cout << "-- lectura borrada --" << endl;
    }
}
