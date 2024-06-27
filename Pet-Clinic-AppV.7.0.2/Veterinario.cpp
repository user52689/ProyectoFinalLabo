#include <iostream>
using namespace std;
#include "Veterinario.h"
#include "FechaHora.h"

Veterinario::Veterinario() : Persona(){
    _legajo = 0;
}

Veterinario::Veterinario(int legajo, const char* nombre, const char* telefono, const char* email, const char* direccion, FechaHora fechaHora, bool estado)
    : Persona(nombre, telefono, email, direccion, estado) {
    _legajo = legajo;
    _fechaHora = FechaHora();
}

int Veterinario::getLegajo() {
    return _legajo;
}

void Veterinario::setLegajo(int legajo) {
    _legajo = legajo;
}

FechaHora Veterinario::getFechaHora() {
    return _fechaHora;
}

void Veterinario::setFechaHora(FechaHora fechaHora) {
    _fechaHora = fechaHora;
}
