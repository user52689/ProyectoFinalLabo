#pragma once
#include "Fecha.h"
#include <string>

class Mascota
{
    public:
        //Constructores
        Mascota();
        Mascota(int numeroMascota, std::string nombre, int especie, Fecha anioNacimiento, int numeroCliente, bool estado);

        // Getters y Setters
        int getNumeroMascota();
        void setNumeroMascota(int numeroMascota);

        const char* getNombre();
        void setNombre(std::string nombre);

        int getEspecie();
        void setEspecie(int especie);

        Fecha getAnioNacimiento();
        void setAnioNacimiento(Fecha anioNacimiento);

        int getNumeroCliente();
        void setNumeroCliente(int numeroCliente);

        bool getEstado();
        void setEstado(bool estado);

    private:
        int _numeroMascota;
        char _nombre[20];
        int _especie;
        Fecha _anioNacimiento;
        int _numeroCliente;
        bool _estado;
};
