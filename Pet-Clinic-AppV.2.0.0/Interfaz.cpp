#include "Interfaz.h"

// Metodo para limpiar la pantalla
void Interfaz::limpiarPantalla() {
    rlutil::cls();
}

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

// Metodo para dibujar el cuadro sin valores ni carteles
void Interfaz::dibujarCuadro() {
    limpiarPantalla();

    char esquinaSuperiorIzquierda = 201; // Código ASCII para "╔"
    char esquinaSuperiorDerecha = 187; // Código ASCII para "╗"
    char lineaHorizontal = 205; // Código ASCII para "═"
    char lineaVertical = 186; // Código ASCII para "║"
    char esquinaInferiorIzquierda = 200; // Código ASCII para "╚"
    char esquinaInferiorDerecha = 188; // Código ASCII para "╝"
    char interseccionIzquierda = 204; // Código ASCII para "╠"
    char interseccionDerecha = 185; // Código ASCII para "╣"
    char interseccionArriba = 202; // Código ASCII para "╩"
    char interseccionAbajo = 203; // Código ASCII para "╦"

    // Dibuja el marco superior e inferior
    crearRecuadro(1, 1, 119, 29,
                  esquinaSuperiorIzquierda, esquinaSuperiorDerecha,
                  esquinaInferiorIzquierda, esquinaInferiorDerecha,
                  lineaHorizontal, lineaVertical,
                  interseccionIzquierda, interseccionDerecha,
                  interseccionArriba, interseccionAbajo);

    // Dibuja las líneas horizontales internas
    for (int x = 2; x < 119; ++x) {
        moverCursor(x, 6);
        std::cout << lineaHorizontal;
        moverCursor(x, 20);
        std::cout << lineaHorizontal;
    }

    // Dibuja las intersecciones
    moverCursor(1, 6);
    std::cout << interseccionIzquierda;
    moverCursor(119, 6);
    std::cout << interseccionDerecha;
    moverCursor(1, 20);
    std::cout << interseccionIzquierda;
    moverCursor(119, 20);
    std::cout << interseccionDerecha;

    // Dibuja las líneas verticales internas
    for (int y = 2; y < 6; ++y) {
        moverCursor(40, y);
        std::cout << lineaVertical;
        moverCursor(80, y);
        std::cout << lineaVertical;
    }

    // Primera Intersección vertical
    moverCursor(40, 1);
    std::cout << interseccionAbajo;
    moverCursor(40, 6);
    std::cout << interseccionArriba;

    // Segunda Intersección vertical
    moverCursor(80, 1);
    std::cout << interseccionAbajo;
    moverCursor(80, 6);
    std::cout << interseccionArriba;

    establecerColorTexto(rlutil::WHITE);
}
