#pragma once
#include "Persona.h"
#include "Hora.h"

class Veterinario : public Persona {
public:
    Veterinario();
    Veterinario(int legajo, const char* nombre, const char* telefono, const char* email, const char* direccion, bool estado, Hora horaInicio, Hora horaSalida);

    int getLegajo();
    void setLegajo(int legajo);

    Hora getHoraInicio();
    void setHoraInicio(Hora horaInicio);

    Hora getHoraSalida();
    void setHoraSalida(Hora horaSalida);

private:
    int _legajo;
    Hora _horaInicio;
    Hora _horaSalida;
};
