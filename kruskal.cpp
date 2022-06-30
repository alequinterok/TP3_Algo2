#include "kruskal.h"

Kruskal::Kruskal(int ** matriz_de_adyacencia, Lista<Vertice>* vertices) {
    this -> matriz_de_adyacencia = matriz_de_adyacencia;
    this -> vertices = vertices;
    arbol_minimo = nullptr;
    arboles = new Lista<Grafo>;
    aristas = new Lista<Arista>;
}


void Kruskal::cargar_aristas() {
    
    int posicion = 2;
    for(int i = 0; i < vertices -> obtener_cantidad(); i++) {
        for(int j = i; j < vertices -> obtener_cantidad(); j++) {
            auto* arista = new Arista(matriz_de_adyacencia[i][j],i+1,j+1);
            if (aristas->vacia()){
                aristas->alta(arista, 1);
            }
        
            else{
                // compara con la que está en la posición anterior
                int k = posicion - 1;
                // si es menor, compara con el anterior y asì hasta que llegue a uno que sea menor que este o al principio de la lista
                while (arista->comparar(*(aristas->obtener_dato_en(k))) == MENOR && k>0){
                    k--;
                }
                posicion++;
                //la agrega dsps de la lectura que es menor que la que queremos agregar
                aristas->alta(arista, k + 1);
            }
        }    
    }    
}

void Kruskal::cargar_arboles(){
    for (int i = 1; i <= vertices -> obtener_cantidad(); i++){
        auto* arbol = new Grafo;
        arbol-> agregar_vertice(vertices->obtener_dato_en(i)->obtener_lectura(),1);
        arboles->alta(arbol,i);
    }

}


Posicion Kruskal::buscar_vertice(int vertice){
    int i = 1;
    while(i <= arboles -> obtener_cantidad()){
        Lista<Vertice>* list = arboles -> obtener_dato_en(i) -> obtener_vertices();
        int j = 1;
        while ((j <= list -> obtener_cantidad()) && (list -> obtener_dato_en(j)-> obtener_lectura()) != vertices -> obtener_dato_en(vertice) ->obtener_lectura()){
            j++;
        }
        if (j <=  list -> obtener_cantidad())
            return {i,j};
        i++;    
    }
    return {0,0};
}



void Kruskal::juntar_arboles(int vertice_a, int vertice_b, int peso) {

    Posicion posicion_a = buscar_vertice(vertice_a);
    Posicion posicion_b = buscar_vertice(vertice_b);
    if( posicion_a.obtener_fila() != posicion_b.obtener_fila() ){
        int cant_vertices_a = arboles -> obtener_dato_en(posicion_a.obtener_fila()) -> obtener_vertices() -> obtener_cantidad();
        for(int i = 1; i <= arboles -> obtener_dato_en(posicion_b.obtener_fila()) -> obtener_vertices() -> obtener_cantidad(); i++){
            arboles -> obtener_dato_en(posicion_a.obtener_fila()) -> agregar_vertice((arboles->obtener_dato_en(posicion_b.obtener_fila() )) -> obtener_vertices() -> obtener_dato_en(i) -> obtener_lectura(),1);
        }
        for(int i = 1; i <= arboles->obtener_dato_en((posicion_b.obtener_fila() )) -> obtener_vertices() -> obtener_cantidad(); i++){
            for(int j = i + 1; j <= arboles->obtener_dato_en((posicion_b.obtener_fila() )) -> obtener_vertices() -> obtener_cantidad();j++){
                arboles->obtener_dato_en(posicion_a.obtener_fila())->agregar_arista(i + cant_vertices_a, j + cant_vertices_a, arboles->obtener_dato_en(posicion_b.obtener_fila())-> obtener_matriz()[i-1][j-1]);
            }
        }
        arboles->obtener_dato_en(posicion_a.obtener_fila())->agregar_arista(posicion_a.obtener_columna(),cant_vertices_a + posicion_b.obtener_columna(),peso);
        arboles->baja(posicion_b.obtener_fila());
    }
}


void Kruskal::buscar_arbol_minimo() {
    cargar_aristas();
    cargar_arboles();
    int i = 1;
    while (arboles->obtener_cantidad() > 1){
        Arista arista = *(aristas->obtener_dato_en(i));
        juntar_arboles(arista.obtener_vertice_a(), arista.obtener_vertice_b(), arista.obtener_peso());
        i++;
    }

    arbol_minimo = arboles -> obtener_dato_en(1);
}


Grafo* Kruskal::obtener_arbol_minimo() {
    return arbol_minimo;
}


Kruskal::~Kruskal() {
    delete aristas;
    delete arboles;
}