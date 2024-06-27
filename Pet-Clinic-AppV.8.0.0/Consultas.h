#pragma once
#include "FechaHora.h"

class Consultas {
private:
    int _numeroTurno;
    FechaHora _fechaHoraTurno;
    int _legajoVeterinarioAsignado;
    int _mascotaInvolucrada;
    char _diagnosticoTratamiento[200];
    float _importe;
    bool _estado;

public:
    Consultas();
    Consultas(int numeroTurno, FechaHora fechaHora, int veterinarioAsignado, int mascotaInvolucrada, const char* diagnosticoTratamiento, float importe, bool estado);

    void setNumeroTurno(int numeroTurno);
    void setFechaHora(FechaHora fechaHoraRegistro);
    void setLegajoVeterinarioAsignado(int legajoVeterinarioAsignado);
    void setMascotaInvolucrada(int mascotaInvolucrada);
    void setDiagnosticoTratamiento(const char* diagnosticoTratamiento);
    void setImporte(float importe);
    void setEstado(bool estado);

    int getNumeroTurno();
    FechaHora getFechaHora();
    int getLegajoVeterinarioAsignado();
    int getMascotaInvolucrada();
    const char* getDiagnosticoTratamiento();
    float getImporte();
    bool getEstado();
};
