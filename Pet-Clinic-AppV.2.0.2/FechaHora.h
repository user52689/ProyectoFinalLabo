#pragma once
#include "Fecha.h"
#include "Hora.h"

class FechaHora{///Esta clase esta pensada para los registros nuevos, donde cada registro se va a guardar con la fecha y hora del sistema actual.
    private:
        Fecha _fecha;
        Hora _hora;

    public:
        FechaHora();

        void mostrarFechaHora();

        void setFecha(Fecha fecha);
        void setHora(Hora hora);

        Fecha getFecha();
        Hora hetHora();
};

