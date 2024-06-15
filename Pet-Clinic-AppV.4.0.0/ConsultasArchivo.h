#pragma once
#include "Turno.h"

class ConsultaArchivo {
private:
    const char* fileName;

public:
    ConsultaArchivo();
    ConsultaArchivo(const char* fileName);

    void guardar(Turno turno);
    void guardar(int index, Turno turno);
    Turno leer(int index);
    int getCantidadRegistros();
    bool isExist(const char* fechaHora);
    int buscar(const char* fechaHora);
    void eliminar(const char* fechaHora);
};
