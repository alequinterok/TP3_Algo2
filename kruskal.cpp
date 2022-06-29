#include "kruskal.h"

Kruskal::Kruskal(int ** matriz_de_adyacencia, Lista<Vertice>* vertices) {
    this -> matriz_de_adyacencia = matriz_de_adyacencia;
    this -> vertices = vertices;
    arbol_minimo = new Grafo;
    arboles = new Lista<Grafo>;
    aristas = new Lista<Arista>;
}


void Kruskal::cargar_aristas() {
    
    int posicion = 2;
    for(int i = 0; i < vertices -> obtener_cantidad(); i++) {
        for(int j = i; j < vertices -> obtener_cantidad(); j++) {
            Arista* arista = new Arista(matriz_de_adyacencia[i][j],i,j);
            if (aristas->vacia()){
                aristas->alta(arista, 1);
            }
        
            else{
                // compara con la que está en la posición anterior
                int i = posicion - 1;
                // si es menor, compara con el anterior y asì hasta que llegue a uno que sea menor que este o al principio de la lista
                while (arista->comparar(*(aristas->obtener_dato_en(i))) == MENOR && i>0){
                    i--;
                }
                posicion++;
                //la agrega dsps de la lectura que es menor que la que queremos agregar
                aristas->alta(arista, i + 1);
            }
        }    
    }    
}

void Kruskal::cargar_arboles(){
    for (int i = 0; i < vertices -> obtener_cantidad(); i++){
        Grafo* arbol = new Grafo;
        arbol-> agregar_vertice(vertices->obtener_dato_en(i)->obtener_lectura());
    }
}

void Kruskal::juntar_arboles(int vertice_a,int vertice_b) {


    
}

Grafo* Kruskal::obtener_arbol_minimo() {
    return arbol_minimo;
}

Kruskal::~Kruskal() {
    delete aristas;
    delete arboles;
    delete arbol_minimo;
}