#include "agrega_lectura.h"

Agrega_lectura::Agrega_lectura(Lista<Lectura> *lecturas, Diccionario *escritores): Agrega_escritor(lecturas,escritores) {
    nueva = NULL;
    minutos = 0;
    publicacion = 0;
}

bool Agrega_lectura::tipo_valido() {
    return (tipo == CUENTO ||
            tipo == POEMA ||
            tipo == NOVELA);
}

bool Agrega_lectura::genero_valido(string genero) {
    return (genero == "DRAMA" ||
            genero == "COMEDIA" ||
            genero == "FICCION" ||
            genero == "SUSPENSO" ||
            genero == "TERROR" ||
            genero == "ROMANTICA" ||
            genero == "HISTORICA");
}

Novela::Genero Agrega_lectura::asignar_genero() {
    string genero_str;
    cout << "Genero de la novela ";
    cout << "(puede ser DRAMA, COMEDIA, FICCION, SUSPENSO, TERROR, ROMANTICA, HISTORICA): ";
    cin >> genero_str;

    while (!genero_valido(genero_str)){
        cout << "Ese genero no existe. Intentelo de nuevo."<<endl;
        cin >> genero_str;
    }

    Novela::Genero genero;

    if(genero_str == "DRAMA")
        genero = Novela::DRAMA;
    else if(genero_str == "COMEDIA")
        genero = Novela::COMEDIA;
    else if(genero_str == "FICCION")
        genero = Novela::FICCION;
    else if(genero_str == "SUSPENSO")
        genero = Novela::SUSPENSO;
    else if(genero_str == "TERROR")
        genero = Novela::TERROR;
    else if(genero_str == "ROMANTICA")
        genero = Novela::ROMANTICA;
    else if (genero_str == "HISTORICA")
        genero = Novela::HISTORICA;


    return genero;
}

void Agrega_lectura::ingreso_tipo() {
    cout << "Tipo de lectura ";
    cout << "(ingrese C para cuento, P para poema o N para novela): ";
    cin >> tipo;
    while (!tipo_valido()){
        cout << "-- tipo no valido ";
        cout << "(ingrese C para cuento, P para poema o N para novela)" << endl;
        cout << "Tipo de lectura: ";
        cin >> tipo;
    }
}

void Agrega_lectura::ingreso_titulo() {
    cin.ignore();
    cout << "Titulo: ";
    getline(cin, titulo);
}

void Agrega_lectura::tipo_poema() {
    int versos = input_numero("Cantidad de versos");
    nueva = new Poema(titulo, minutos, publicacion, nuevo, versos);
}

void Agrega_lectura::tipo_cuento() {
    cin.ignore();
    string titulo_libro;
    cout << "Libro en que esta publicado: ";
    getline(cin, titulo_libro);

    nueva = new Cuento(titulo, minutos, publicacion, nuevo, titulo_libro);
}

void Agrega_lectura::tipo_novela() {
    Novela::Genero genero = asignar_genero();

    if (genero == Novela::HISTORICA){
        cin.ignore();
        string tema_aux;

        cout << "Breve indicacion sobre el tema historico que aborda: ";
        getline(cin, tema_aux);

        char* tema = new char [(int)tema_aux.length() + 1];
        for (int i = 0; i < (int)tema_aux.length() + 1; i++){
            tema[i] = tema_aux[i];
        }
        nueva = new Historica(titulo, minutos, publicacion, nuevo, tema);
    }else{
        nueva = new Novela(titulo, minutos, publicacion, nuevo, genero);
    }

}

bool Agrega_lectura::escritor_anonimo() {
    char confirmacion;
    cout << "El escritor es anóniomo? (ingrese s para si o n para no) ";
    cin >> confirmacion;
    while (confirmacion!= SI && confirmacion!= NO){
        cout << "(ingrese s para si o n para no)" << endl;
        cin >> confirmacion;
    }
    return (confirmacion == SI);
}

void Agrega_lectura::ejecutar_opcion() {

    introduccion("NUEVA LECTURA");
    if (!escritor_anonimo())
        nuevo_escritor();
    ingreso_tipo();
    ingreso_titulo();
    minutos = input_numero("Minutos estimados que demanda la lectura");
    publicacion = input_numero("Anio de publicacion");

    if (tipo == CUENTO)
        tipo_cuento();
    else if (tipo == POEMA)
        tipo_poema();
    else if (tipo == NOVELA)
        tipo_novela();

    int posicion = lecturas->obtener_cantidad();
    while (nueva->comparar(*(lecturas->obtener_dato_en(posicion))) == MENOR
           && posicion > 0){
        posicion--;
    }
    lecturas->alta(nueva, posicion + 1);

    cout << "\n" << "-- Nueva lectura agregada --" << endl;
}
