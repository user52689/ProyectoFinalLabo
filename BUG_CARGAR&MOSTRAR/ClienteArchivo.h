#pragma once
#include "Cliente.h"
#include "Archivo.h"

class ClienteArchivo : public Archivo {
public:
    ClienteArchivo();
    ClienteArchivo(std::string fileName);

    bool guardar(Cliente cliente);
    bool guardar(int index, Cliente cliente);
    Cliente leer(int index);
    int getCantidadRegistros();
    bool isExist(int numeroCliente);
    int buscar(int numeroCliente);
    bool eliminar(int numeroCliente);
};
