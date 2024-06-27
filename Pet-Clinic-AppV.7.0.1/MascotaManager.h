#pragma once
#include "Mascota.h"
#include "MascotaArchivo.h"


class MascotaManager {
private:
    MascotaArchivo _mascotaArchivo;

public:
    void menu();
    Mascota crearMascota();
    void mostrar(Mascota mascota);
    void mostrar(Mascota mascota, int posY);
    void buscarMascota();
    void cargarMascota();
    void listarMascotas();
    void eliminarMascota();
    void modificarFechaNacimiento();///Buscar otra modificacion y agragar un reporte a cada clase base
};
