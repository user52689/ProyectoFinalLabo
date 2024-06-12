#include <iostream>
#include "Interfaz.h"
#include "AppManager.h"

///V.3.0.0 12/05/24
using namespace std;

int main() {
    Interfaz interfaz;
    AppManager app;

    interfaz.tituloConsola();///Establecer nombre a la consola
    interfaz.fijarTamanoConsola();/// Fijar el tamaño de la consola


    app.menu();




return 0;
}
