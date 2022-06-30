#ifndef KRUSKAL_H_INCLUDED
#define KRUSKAL_H_INCLUDED

#include "nodo.h"
#include "lista.h"
#include "vertice.h"
#include "grafo.h"
#include "arista.h"
#include "posicion.h"

class Kruskal {

private:
    Grafo* arbol_minimo;
    int ** matriz_de_adyacencia;
    Lista<Vertice>* vertices;
    Lista<Grafo>* arboles;
    Lista<Arista>*  aristas;
    int primero;

public:
    // Pre: La lista y la matriz existen y deben estar cargadas con la informacion del grafo
    // Post: Constructor de la clase Kruskal
    Kruskal(int**, Lista<Vertice>*);

    // Pre: -
    // Post: Carga las aristas de menor a mayor
    void cargar_aristas();

    // Pre: -
    // Post: Inicializa la lista de arboles con cada vertice como un arbol diferente.
    void cargar_arboles();

    // Pre: Los vertices deben pertenecer a algun arbol
    // Post: Une los 2 vertices si pertenecen a arboles distintos
    void juntar_arboles(int vertice_a, int vertice_b, int peso);

    // Pre: El vertice debe pertenecer a algun arbol
    // Post: Busca el arbol donde se encuentra el vertice y devuelve la posicion del vertice y del arbol
    Posicion buscar_vertice(int vertice);

    // Pre: -
    // Post: Busca el arbol minimo
    void buscar_arbol_minimo();

    // Pre: -
    // Post: Devuelve el arbol minimo
    Grafo* obtener_arbol_minimo();

    // Pre: -
    // Post: Calcula los minutos totales que se tarda en leer todas las lecturas y los devuelve
    int calcular_peso();

    // Pre: -
    // Post: Devuelve true si es una lista
    bool es_lista();

    // Pre: -
    // Post: Muestra la lista si es y si no devuelve que no es una lista y muestra el arbol
    void mostrar();

    // Pre: -
    // Post: Destructor de la clase arbol
    ~Kruskal();
};

#endif // KRUSKAL_H_INCLUDED