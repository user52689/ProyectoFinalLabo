#pragma once
#include <iostream>
#include <string>
#include "rlutil.h"

class Interfaz {
public:
    /// Metodo para limpiar la pantalla
    void limpiarPantalla();

    /// Metodo para establecer el color del texto
    void establecerColorTexto(int color);

    /// Metodo para establecer el color de fondo
    void establecerColorFondo(int color);

    /// Metodo para mover el cursor a una posicion especifica
    void moverCursor(int x, int y);

    /// Metodo para mostrar texto en una posicion específica
    void mostrarTexto(int x, int y, const std::string& texto);

    /// Metodo para capturar una tecla
    char capturarTecla();

    /// Metodo para esperar a que el usuario presione una tecla
    void esperarTecla(const std::string& mensaje);

    /// Metodo para crear un recuadro
    void crearRecuadro(int x1, int y1, int x2, int y2,
                       char esquinaSI, char esquinaSD, char esquinaII, char esquinaID,
                       char lineaH, char lineaV, char interseccionI, char interseccionD,
                       char interseccionA, char interseccionB);

    /// Metodo para dibujar el cuadro sin valores ni carteles
    void dibujarCuadro();

    /// Metodo para establecer de el tamaño de la consola
    void fijarTamanoConsola();
};
