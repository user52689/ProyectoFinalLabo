#pragma once

class Consultas {
private:
    int _numeroTurno;
    char _fechaHora[20];
    int _veterinarioAsignado;
    int _mascotaInvolucrada;
    char _diagnosticoTratamiento[70];
    float _importe;
    bool _estado;

public:
    Consultas(int numeroTurno, const char* fechaHora, int veterinarioAsignado, int mascotaInvolucrada, const char* diagnosticoTratamiento, float importe, bool estado);

    int getNumeroTurno();
    void setNumeroTurno(int numeroTurno);

    const char* getFechaHora();
    void setFechaHora(const char* fechaHora);

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
