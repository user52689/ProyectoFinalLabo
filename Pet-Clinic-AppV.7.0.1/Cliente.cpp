#include<iostream>
using namespace std;
#include "Cliente.h"

Cliente::Cliente() : Persona() {
    _numeroCliente = 0;
}

Cliente::Cliente(int numeroCliente, const char* nombre, const char* telefono, const char* email, const char* direccion, bool estado) : Persona(nombre, telefono, email, direccion, estado) {
    _numeroCliente = numeroCliente;
}

int Cliente::getNumeroCliente() {
    return _numeroCliente;
}

void Cliente::setNumeroCliente(int numeroCliente) {
    _numeroCliente = numeroCliente;
}
