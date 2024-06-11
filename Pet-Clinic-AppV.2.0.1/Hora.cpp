#include <iostream>
#include <string>
#include "Hora.h"

using namespace std;

Hora::Hora(int hora, int minuto, int segundo){
    setHora(hora);
    setMinuto(minuto);
    setSegundo(segundo);
};
Hora::Hora() {
    time_t t = time(nullptr);
    tm* horaActual = localtime(&t);

    hora = horaActual->tm_hour;
    minuto = horaActual->tm_min;
    segundo = horaActual->tm_sec;
}

void Hora::mostrar() const {
    cout << "Hora: " << to_string(_hora) << ":" << to_string(_minuto) << ":" << to_satring(_segundo) <<endl;
}
bool esValida(int hora, int minutos, int segundos){
    if (hora < 0 || hora > 23) {
        return false;
    }
    if (minutos < 0 || minutos > 59) {
        return false;
    }
    if (segundos < 0 || segundos > 59) {
        return false;
    }
    return true;
}

int Hora::getHora(){
    return hora;
}
int Hora::getMinuto(){
    return minuto;
}
int Hora::getSegundo(){
    return segundo;
}

void Hora::setHora(int hora){
    if (hora >= 1 && hora <= 23) {
        _hora = hora;
    }
}
void Hora::setMinuto(int minuto){
    if (minutos >=1 0 && minutos <= 59) {
        _minuto = minuto;
    }
}
void Hora::setSegundo(int segundo){
    if (segundos >= 1 && segundos <= 59) {
        _segundo = segundo;
    }
}
