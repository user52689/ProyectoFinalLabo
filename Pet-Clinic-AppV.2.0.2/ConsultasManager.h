#pragma once
#include "TurnoArchivo.h"

class ConsultasManager {
private:
    TurnoArchivo turnoArchivo;

public:
    void menu();
    void crearTurno();
    void mostrar(Turno turno);
    void buscarTurno();
    void cargarTurno();
    void listarTurnos();
    void eliminarTurno();
    void modificarFechaHora();
};
