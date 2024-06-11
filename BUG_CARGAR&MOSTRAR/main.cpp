#include <iostream>
#include "Interfaz.h"
#include "AppManager.h"


using namespace std;

int main() {
    Interfaz interfaz;
    AppManager app;

    /// Fijar el tamaño de la consola
    interfaz.fijarTamanoConsola();

    app.menu();




return 0;
}
