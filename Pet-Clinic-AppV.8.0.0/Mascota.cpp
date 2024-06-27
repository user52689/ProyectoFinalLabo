#include "Mascota.h"
#include <string>
#include <cstring>
#include "FechaHora.h"

using namespace std;

Mascota::Mascota(){
    _numeroMascota = 0;
     strcpy(_nombre, "");
    _especie = 0;
    _anioNacimiento = Fecha(0, 0, 0);
    _fechaHoraRegistro = FechaHora();
    _numeroCliente = 0;
    _estado = false;
}

Mascota::Mascota(int numeroMascota, string nombre, int especie, Fecha anioNacimiento, FechaHora fechaHoraRegistro, int numeroCliente, bool estado){
    setNumeroMascota(numeroMascota);
    setNombre(nombre);
    setEspecie(especie);
    setAnioNacimiento(anioNacimiento);
    setFechaHoraRegistro(fechaHoraRegistro);
    setNumeroCliente(numeroCliente);
    setEstado(estado);
}

void Mascota::setNumeroMascota(int numeroMascota){
    _numeroMascota = numeroMascota;
}
void Mascota::setNombre(string nombre){
    if(nombre.size() <= 19)
    {
        strcpy(_nombre, nombre.c_str());
    }
    else
    {
        strcpy(_nombre, "SIN DATOS");
    }
}
void Mascota::setEspecie(int especie){
    _especie = especie;
}
void Mascota::setAnioNacimiento(Fecha anioNacimiento){
    _anioNacimiento = anioNacimiento;
}
void Mascota::setFechaHoraRegistro(FechaHora fechaHoraRegistro){
    _fechaHoraRegistro = fechaHoraRegistro;
}
void Mascota::setNumeroCliente(int numeroCliente){
    _numeroCliente = numeroCliente;
}
void Mascota::setEstado(bool estado){
    _estado = estado;
}


int Mascota::getNumeroMascota(){
    return _numeroMascota;
}
const char* Mascota::getNombre(){
    return _nombre;
}
int Mascota::getEspecie(){
    return _especie;
}
Fecha Mascota::getAnioNacimiento(){
    return _anioNacimiento;
}
FechaHora Mascota::getFechaHoraRegistro(){
    return _fechaHoraRegistro;
}

int Mascota::getNumeroCliente(){
    return _numeroCliente;
}
bool Mascota::getEstado(){
    return _estado;
}

