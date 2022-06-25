#include <iostream>

#include "menu.h"

const string PATH_LECTURAS = "archivos/lecturas.txt";
const string PATH_ESCRITORES = "archivos/escritores.txt";

int main() {
    Menu menu = Menu(PATH_LECTURAS,PATH_ESCRITORES);
    menu.ejecutar_menu();
    return 0;
}
