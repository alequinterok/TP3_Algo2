#include <iostream>

#include "menu.h"

const string PATH_LECTURAS = "/home/anita/Desktop/TP3_Algo2(1)/TP3_Algo2/archivos/lecturas.txt";
const string PATH_ESCRITORES = "/home/anita/Desktop/TP3_Algo2(1)/TP3_Algo2/archivos/escritores.txt";

int main() {
    Menu menu = Menu(PATH_LECTURAS,PATH_ESCRITORES);
    menu.ejecutar_menu();
    return 0;
}
