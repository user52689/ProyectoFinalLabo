#pragma once
#include <ctime>
#include <iostream>

///falta crear metodos independientes para fecha & hora por separado
class Fecha {
private:
    int _dia;
    int _mes;
    int _anio;
    int _hora;
    int _minuto;
    int _segundo;

public:
    Fecha(int dia = 0, int mes = 0, int anio = 0, int hora = 0, int minuto = 0, int segundo = 0) {
        _dia = dia;
        _mes = mes;
        _anio = anio;
        _hora = hora;
        _minuto = minuto;
        _segundo = segundo;

    }

    int getDia() { return _dia;}
    int getMes() { return _mes;}
    int getAnio() { return _anio;}
    int getHora() {return _hora;}
    int getMinuto() {return _minuto;}
    int getSegundo() {return _segundo;}

    void setDia(int dia) { _dia = dia; }
    void setMes(int mes) { _mes = mes; }
    void setAnio(int anio) { _anio = anio; }
    void setHora(int hora) { _hora = hora; }
    void setMinuto(int minuto) { _minuto = minuto; }
    void setSegundo (int segundo) { _segundo = segundo; }

    std::string mostrar();
    void cargar();

    bool esFechaAnteriorOIgualActual();
    bool esFechaValida(int dia,int mes, int anio, int hora, int minuto, int segundo);
    bool esFechaPosteriorActual();

};
