#include <iostream>
#include "FechaHora.h"

using namespace std;


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
