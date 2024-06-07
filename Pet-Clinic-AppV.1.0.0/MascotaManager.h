#pragma once
#include "MascotaArchivo.h"

class MascotaManager {
private:
    MascotaArchivo mascotaArchivo;

public:
    void menu();
    void crearMascota();
    void mostrar(Mascota mascota);
    void buscarMascota();
    void cargarMascota();
    void listarMascotas();
    void eliminarMascota();
    void modificarEdad();
    void crearReporte();
};
