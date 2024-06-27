#pragma once
#include <iostream>
#include <string>
#include "rlutil.h"

class Interfaz {
public:
    void establecerColorTexto(int color);
    void establecerColorFondo(int color);
    void moverCursor(int x, int y);
    void fijarTamanoConsola();
    void mostrarTitulo();
    void tituloConsola();
    char capturarTecla();
    void obtenerDibujoEspecie(int especie);
    void interfazCliente();

};
