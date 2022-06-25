#include "crear_cola.h"

Crear_cola::Crear_cola(Lista<Lectura> *lecturas, Diccionario *escritores, Cola* cola,int tipo): Opcion(lecturas,escritores) {
    this -> cola = cola;
    this -> tipo = tipo;
}

void Crear_cola::crear_cola() {


    while(!cola->cola_vacia()){
        cola->quitar();
    }


    int* orden = new int[lecturas->obtener_cantidad()-1];

    orden[0] = 1;

    for(int i = 2;i<lecturas->obtener_cantidad();i++){
        Lectura* lectura = lecturas->obtener_dato_en(i);
        orden[i-1] = i;
        int posicion = i - 1;
        int anterior = orden[posicion-1];

        while (lectura->comparar(*(lecturas->obtener_dato_en(anterior)),0) == MENOR && posicion > 0){
            orden[posicion-1] = i;
            orden[posicion] = anterior;
            posicion--;
            if (posicion>0)
                anterior = orden[posicion-1];
        }
    }


    for(int i = 0;i<(lecturas->obtener_cantidad()-1);i++){
        if(!(lecturas->obtener_dato_en(orden[i])->obtener_leida())) {
            cola->insertar_cola(new Lectura *(lecturas->obtener_dato_en(orden[i])));
        }
    }
    delete [] orden;
    cout<<"\nCola: "<<endl;
    cola->mostrar();

}

void Crear_cola::ejecutar_opcion() {
    if (tipo == 1) {
        introduccion("NUEVA COLA DE LECTURAS");
        crear_cola();
    }else{
        introduccion("LECTURA PARA LEER");
        leer_una_lectura();
    }
}

void Crear_cola::leer_una_lectura() {
    if(cola->cola_vacia()){
        cout << "\nNo hay lecturas en la cola."<<endl;
    }
    else{
        cout<<"\nSe leerá la siguiente lectura: "<<endl;
        Lectura** primero = cola->obtener_primero();
        (*primero)->mostrar();
        (*primero)->leer();
        cola->quitar();
    }
}
