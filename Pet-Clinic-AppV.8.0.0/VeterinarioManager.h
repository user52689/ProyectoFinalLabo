#pragma once
#include "Veterinario.h"
#include "VeterinarioArchivo.h"

class VeterinarioManager {
private:
    VeterinarioArchivo veterinarioArchivo;

public:
    void menu();
    Veterinario crearVeterinario();
    void mostrar(Veterinario veterinario, int posY);
    void mostrar(Veterinario veterinario);
    void buscarVeterinario();
    void cargarVeterinario();
    void listarVeterinarios();
    void eliminarVeterinario();
    void modificarTelefono();
};
