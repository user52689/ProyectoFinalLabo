#include<iostream>

#include "Cliente.h"


int Cliente::getNumeroCliente() {
    return _numeroCliente;
}

void Cliente::setNumeroCliente(int numeroCliente) {
    _numeroCliente = numeroCliente;
}

int Cliente::getEstado() {
    return _estado;
}

void Cliente::setEstado(int estado) {
    _estado = estado;
}
