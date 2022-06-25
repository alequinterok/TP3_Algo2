#include "carga_escritores.h"

Carga_escritores::Carga_escritores(string nombre_archivo) {
    diccionario_escritores = new Diccionario;
    cargar_diccionario(nombre_archivo);
}

void Carga_escritores::crear_escritor() {
    string datos[5] = {"", "" , "¿?", "-1", "-1"};

    int indice = 0;
    string dato;
    do{
        dato = archivo.leer_linea();
        if (dato != "" && indice < 5) {
            datos[indice] = dato;
        }
        indice++;
    }while(dato != "" && indice < 6 && !archivo.fin_de_archivo());

    escritor = new Escritor((string)datos[1],(string)datos[2],stoi(datos[3]),stoi(datos[4]), identificar_isni(datos[0]));
}

int Carga_escritores::identificar_isni(string isni_bruto){
    string isni_str = "";

    for (int i = 1; i <= CANT_DIGITOS_ISNI; i++){
        isni_str[i-1] = isni_bruto[i];
    }

    return stoi(isni_str);
}

void Carga_escritores::cargar_diccionario(string nombre_archivo) {
    archivo.abrir_archivo(nombre_archivo);
    do{
        crear_escritor();
        diccionario_escritores->agregar_escritor(escritor);
    }while(!archivo.fin_de_archivo());
    archivo.cerrar_archivo();
}


Diccionario* Carga_escritores::obtener_diccionario() {
    return diccionario_escritores;
}
