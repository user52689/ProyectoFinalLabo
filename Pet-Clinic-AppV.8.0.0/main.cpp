#include <iostream>
#include "Interfaz.h"
#include "AppManager.h"
///V.8.0.0
using namespace std;

int main() {
    Interfaz interfaz;
    AppManager app;

    interfaz.tituloConsola();
    interfaz.fijarTamanoConsola();



    app.menuPrincipal();

    return 0;
}
