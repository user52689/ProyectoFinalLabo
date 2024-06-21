#include "Interfaz.h"
#include "rlutil.h"

// Metodo para establecer el color del texto
void Interfaz::establecerColorTexto(int color) {
    rlutil::setColor(color);
}

// Metodo para establecer el color de fondo
void Interfaz::establecerColorFondo(int color) {
    rlutil::setBackgroundColor(color);
}

// Metodo para mover el cursor a una posicion especifica
void Interfaz::moverCursor(int x, int y) {
    rlutil::locate(x, y);
}

// Metodo para mostrar texto en una posicion especifica
void Interfaz::mostrarTexto(int x, int y, const std::string& texto) {
    moverCursor(x, y);
    std::cout << texto;
}

// Metodo para capturar una tecla
char Interfaz::capturarTecla() {
    return rlutil::getkey();
}

// Metodo para esperar a que el usuario presione una tecla
void Interfaz::esperarTecla(const std::string& mensaje) {
    rlutil::anykey(mensaje.c_str());
}

void Interfaz::fijarTamanoConsola() {
    system("mode con cols=100 lines=35");
}

// Metodo para crear un recuadro
void Interfaz::crearRecuadro(int x1, int y1, int x2, int y2,
                             char esquinaSI, char esquinaSD, char esquinaII, char esquinaID,
                             char lineaH, char lineaV, char interseccionI, char interseccionD,
                             char interseccionA, char interseccionB) {
    // Dibujar las lineas horizontales
    for (int x = x1 + 1; x < x2; ++x) {
        moverCursor(x, y1);
        std::cout << lineaH;
        moverCursor(x, y2);
        std::cout << lineaH;
    }

    // Dibujar las lineas verticales
    for (int y = y1 + 1; y < y2; ++y) {
        moverCursor(x1, y);
        std::cout << lineaV;
        moverCursor(x2, y);
        std::cout << lineaV;
    }

    // Dibujar las esquinas
    moverCursor(x1, y1);
    std::cout << esquinaSI;
    moverCursor(x2, y1);
    std::cout << esquinaSD;
    moverCursor(x1, y2);
    std::cout << esquinaII;
    moverCursor(x2, y2);
    std::cout << esquinaID;
}

void Interfaz::dibujarLineaHorizontal(int x, int y, int longitud) {
    char lineaHorizontal = 205; // Código ASCII para "═"
    moverCursor(x, y);
    for (int i = 0; i < longitud; ++i) {
        std::cout << lineaHorizontal;
    }
}

void Interfaz::mostrarTitulo() {
    rlutil::locate(20, 7);
    std::cout << "  _____     _           _____ _ _       _                                " << std::endl;
    rlutil::locate(20, 8);
    std::cout << " |  __ \\   | |         / ____| (_)     (_)             /\\                " << std::endl;
    rlutil::locate(20, 9);
    std::cout << " | |__) |__| |_ ______| |    | |_ _ __  _  ___ ______ /  \\   _ __  _ __  " << std::endl;
    rlutil::locate(20, 10);
    std::cout << " |  ___/ _ \\ __|______| |    | | | '_ \\| |/ __|______/ /\\ \\ | '_ \\| '_ \\ " << std::endl;
    rlutil::locate(20, 11);
    std::cout << " | |  |  __/ |_       | |____| | | | | | | (__      / ____ \\| |_) | |_) |" << std::endl;
    rlutil::locate(20, 12);
    std::cout << " |_|   \\___|\\__|       \\_____|_|_|_| |_|_|\\___|    /_/    \\_\\ .__/| .__/ " << std::endl;
    rlutil::locate(20, 13);
    std::cout << "                                                            | |   | |    " << std::endl;
    rlutil::locate(20, 14);
    std::cout << "                                                  V5.0.0    |_|   |_|    " << std::endl;
}

void Interfaz::tituloConsola(){
    rlutil::setConsoleTitle("Pet-Clinic-App");
}
