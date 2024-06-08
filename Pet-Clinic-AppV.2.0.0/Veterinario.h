#pragma once

#include "Persona.h"

class Veterinario : public Persona {
private:
    int _legajo;

public:

    int getLegajo();
    void setLegajo(int legajo);
};
