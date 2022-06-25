#include "grafo.h"
#include <iostream>




Grafo::Grafo() {
    matriz_de_adyacencia = nullptr;
    vertices = new Lista<Vertice>();
}

void Grafo::agregar_vertice(Lectura* vertice_nuevo) {
    agrandar_matriz_de_adyacencia();
    auto* nuevo_vertice = new Vertice(vertice_nuevo);
    vertices -> alta(nuevo_vertice,vertices->obtener_cantidad()+1);
    agregar_caminos(vertices->obtener_cantidad());
}

void Grafo::mostrar_grafo() {
    mostrar_vertices();
    mostrar_matriz_adyacencia();
}

int Grafo::asignar_peso(string tipo_uno, string tipo_dos) {
    int peso = 0;
    if (tipo_uno[0] == 'P' && tipo_dos[0] == 'P'){
        peso = POEMA_POEMA;
    }
    else if ((tipo_uno[0] == 'P' && tipo_dos[0] == 'C') || (tipo_uno[0] == 'C' && tipo_dos[0] == 'P')){
        peso = CUENTO_POEMA;
    }
    else if ((tipo_uno[0] == 'P' && tipo_dos[0] == 'N') || (tipo_uno[0] == 'N' && tipo_dos[0] == 'P')){
        peso = POEMA_NOVELA;
    }
    else if ((tipo_uno[0] == 'P' && tipo_dos[0] == 'H') || (tipo_uno[0] == 'H' && tipo_dos[0] == 'P')){
        peso = POEMA_HISTORICA;
    }
    else if ((tipo_uno[0] == 'N' && tipo_dos[0] == 'C') || (tipo_uno[0] == 'C' && tipo_dos[0] == 'N')){
        peso = CUENTO_NOVELA;
    }
    else if ((tipo_uno[0] == 'H' && tipo_dos[0] == 'C') || (tipo_uno[0] == 'C' && tipo_dos[0] == 'H')){
        peso = CUENTO_HISTORICA;
    }
    else if ((tipo_uno[0] == 'N' && tipo_dos[0] == 'H') || (tipo_uno[0] == 'H' && tipo_dos[0] == 'N')){
        peso = NOVELA_HISTORICA;
    }
    else if (tipo_uno[0] == 'C' && tipo_dos[0] == 'C'){
        peso = CUENTO_CUENTO;
    }
    else if (tipo_uno[0] == 'H' && tipo_dos[0] == 'H'){
        peso = HISTORICA_HISTORICA;
    }
    else if (tipo_uno[0] == 'N' && tipo_dos[0] == 'N'){
        peso = NOVELA_NOVELA;
    }
    return peso;
}

void Grafo::agregar_caminos(int nuevo) {
    string tipo_nuevo = vertices ->obtener_dato_en(nuevo) -> obtener_lectura() -> obtener_tipo();

    for(int i = 0; i < vertices -> obtener_cantidad(); i++){
        string tipo_otro = vertices ->obtener_dato_en(i+1) -> obtener_lectura() -> obtener_tipo();
        int peso = asignar_peso(tipo_nuevo,tipo_otro);
        matriz_de_adyacencia[nuevo-1][i] = peso;
        matriz_de_adyacencia[i][nuevo-1] = peso;

    }
}

void Grafo::agrandar_matriz_de_adyacencia() {
    int** matriz_auxiliar;
    int nueva_cantidad = vertices->obtener_cantidad() + 1;

    matriz_auxiliar = new int*[nueva_cantidad];
    for(int i = 0; i < nueva_cantidad; i++){
        matriz_auxiliar[i] = new int[nueva_cantidad];
    }

    copiar_matriz_adyacente(matriz_auxiliar);
    inicializar_nuevo_vertice(matriz_auxiliar);
    liberar_matriz_adyacencia();
    matriz_de_adyacencia = matriz_auxiliar;
}

void Grafo::copiar_matriz_adyacente(int** nueva_adyacente) {
    for(int i = 0; i < vertices -> obtener_cantidad(); i++){
        for(int j = 0; j < vertices -> obtener_cantidad(); j++){
            nueva_adyacente[i][j] = matriz_de_adyacencia[i][j];
        }
    }
}

void Grafo::inicializar_nuevo_vertice(int** nueva_adyacente) {
    for(int i = 0; i < vertices -> obtener_cantidad(); i++){
        nueva_adyacente[vertices -> obtener_cantidad()][i] = INFINITO;
        nueva_adyacente[i][vertices -> obtener_cantidad()] = INFINITO;
    }
    nueva_adyacente[vertices -> obtener_cantidad()][vertices -> obtener_cantidad()] = 0;
}

void Grafo::liberar_matriz_adyacencia() {
    for(int i = 0; i < vertices -> obtener_cantidad(); i++){
        delete[] matriz_de_adyacencia[i];
    }
    delete[] matriz_de_adyacencia;
}

Grafo::~Grafo() {
    liberar_matriz_adyacencia();
    matriz_de_adyacencia = nullptr;
    delete vertices;
}

void Grafo::mostrar_vertices() {
    cout << "\nLista de lecturas: ";
    for(int i = 1; i < vertices -> obtener_cantidad()+1; i++){
        cout << vertices -> obtener_dato_en(i) ->obtener_lectura()->obtener_titulo();
        if(i != vertices -> obtener_cantidad()){
            cout << ", ";
        }
    }
    cout << endl;
}

void Grafo::mostrar_matriz_adyacencia() {
    cout << "Matriz de adyacencia:" << endl;
    for(int i = 0; i < vertices -> obtener_cantidad(); i++){
        for(int j = 0; j < vertices -> obtener_cantidad() * 2; j++) {
            if(j == vertices -> obtener_cantidad() * 2 - 1){
                cout << endl;
            } else if(j % 2 == 0){
                if(matriz_de_adyacencia[i][j / 2] == INFINITO){
                    cout << "∞";
                } else {
                    cout << matriz_de_adyacencia[i][j / 2];
                }
            } else{
                cout << "|";
            }
        }
    }
    cout << endl;
}

