#pragma once
#include "Persona.h"

class Cliente : public Persona {
public:
    Cliente();
    Cliente(int numeroCliente, const char* nombre, const char* telefono, const char* email, const char* direccion, bool estado);

    int getNumeroCliente();
    void setNumeroCliente(int numeroCliente);

private:
    int _numeroCliente;
};
