#pragma once
#include "Cliente.h"

class ClienteArchivo {
private:
    const char* fileName;

public:
    ClienteArchivo();
    ClienteArchivo(const char* fileName);

    void guardar(Cliente cliente);
    void guardar(int index, Cliente cliente);
    Cliente leer(int index);
    int getCantidadRegistros();
    bool isExist(int numeroCliente);
    int buscar(int numeroCliente);
    void eliminar(int numeroCliente);
};
