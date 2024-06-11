#include<iostream>

#include "Cliente.h"


Cliente::Cliente() : Persona() {
    _numeroCliente = 0;
}

Cliente::Cliente(int numeroCliente, std::string nombre, std::string telefono, std::string email, std::string direccion, bool estado)
    : Persona(nombre, telefono, email, direccion, estado) {
    _numeroCliente = numeroCliente;
}


int Cliente::getNumeroCliente() {
    return _numeroCliente;
}

void Cliente::setNumeroCliente(int numeroCliente) {
    _numeroCliente = numeroCliente;
}
