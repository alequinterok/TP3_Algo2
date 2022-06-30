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

public:
    //Pre: -
    //Post: Constructor de la clase Kruskal
    Kruskal(int**, Lista<Vertice>*);

    // Pre: -
    // Post: Carga las aristas de menor a mayor
    void cargar_aristas();

    // Pre: -
    // Post: Inicializa la lista de arboles con cada vertice como un arbol diferente.
    void cargar_arboles();

    // Pre: -
    // Post: 
    void juntar_arboles(int, int, int);

    // Pre: -
    // Post: 
    Posicion buscar_vertice(int vertice);

    // Pre: -
    // Post: Busca el arbol minimo
    void buscar_arbol_minimo();

    // Pre: -
    // Post: 
    Grafo* obtener_arbol_minimo();

    // Pre: -
    // Post: Destructor de la clase arbol
    ~Kruskal();
};

#endif // KRUSKAL_H_INCLUDED