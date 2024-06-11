#include <cstring>
#include "Consultas.h"

Consultas::Consultas(int numeroTurno, const char* fechaHora, int veterinarioAsignado, int mascotaInvolucrada, const char* diagnosticoTratamiento, float importe, bool estado) {
    _numeroTurno = numeroTurno;
    strcpy(_fechaHora, fechaHora);
    _veterinarioAsignado = veterinarioAsignado;
    _mascotaInvolucrada = mascotaInvolucrada;
    strcpy(_diagnosticoTratamiento, diagnosticoTratamiento);
    _importe = importe;
    _estado = estado;
}

int Consultas::getNumeroTurno() {
    return _numeroTurno;
}

void Consultas::setNumeroTurno(int numeroTurno) {
    _numeroTurno = numeroTurno;
}

const char* Consultas::getFechaHora() {
    return _fechaHora;
}

void Consultas::setFechaHora(const char* fechaHora) {
    strcpy(_fechaHora, fechaHora);
}

int Consultas::getVeterinarioAsignado() {
    return _veterinarioAsignado;
}

void Consultas::setVeterinarioAsignado(int veterinarioAsignado) {
    _veterinarioAsignado = veterinarioAsignado;
}

int Consultas::getMascotaInvolucrada() {
    return _mascotaInvolucrada;
}

void Consultas::setMascotaInvolucrada(int mascotaInvolucrada) {
    _mascotaInvolucrada = mascotaInvolucrada;
}

const char* Consultas::getDiagnosticoTratamiento() {
    return _diagnosticoTratamiento;
}

void Consultas::setDiagnosticoTratamiento(const char* diagnosticoTratamiento) {
    strcpy(_diagnosticoTratamiento, diagnosticoTratamiento);
}

float Consultas::getImporte() {
    return _importe;
}

void Consultas::setImporte(float importe) {
    _importe = importe;
}

bool Consultas::getEstado() {
    return _estado;
}

void Consultas::setEstado(bool estado) {
    _estado = estado;
}
