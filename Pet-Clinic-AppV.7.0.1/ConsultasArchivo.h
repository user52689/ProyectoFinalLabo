#pragma once
#include "Archivo.h"
#include "Consultas.h"

class ConsultasArchivo : public Archivo{
private:
    const char* _fileName;

public:
    ConsultasArchivo();

    bool guardar(Consultas turno);
    bool guardar(int index, Consultas turno);
    Consultas leer(int index);
    int getCantidadRegistros();
    bool isExist(int numeroTurno);
    int buscar(int numeroTurno);
    bool eliminar(int numeroTurno);
};
