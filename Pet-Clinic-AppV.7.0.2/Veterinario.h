#pragma once
#include "Persona.h"
#include "FechaHora.h"

class Veterinario : public Persona {
private:
    int _legajo;
    FechaHora _fechaHora;

public:
    Veterinario();
    Veterinario(int legajo, const char* nombre, const char* telefono, const char* email, const char* direccion, FechaHora fechaHora, bool estado);

    void setLegajo(int legajo);
    void setFechaHora(FechaHora fechaHora);

    int getLegajo();
    FechaHora getFechaHora();
};
