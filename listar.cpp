#include "listar.h"

Listar::Listar(Lista<Lectura> *lecturas, Diccionario *escritores,int tipo): Opcion(lecturas,escritores) {
    this -> tipo = tipo;
}

void Listar::listar_escritores() {

    introduccion("LISTA DE ESCRITORES");

    escritores->listar_escritores();
}

void Listar::listar_lecturas() {

    introduccion("LISTA DE LECTURAS");

    for (int i = 1; i <= lecturas->obtener_cantidad(); i++){
        lecturas->obtener_dato_en(i)->mostrar();
    }
}

void Listar::lectura_al_azar() {
    srand((unsigned int)time(nullptr));

    int numero = 1 + rand()%(lecturas->obtener_cantidad()-1);

    cout << "\nSe leerá la siguiente lectura, elegida al azar: "<< endl;
    lecturas->obtener_dato_en(numero)->mostrar();
    lecturas->obtener_dato_en(numero)->leer();
}

int Listar::elegir_escritor() {
    cout << "\nEscritores:" << endl;

    escritores->mostrar();

    int isni;

    cout << "Ingrese el ISNI asociado al escritor deseado" << endl;
    isni = input_isni();

    return isni;
}

void Listar::lecturas_del_escritor() {
    introduccion("LECTURAS DE UN ESCRITOR");

    int isni_escritor = elegir_escritor();

    if (escritores->obtener_elemento(isni_escritor) != NULL){

        cout << "\nLecturas escritas por "<< escritores->obtener_elemento(isni_escritor)->obtener_nombre_apellido() << ": " << endl;

        int cantidad = 0;
        for (int i = 1; i <= lecturas->obtener_cantidad(); i++){
            if(lecturas->obtener_dato_en(i)->obtener_autor() != NULL &&
               lecturas->obtener_dato_en(i)->obtener_autor()->obtener_isni() == isni_escritor){

                lecturas->obtener_dato_en(i)->mostrar();
                cantidad++;
            }
        }
        if(cantidad == 0)
            cout << "\nNo se encontraron lecturas escritas por este escritor. "<<endl;
    }else{
        cout << "No existe tal escritor" << endl;
    }
}

void Listar::novela_de_genero() {
    introduccion("NOVELAS DE UN GENERO");

    cout << "1- DRAMA\n2- COMEDIA\n3- FICCION\n4- SUSPENSO\n5- TERROR\n6- ROMANTICA\n7- HISTORICA"<< endl;

    int genero;
    do{
        genero = input_numero("Ingrese el número asociado al genero deseado");
    }while (1 > genero || CANTIDAD_GENEROS < genero);

    cout << "\nNovelas del genero " << genero << ": " << endl;

    for (int i = 1; i <= lecturas->obtener_cantidad(); i++){
        if(lecturas->obtener_dato_en(i)->obtener_genero() == (genero - 1))
            lecturas->obtener_dato_en(i)->mostrar();
    }
}

void Listar::lecturas_entre_anios() {
    introduccion("LECTURAS ENTRE ANIOS");

    int anio_i = input_numero("Ingrese el año inicial");
    int anio_f = input_numero("Ingrese el año final");

    if (anio_i < anio_f){
        int posicion = 1;

        while (posicion <= lecturas->obtener_cantidad() &&
               lecturas->obtener_dato_en(posicion)->obtener_anio() < anio_i) {
            posicion++;
        }

        if (posicion <= lecturas->obtener_cantidad()) {
            cout << "\nLecturas publicadas entre los años " << anio_i << " y " << anio_f << ": " << endl;

            while (posicion <= lecturas->obtener_cantidad() &&
                   lecturas->obtener_dato_en(posicion)->obtener_anio() <= anio_f) {
                lecturas->obtener_dato_en(posicion)->mostrar();
                posicion++;
            }

        }else{
            cout << "\nNo se encontraron lecturas entre esos años." << endl;
        }

    }else{
        cout << "\nEl año inicial es mayor al año final." <<endl;
    }

}

void Listar::ejecutar_opcion() {
    switch(tipo){
        case 1:
            listar_escritores();
            break;
        case 2:
            lectura_al_azar();
            break;
        case 3:
            listar_lecturas();
            break;
        case 4:
            lecturas_entre_anios();
            break;
        case 5:
            lecturas_del_escritor();
            break;
        case 6:
            novela_de_genero();
            break;
    }
}
