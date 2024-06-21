#include <cstring>
#include "Consultas.h"

Consultas::Consultas() {
    _numeroTurno = 0;
    _fechaHoraRegistro = FechaHora();
    _legajoVeterinarioAsignado = 0;
    _mascotaInvolucrada = 0;
    strcpy(_diagnosticoTratamiento, "");
    _importe = 0;
    _estado = false;
}
Consultas::Consultas(int numeroTurno, FechaHora fechaHora, int veterinarioAsignado, int mascotaInvolucrada, const char* diagnosticoTratamiento, float importe, bool estado) {
    _numeroTurno = numeroTurno;
    _fechaHoraRegistro = fechaHora;
    _legajoVeterinarioAsignado = veterinarioAsignado;
    _mascotaInvolucrada = mascotaInvolucrada;
    strcpy(_diagnosticoTratamiento, diagnosticoTratamiento);
    _importe = importe;
    _estado = estado;
}


void Consultas::setNumeroTurno(int numeroTurno) {
    _numeroTurno = numeroTurno;
}
void Consultas::setFechaHora(FechaHora fechaHora) {
    _fechaHoraRegistro = fechaHora;
}
void Consultas::setLegajoVeterinarioAsignado(int legajoVeterinarioAsignado) {
    _legajoVeterinarioAsignado = legajoVeterinarioAsignado;
}
void Consultas::setMascotaInvolucrada(int mascotaInvolucrada) {
    _mascotaInvolucrada = mascotaInvolucrada;
}
void Consultas::setDiagnosticoTratamiento(const char* diagnosticoTratamiento) {
    strcpy(_diagnosticoTratamiento, diagnosticoTratamiento);
}
void Consultas::setImporte(float importe) {
    _importe = importe;
}
void Consultas::setEstado(bool estado) {
    _estado = estado;
}

int Consultas::getNumeroTurno() {
    return _numeroTurno;
}
FechaHora Consultas::getFechaHora() {
    return _fechaHoraRegistro;
}
int Consultas::getLegajoVeterinarioAsignado() {
    return _legajoVeterinarioAsignado;
}
int Consultas::getMascotaInvolucrada() {
    return _mascotaInvolucrada;
}
const char* Consultas::getDiagnosticoTratamiento() {
    return _diagnosticoTratamiento;
}
float Consultas::getImporte() {
    return _importe;
}
bool Consultas::getEstado() {
    return _estado;
}
