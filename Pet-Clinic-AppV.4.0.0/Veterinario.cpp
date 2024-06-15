#include <iostream>
using namespace std;
#include "Veterinario.h"

Veterinario::Veterinario() : Persona(){
    _legajo = 0;
}

Veterinario::Veterinario(int legajo, const char* nombre, const char* telefono, const char* email, const char* direccion, bool estado, Hora horaInicio, Hora horaSalida)
    : Persona(nombre, telefono, email, direccion, estado) {
    _legajo = legajo;
    _horaInicio = horaInicio;
    _horaSalida = horaSalida;
}

int Veterinario::getLegajo() {
    return _legajo;
}

void Veterinario::setLegajo(int legajo) {
    _legajo = legajo;
}

Hora Veterinario::getHoraInicio() {
    return _horaInicio;
}

void Veterinario::setHoraInicio(Hora horaInicio) {
    _horaInicio = horaInicio;
}

Hora Veterinario::getHoraSalida() {
    return _horaSalida;
}

void Veterinario::setHoraSalida(Hora horaSalida) {
    _horaSalida = horaSalida;
}
