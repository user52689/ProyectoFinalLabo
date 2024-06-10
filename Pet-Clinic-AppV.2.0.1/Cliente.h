#pragma once

#include "Persona.h"

class Cliente : public Persona {
private:
    int _numeroCliente;
    int _estado;

public:
    int getNumeroCliente();
    void setNumeroCliente(int numeroCliente);

    int getEstado();
    void setEstado(int estado);
};
