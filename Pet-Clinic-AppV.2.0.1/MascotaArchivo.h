#pragma once
#include "Mascota.h"
#include "Archivo.h"

class MascotaArchivo : public Archivo{
public:
    MascotaArchivo();
    MascotaArchivo(std::string fileName);

    void guardar(Mascota mascota);
    void guardar(int index, Mascota mascota);
    Mascota leer(int index);
    int getCantidadRegistros();
    bool isExist(int numeroMascota);
    Mascota buscar(int numeroMascota);
    bool eliminar(int numeroMascota);

private:

};
