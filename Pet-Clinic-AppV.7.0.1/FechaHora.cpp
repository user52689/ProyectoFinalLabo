#include <iostream>
#include "FechaHora.h"

using namespace std;


FechaHora::FechaHora(int dia, int mes, int anio, int hora, int minuto, int segundo){
    _fecha.setDia(dia);
    _fecha.setMes(mes);
    _fecha.setAnio(anio);
    _hora.setHora(hora);
    _hora.setMinuto(minuto);
    _hora.setSegundo(segundo);
}
FechaHora::FechaHora(){
    _fecha = Fecha();
    _hora = Hora();
}

string FechaHora::mostrarFechaHora(){
    return _fecha.mostrarFecha() + _hora.mostrarHora();
}

void FechaHora::setFecha(Fecha fecha){
    _fecha = fecha;
}
void FechaHora::setHora(Hora hora){
    _hora = hora;
}

Fecha FechaHora::getFecha(){
    return _fecha;
}
Hora FechaHora::hetHora(){
    return _hora;
}
