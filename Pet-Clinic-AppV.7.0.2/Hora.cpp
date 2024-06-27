#include <iostream>
#include <string>
#include "Interfaz.h"
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


bool Hora::esHoraValida(int hora, int minutos, int segundos){
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
bool Hora::cargarHora(){
    int hora, minutos, segundos;
    Interfaz interfaz;
    int posX = 30;
    int posY = 24;

    cout<<"Hora: ";
    cin>>hora;
    interfaz.moverCursor(posX,posY);
    cout<<"Minuto: ";
    interfaz.moverCursor(36,posY++);
    cin>>minutos;
    interfaz.moverCursor(posX,posY);
    cout<<"Segundo: ";
    interfaz.moverCursor(36,posY);
    cin>>segundos;

    if(esHoraValida(hora, minutos, segundos)){
        _hora = hora;
        _minuto = minutos;
        _segundo = segundos;
        return true;
    }
    return false;
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
