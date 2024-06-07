#pragma once
#include "Mascota.h"

class MascotaArchivo {
private:
    const char* fileName;

public:
    MascotaArchivo();
    MascotaArchivo(const char* fileName);

    void guardar(Mascota mascota);
    void guardar(int index, Mascota mascota);
    Mascota leer(int index);
    int getCantidadRegistros();
    bool isExist(int numeroMascota);
    Mascota buscar(int numeroMascota);
    void eliminar(int numeroMascota);
};
