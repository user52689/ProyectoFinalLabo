#pragma once
#include <iostream>
#include <ctime>

class Fecha {
private:
    int _dia;
    int _mes;
    int _anio;

public:
    Fecha(int dia, int mes, int anio);
    Fecha();

    void mostrar();
    bool esValida(int dia, int mes, int anio);
    bool esBisiesto(int anio);

    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);

    int getDia();
    int getMes();
    int getAnio();
};
