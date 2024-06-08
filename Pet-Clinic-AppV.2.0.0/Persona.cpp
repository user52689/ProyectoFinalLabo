#include <iostream>
#include <cstring>

#include "Persona.h"

using namespace std;

Persona::Persona(const char* nombre, const char* telefono, const char* email, const char* direccion, bool estado) {
    strcpy(_nombre, nombre);
    strcpy(_telefono, telefono);
    strcpy(_email, email);
    strcpy(_direccion, direccion);
    _estado = estado;
}

const char* Persona::getNombre() {
    return _nombre;
}


const char* Persona::getTelefono() {
    return _telefono;
}

const char* Persona::getEmail() {
    return _email;
}

const char* Persona::getDireccion() {
    return _direccion;
}


bool Persona::getEstado() {
    return _estado;
}

void Persona::setNombre(const char* nombre) {
    strcpy(_nombre, nombre);
}

void Persona::setTelefono(const char* telefono) {
    strcpy(_telefono, telefono);
}

void Persona::setEmail(const char* email) {
    strcpy(_email, email);
}

void Persona::setDireccion(const char* direccion) {
    strcpy(_direccion, direccion);
}

void Persona::setEstado(bool estado) {
    _estado = estado;
}
