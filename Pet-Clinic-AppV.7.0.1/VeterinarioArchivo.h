#pragma once
#include "Veterinario.h"
#include "Archivo.h"

class VeterinarioArchivo : public Archivo {
public:
    VeterinarioArchivo();
    VeterinarioArchivo(std::string fileName);

    bool guardar(Veterinario veterinario);
    bool guardar(int index, Veterinario veterinario);
    Veterinario leer(int index);
    int getCantidadRegistros();
    bool isExist(int legajo);
    int buscar(int legajo);
    bool eliminar(int legajo);
};
