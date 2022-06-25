#ifndef ESCRITORES_H_INCLUDED
#define ESCRITORES_H_INCLUDED

#include <string>

using namespace std;

const int SIGUE_VIVO = -1;
const int ANIO_DESCONOCIDO = -1;

class Escritor{

private:

    string nombre_apellido;

    string nacionalidad;

    int anio_nacimiento;

    int anio_fallecimiento;

public:

    // Pre: -
    // Post: Constructor de la clase escritor
    Escritor(string nombre_apellido, string nacionalidad, int anio_nacimiento, int anio_fallecimiento);

    // Pre: El parametro no debe estar vacio
    // Post: Modifica el año de fallecimiento de un escritor
    void modificar_anio_fallecimiento(int anio_fallecimiento);

    // Pre: -
    // Post: Devuelve el nombre y apellido del escritor
    string obtener_nombre_apellido();

    // Pre: -
    // Post: Devuelve la nacionalidad del escritor
    string obtener_nacionalidad();

    // Pre: -
    // Post: Devuelve el año de nacimiento del escritor
    int obtener_anio_nacimiento();

    // Pre: -
    // Post: Devuelve el año de fallecimiento del escritor
    int obtener_anio_fallecimiento();

    // Pre: -
    // Post: Imprime por pantalla la informacion del escritor
    void mostrar();

    // Pre: -
    // Post: Destructor de escritor
    ~Escritor();
};

#endif // ESCRITORES_H_INCLUDED
