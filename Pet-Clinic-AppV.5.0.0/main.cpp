#include <iostream>
#include "Interfaz.h"
#include "AppManager.h"

using namespace std;

int main() {
    Interfaz interfaz;
    AppManager app;

    interfaz.tituloConsola();
    interfaz.fijarTamanoConsola();

    app.menuPrincipal();

    return 0;
}
