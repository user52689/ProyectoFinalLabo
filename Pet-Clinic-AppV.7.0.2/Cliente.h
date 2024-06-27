#pragma once
#include "Persona.h"

class Cliente : public Persona {
private:
    int _numeroCliente;

public:
    Cliente();
    Cliente(int numeroCliente, const char* nombre, const char* telefono, const char* email, const char* direccion, bool estado);

    void setNumeroCliente(int numeroCliente);

    int getNumeroCliente();
};
