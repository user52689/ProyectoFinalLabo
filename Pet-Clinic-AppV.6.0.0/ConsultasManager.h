#pragma once
#include "Consultas.h"
#include "ConsultasArchivo.h"

class ConsultasManager {
private:
    ConsultasArchivo _consultasArchivo;

public:
    void menu();
    void mostrar(Consultas turno);
    void buscarTurno();
    void cargarTurno();
    void listarTurnos();
    void eliminarTurno();
    void modificarVeterinarioAsignado();
};
