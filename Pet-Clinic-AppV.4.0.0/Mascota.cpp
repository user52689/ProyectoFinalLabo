#include "Mascota.h"
#include <string>
#include <cstring>

using namespace std;

Mascota::Mascota()
{
    _numeroMascota = 0;
     strcpy(_nombre, "");
    _especie = 0;
    _anioNacimiento = Fecha(0, 0, 0);
    _numeroCliente = 0;
    _estado = false;
}

Mascota::Mascota(int numeroMascota, string nombre, int especie, Fecha anioNacimiento, int numeroCliente, bool estado)
{
    setNumeroMascota(numeroMascota);
    setNombre(nombre);
    setEspecie(especie);
    setAnioNacimiento(anioNacimiento);
    setNumeroCliente(numeroCliente);
    setEstado(estado);
}

int Mascota::getNumeroMascota()
{
    return _numeroMascota;
}

void Mascota::setNumeroMascota(int numeroMascota)
{
    _numeroMascota = numeroMascota;
}

const char* Mascota::getNombre()
{
    return _nombre;
}

void Mascota::setNombre(string nombre)
{
    if(nombre.size() <= 19)
    {
        strcpy(_nombre, nombre.c_str());
    }
    else
    {
        strcpy(_nombre, "SIN DATOS");
    }
}

int Mascota::getEspecie()
{
    return _especie;
}

void Mascota::setEspecie(int especie)
{
    _especie = especie;
}

Fecha Mascota::getAnioNacimiento()
{
    return _anioNacimiento;
}

void Mascota::setAnioNacimiento(Fecha anioNacimiento)
{
    _anioNacimiento = anioNacimiento;
}

int Mascota::getNumeroCliente()
{
    return _numeroCliente;
}

void Mascota::setNumeroCliente(int numeroCliente)
{
    _numeroCliente = numeroCliente;
}

bool Mascota::getEstado()
{
    return _estado;
}

void Mascota::setEstado(bool estado)
{
    _estado = estado;
}
