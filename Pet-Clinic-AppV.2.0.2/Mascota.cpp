#include <string>
#include "Mascota.h"
using namespace std;

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

string Mascota::getNombre()
{
    return _nombre;
}

void Mascota::setNombre(string nombre)
{
    if(nombre.size() <= 19)
    {
        _nombre = nombre;
    }
    else
    {
        _nombre = "SIN NOMBRE";
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
