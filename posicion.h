#ifndef POSICION_H_INCLUDED
#define POSICION_H_INCLUDED

class Posicion{
private:

    int fila;

    int columna;

public:

    /*
    *pre:
    *pos: constructor posicion, inicializa la fila y la columna como (1,1)
    */
    Posicion();

    /*
    *pre:
    *pos: constructor posicion
    */
    Posicion(int fila, int columna);

    /*
    *pre:
    *pos: cambia la fila por una nueva
    */
    void cambiar_fila (int fil);

    /*
    *pre:
    *pos: cambia la columna por una nueva
    */
    void cambiar_columna (int col);

    /*
    *pre:
    *pos: devuelve la fila de la posicion
    */
    int obtener_fila();

    /*
    *pre:
    *pos: devuelve la columna de la posicion
    */
    int obtener_columna();
};


#endif // POSICION_H_INCLUDED
