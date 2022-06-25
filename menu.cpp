#include "menu.h"

Menu::Menu(string archivo_lecturas, string archivo_escritores) {
    escritores = Carga_escritores(archivo_escritores).obtener_lista();
    lecturas = Carga_lecturas(archivo_lecturas, escritores).obtener_lista();
    cola = new Cola;
    opciones = new Lista<Opcion>;
    opciones ->alta(new Agrega_lectura(lecturas,escritores),1);
    opciones ->alta(new Quita_lectura(lecturas,escritores),2);
    opciones ->alta(new Agrega_escritor(lecturas,escritores),3);
    opciones ->alta(new Cambia_dato(lecturas,escritores),4);
    opciones ->alta(new Listar(lecturas,escritores,1),5);
    opciones ->alta(new Listar(lecturas,escritores,2),6);
    opciones ->alta(new Listar(lecturas,escritores,3),7);
    opciones ->alta(new Listar(lecturas,escritores,4),8);
    opciones ->alta(new Listar(lecturas,escritores,5),9);
    opciones ->alta(new Listar(lecturas,escritores,6),10);
    opciones ->alta(new Crear_cola(lecturas,escritores,cola,1),11);
    opciones ->alta(new Crear_cola(lecturas,escritores,cola,2),12);
}

void Menu::mensaje_para_volver_al_menu(){
    string basura;
    cout << "\n Ingrese cualquier tecla para volver al menu: ";
    cin >> basura;
}

int Menu::obtener_opcion(){
    int numero = Opcion::input_numero("Ingrese la opcion que desee ");
    while (!(numero >= PRIMER_OPCION && numero <= ULTIMA_OPCION)){
        cout << "Esa opcion no existe. Intentelo de nuevo.\n";
        numero = Opcion::input_numero("Ingrese la opcion que desee ");
    }
    return numero;
}

void Menu::ejecutar_menu(){
    system("clear");
    cout << "-- MENU -- \n" <<endl;

    Opcion::imprimir_opciones();

    int numero = obtener_opcion();

    system("clear");

    if (numero == 13)
        cout << "\nHasta luego!" <<endl;
    else {
        opciones->obtener_dato_en(numero)->ejecutar_opcion();
        mensaje_para_volver_al_menu();
        ejecutar_menu();
    }
}

Menu::~Menu() {
    delete opciones;
    delete cola;
    delete lecturas;
    delete escritores;
}
