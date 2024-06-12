#include <iostream>
#include <string>
#include "Hora.h"

using namespace std;

Hora::Hora(){
    time_t t = time(nullptr);
    tm* horaActual = localtime(&t);

    _hora = horaActual->tm_hour;
    _minuto = horaActual->tm_min;
    _segundo = horaActual->tm_sec;
}

string Hora::mostrarHora(){
    return "Hora: " + to_string(_hora) + ":" + to_string(_minuto) + ":" + to_string(_segundo);
}
bool esHoraValida(int hora, int minutos, int segundos){
    if (hora < 0 || hora > 23){
        return false;
    }
    if (minutos < 0 || minutos > 59){
        return false;
    }
    if (segundos < 0 || segundos > 59){
        return false;
    }
    return true;
}

int Hora::getHora(){
    return _hora;
}
int Hora::getMinuto(){
    return _minuto;
}
int Hora::getSegundo(){
    return _segundo;
}

void Hora::setHora(int hora){
    if (hora >= 1 && hora <= 23) {
        _hora = hora;
    }
}
void Hora::setMinuto(int minuto){
    if(minuto >=1 && minuto <= 59){
        _minuto = minuto;
    }
}
void Hora::setSegundo(int segundo){
    if (segundo >= 1 && segundo <= 59) {
        _segundo = segundo;
    }
}
