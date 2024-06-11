#pragma once
#include "Persona.h"

class Cliente : public Persona {
public:
    Cliente();
    Cliente(int numeroCliente, std::string nombre, std::string telefono, std::string email, std::string direccion, bool estado);

    int getNumeroCliente();
    void setNumeroCliente(int numeroCliente);

private:
    int _numeroCliente;
};
