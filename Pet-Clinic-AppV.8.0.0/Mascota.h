#pragma once
#include <string>
#include "FechaHora.h"

class Mascota{
private:
    int _numeroMascota;
    char _nombre[20];
    int _especie;
    Fecha _anioNacimiento;
    FechaHora _fechaHoraRegistro;
    int _numeroCliente;
    bool _estado;

public:
    Mascota();
    Mascota(int numeroMascota, std::string nombre, int especie, Fecha anioNacimiento, FechaHora fechaHoraRegistro, int numeroCliente, bool estado);

    void setNombre(std::string nombre);
    void setNumeroMascota(int numeroMascota);
    void setEspecie(int especie);
    void setAnioNacimiento(Fecha anioNacimiento);
    void setFechaHoraRegistro(FechaHora fechaHoraRegistro);
    void setNumeroCliente(int numeroCliente);
    void setEstado(bool estado);

    int getNumeroMascota();
    const char* getNombre();
    int getEspecie();
    Fecha getAnioNacimiento();
    FechaHora getFechaHoraRegistro();
    int getNumeroCliente();
    bool getEstado();
};
