#pragma once
#include <string>
#include "Fecha.h"
#include "Hora.h"

class FechaHora{
private:
    Fecha _fecha;
    Hora _hora;

public:
    FechaHora();
    FechaHora(int dia, int mes, int anio, int hora, int minuto, int segundo);

    std::string mostrarFechaHora();

    void setFecha(Fecha fecha);
    void setHora(Hora hora);

    Fecha getFecha();
    Hora hetHora();
};

