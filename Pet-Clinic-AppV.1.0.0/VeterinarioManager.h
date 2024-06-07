#pragma once
#include "VeterinarioArchivo.h"

class VeterinarioManager {
private:
    VeterinarioArchivo veterinarioArchivo;

public:
    void menu();
    void crearVeterinario();
    void mostrar(Veterinario veterinario);
    void buscarVeterinario();
    void cargarVeterinario();
    void listarVeterinarios();
    void eliminarVeterinario();
    void modificarHorario();
    void crearReporte();
};
