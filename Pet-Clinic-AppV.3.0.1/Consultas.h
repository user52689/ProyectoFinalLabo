#pragma once
#include "FechaHora.h"

class Consultas {
private:
    int _numeroTurno;
    FechaHora _fechaHora;
    int _veterinarioAsignado;
    int _mascotaInvolucrada;
    char _diagnosticoTratamiento[200];
    float _importe;
    bool _estado;

public:
    Consultas();
    Consultas(int numeroTurno, FechaHora fechaHora, int veterinarioAsignado, int mascotaInvolucrada, const char* diagnosticoTratamiento, float importe, bool estado);

    int getNumeroTurno();
    void setNumeroTurno(int numeroTurno);

    FechaHora getFechaHora();
    void setFechaHora(FechaHora fechaHora);

    int getVeterinarioAsignado();
    void setVeterinarioAsignado(int veterinarioAsignado);

    int getMascotaInvolucrada();
    void setMascotaInvolucrada(int mascotaInvolucrada);

    const char* getDiagnosticoTratamiento();
    void setDiagnosticoTratamiento(const char* diagnosticoTratamiento);

    float getImporte();
    void setImporte(float importe);

    bool getEstado();
    void setEstado(bool estado);
};
