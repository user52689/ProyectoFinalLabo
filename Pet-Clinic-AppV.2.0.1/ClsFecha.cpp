#include "ClsFecha.h"
#include <ctime>
#include <iostream>

bool Fecha::esFechaValida(int dia, int mes, int anio, int hora, int minuto, int segundo) {
    if (mes < 1 || mes > 12)  {return false;}

    if (dia < 1 || dia > 31) {return false;}

    if (anio<1800) {return false;}

    if (hora < 1 || hora > 23) {return false;}

    if (minuto < 0 || minuto > 59) {return false;}

    if (segundo < 0 || segundo > 59) {return false;}

    return true;
}

void Fecha::cargar() {
    bool fechaValida = false;

    while (!fechaValida || !esFechaAnteriorOIgualActual()) {
        std::cout << "Ingrese dia: ";
        std::cin >> _dia;
        std::cout << "Ingrese mes: ";
        std::cin >> _mes;
        std::cout << "Ingrese anio: ";
        std::cin >> _anio;
        std::cout << "Ingrese hora: ";
        std::cin >> _hora;
        std::cout << "Ingrese minuto: ";
        std::cin >> _minuto;
        std::cout << "Ingrese segundo: ";
        std::cin >> _segundo;

        fechaValida = esFechaValida(_dia, _mes, _anio, _hora, _minuto, _segundo);

        if (!fechaValida) {
            std::cout << "La fecha ingresada es incorrecta. Por favor, ingresela nuevamente." << std::endl;
        } else if (!esFechaAnteriorOIgualActual()) {
            std::cout << "La fecha ingresada debe ser anterior o igual a la fecha actual." << std::endl;
            fechaValida = false;
        }
    }
}

bool Fecha::esFechaAnteriorOIgualActual() {
    time_t tiempoActual = time(NULL);
    tm* tiempoDescompuesto = localtime(&tiempoActual);
    int anioActual = tiempoDescompuesto->tm_year + 1900;
    int mesActual = tiempoDescompuesto->tm_mon + 1;
    int diaActual = tiempoDescompuesto->tm_mday;
    int horaActual = tiempoDescompuesto->tm_hour;
    int minutoActual = tiempoDescompuesto->tm_min;
    int segundoActual = tiempoDescompuesto->tm_sec;

    if (_anio < anioActual)
        return true;
    if (_anio == anioActual && _mes < mesActual)
        return true;
    if (_anio == anioActual && _mes == mesActual && _dia < diaActual)
        return true;
    if (_anio == anioActual && _mes == mesActual && _dia == diaActual) {
        if (_hora < horaActual)
            return true;
        if (_hora == horaActual && _minuto < minutoActual)
            return true;
        if (_hora == horaActual && _minuto == minutoActual && _segundo <= segundoActual)
            return true;
    }

    std::cout << "La fecha ingresada debe ser anterior o igual a la fecha actual." << std::endl;
    return false;
}

bool Fecha::esFechaPosteriorActual()  {
    return true;
}

std::string Fecha::mostrar()  {
    return std::to_string(_dia) + "/" + std::to_string(_mes) + "/" + std::to_string(_anio) + " " +
           std::to_string(_hora) + ":" + std::to_string(_minuto) + ":" + std::to_string(_segundo);
}
