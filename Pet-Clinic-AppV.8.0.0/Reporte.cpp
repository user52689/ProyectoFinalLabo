#include <iostream>
#include <cstring>
#include <string>
#include "Reporte.h"


using namespace std;

Reporte::Reporte(const char* nombre){
    strcpy(_nombre, nombre);
}

void Reporte::setNombre(std::string nombre){
    strcpy(_nombre, nombre.c_str());
}
const char* Reporte::getNombre(){
    return _nombre;
}
