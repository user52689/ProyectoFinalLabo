#pragma once
#include "Veterinario.h"

class VeterinarioArchivo {
private:
    const char* fileName;

public:
    VeterinarioArchivo();
    VeterinarioArchivo(const char* fileName);

    void guardar(Veterinario veterinario);
    void guardar(int index, Veterinario veterinario);
    Veterinario leer(int index);
    int getCantidadRegistros();
    bool isExist(int legajo);
    int buscar(int legajo);
    void eliminar(const char* nombreVeterinario);
};
