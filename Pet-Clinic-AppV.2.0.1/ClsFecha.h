#pragma once
#include <ctime>
#include <iostream>



///falta crear metodos independientes para fecha & hora por separado
class Fecha {
private:


public:
    Fecha(int dia = 0, int mes = 0, int anio = 0, int hora = 0, int minuto = 0, int segundo = 0) {
        _dia = dia;
        _mes = mes;
        _anio = anio;
        _hora = hora;
        _minuto = minuto;
        _segundo = segundo;
    }


    std::string mostrar();
    void cargar();

    bool esFechaAnteriorOIgualActual();
    bool esFechaValida(int dia,int mes, int anio, int hora, int minuto, int segundo);
    bool esFechaPosteriorActual();

};
