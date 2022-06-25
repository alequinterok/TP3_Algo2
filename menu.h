#ifndef TP2__MENU_H
#define TP2__MENU_H

#include <iostream>

using namespace std;

#include<cstdlib>
#include<ctime>
#include "novela.h"
#include "historica.h"
#include "poema.h"
#include "cuento.h"
#include "lista.h"
#include "carga_escritores.h"
#include "carga_lecturas.h"
#include "cola.h"
#include "opcion.h"
#include "agrega_lectura.h"
#include "agrega_escritor.h"
#include "crear_cola.h"
#include "listar.h"
#include "cambia_dato.h"
#include "quita_lectura.h"

const int PRIMER_OPCION = 1;
const int ULTIMA_OPCION = 13;





class Menu {
//atributos
private:
    Lista<Lectura> *lecturas;
    Lista<Escritor> *escritores;
    Cola* cola;
    Opcion* opcion;
    Lista<Opcion>* opciones;

//metodos
public:
    // Pre: -
    // Post: Constructor de la clase menu
    Menu(string archivo_lecturas, string archivo_esctritores);

    // Pre: -
    // Post: Ejecuta el menu por pantalla interactiva
    void ejecutar_menu();

    // Pre: -
    // Post: Destructor de la clase menu
    ~Menu();

private:

    // Pre: -
    // Post: Imprime por pantalla un mensaje para volver al menu
    void mensaje_para_volver_al_menu();

    // Pre:
    // Post: Devuelve la opcion que elige el usuario.
    int obtener_opcion();

};


#endif //TP2__MENU_H
