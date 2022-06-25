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
    //CaminoMinimo * algoritmoCaminoMinimo;

/*MÉTODOS*/


    //post: agranda dinamicamente la matriz de adyacencia
    void agrandar_matriz_de_adyacencia();

    //pre: la matriz que se le envie ya debe tener memoria reservada
    //post: copia la matriz de adyacencia en la nueva matriz
    void copiar_matriz_adyacente(int** nueva_adyacente);

    //post inicializa un nuevo vertice en la matriz de adyacencia con un valor de infinito
    void inicializar_nuevo_vertice(int** nueva_adyacente);

    //post libera la memoria de la matriz de adyacencia
    void liberar_matriz_adyacencia();

    //post: imprime por pantalla los vertices del grafo
    void mostrar_vertices();

    //post: imprime por pantalla la matriz de adyacencia
    void mostrar_matriz_adyacencia();
public:

    Grafo();
    //pre: No hay vertices repetidos en nombre
    //post: agrega un nuevo vertice al grafo
    void agregar_vertice(Lectura* vertice_nuevo);

    //pre:
    //post: Ajusta la matriz de adyacencia con los pesos correspondientes al vertice agregado
    void agregar_caminos(int nuevo);

    int asignar_peso(string tipo_uno, string tipo_dos);

    //post: imprime por pantalla el grafo
    void mostrar_grafo();


    ~Grafo();
};


#endif //TP3_GRAFO_H
