#ifndef TP3_GRAFO_H
#define TP3_GRAFO_H

#include <string>
#include "lista.h"
#include "lectura.h"
#include "vertice.h"

using namespace std;

const int INFINITO = 99999999;

const int CUENTO_NOVELA = 10;
const int CUENTO_HISTORICA = 15;
const int CUENTO_POEMA = 0;
const int POEMA_NOVELA = 5;
const int POEMA_HISTORICA = 20;
const int NOVELA_HISTORICA = 60;
const int POEMA_POEMA = 1;
const int CUENTO_CUENTO = 8;
const int NOVELA_NOVELA = 30;
const int HISTORICA_HISTORICA = 80;




class Grafo {
/*ATRIBUTOS*/
private:
    int ** matriz_de_adyacencia;
    Lista<Vertice>* vertices;

/*MÉTODOS*/

    // Pre: -
    // Post: Agranda dinamicamente la matriz de adyacencia
    void agrandar_matriz_de_adyacencia();

    // Pre: La matriz que se le envie ya debe tener memoria reservada
    // Post: Copia la matriz de adyacencia en la nueva matriz
    void copiar_matriz_adyacente(int** nueva_adyacente);

    // Pre: La matriz que se le envie ya debe tener memoria reservada
    // Post Inicializa un nuevo vertice en la matriz de adyacencia con un valor de infinito
    void inicializar_nuevo_vertice(int** nueva_adyacente);

    // Pre: -
    // Post: Libera la memoria de la matriz de adyacencia
    void liberar_matriz_adyacencia();

public:
    
    // Pre: -
    // Post: Constructor de la clase Grafo
    Grafo();
    
    // Pre: -
    // Post: Imprime por pantalla los vertices del grafo
    void mostrar_vertices();

    // Pre: -
    // Post: Imprime por pantalla la matriz de adyacencia
    void mostrar_matriz_adyacencia();

    // Pre: No hay vertices repetidos en nombre
    // Post: Agrega un nuevo vertice al grafo y las aristas correspondientes.
    void agregar_vertice(Lectura* vertice_nuevo);

    // Pre: No hay vertices repetidos en nombre
    // Post: Agrega un nuevo vertice al grafo.
    void agregar_vertice(Lectura* vertice_nuevo,int a);

    //Pre: Los vertices existen.
    //Post: Agrega una nueva arista al grafo.
    void agregar_arista(int vertice_a, int vertice_b, int peso);

    //Pre:
    //Post: Ajusta la matriz de adyacencia con los pesos correspondientes al vertice agregado
    void agregar_caminos(int nuevo);

    //Pre: -
    //Post: Devuelve la lista de vertices.
    Lista<Vertice>* obtener_vertices();

    //Pre: -
    //Post: Devuelve la matriz de adyacencia.
    int** obtener_matriz();

    // Pre: Los tipos de lectura existen
    // Post: Asigna el peso segun la arista que une los tipos de lectura
    int asignar_peso(string tipo_uno, string tipo_dos);

    // Pre: -
    // Post: Imprime por pantalla el grafo
    void mostrar_grafo();


    ~Grafo();
};


#endif //TP3_GRAFO_H
