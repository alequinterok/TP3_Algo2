#include "diccionario.h"


Diccionario::Diccionario (){

    escritores = new Lista<Escritor>* [TAMANIO_TABLA];

    for (int i = 0; i < TAMANIO_TABLA; i++){

        escritores[i] = NULL;

    }

}

void Diccionario::mostrar(){
    cout << "ISNI |  escritor \n" << endl;

    for (int i = 0; i < TAMANIO_TABLA; i++){

    if(escritores[i] != NULL){

        for (int j = 1; j <= escritores[i]->obtener_cantidad(); j++){

            Escritor* escritor = escritores[i]->obtener_dato_en(j);

            cout << escritor->obtener_isni() << " | " << escritor->obtener_nombre_apellido() << endl;

        }

    }

    }

    cout << endl;
}

void Diccionario::listar_escritores(){

    for (int i = 0; i < TAMANIO_TABLA; i++){

    if(escritores[i] != NULL){

        for (int j = 1; j <= escritores[i]->obtener_cantidad(); j++){

            escritores[i]->obtener_dato_en(j)->mostrar();
            cout << endl;

        }

    }

    }

}

int Diccionario::obtener_fila(int clave){

    return (clave % TAMANIO_TABLA);
}

Posicion Diccionario::obtener_posicion(int clave){

    Posicion posicion;

    posicion.cambiar_fila(obtener_fila(clave));

    if (escritores[posicion.obtener_fila()] != NULL &&
        !escritores[posicion.obtener_fila()]->vacia()){

        posicion.cambiar_columna( colision (clave, PRIMERA_POSICION) );

    }

    return posicion;
}

int Diccionario::colision(int clave, int i){

    if ( obtener_isni_en (Posicion ( obtener_fila(clave), i )) >= clave){

            return (i);

    }

    if (i == escritores[obtener_fila(clave)]->obtener_cantidad() &&
        obtener_isni_en (Posicion ( obtener_fila(clave), i )) < clave){

            return (i+1);

        }

    return colision(clave, i+1);
}

void Diccionario::agregar_escritor(Escritor* escritor_nuevo){

    Posicion pos = obtener_posicion(escritor_nuevo->obtener_isni());

    if (escritores[pos.obtener_fila()] == NULL){

        escritores[pos.obtener_fila()] = new Lista<Escritor>;

    }

    escritores[pos.obtener_fila()]->alta(escritor_nuevo, pos.obtener_columna());

}

Escritor* Diccionario::obtener_elemento(int clave){

    Posicion pos = obtener_posicion(clave);

    Escritor* escritor = NULL;

    if (escritores[pos.obtener_fila()] != NULL &&
        escritores[pos.obtener_fila()]->obtener_cantidad() >= pos.obtener_columna() &&
        obtener_isni_en (pos) == clave){

        escritor = escritores[pos.obtener_fila()]->obtener_dato_en(pos.obtener_columna());

    }


    return escritor;
}

void Diccionario::eliminar_elemento(int clave){

    Posicion pos = obtener_posicion(clave);


    if (obtener_isni_en (pos) == clave){

        escritores[pos.obtener_fila()]->baja(pos.obtener_columna());

        if (escritores[pos.obtener_fila()]->vacia()){

            delete escritores[pos.obtener_fila()];
            escritores[pos.obtener_fila()] = NULL;

        }

    }

}

int Diccionario::obtener_isni_en(Posicion pos){

    return (escritores[pos.obtener_fila()]->obtener_dato_en(pos.obtener_columna())->obtener_isni());

}

Diccionario::~Diccionario(){

    for (int i = 0; i < TAMANIO_TABLA; i++){

        if (escritores[i] != NULL){

            delete escritores[i];

        }

    }

    delete [] escritores;
}
