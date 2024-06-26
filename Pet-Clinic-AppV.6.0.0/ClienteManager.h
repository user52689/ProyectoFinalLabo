#pragma once
#include "Cliente.h"
#include "ClienteArchivo.h"

class ClienteManager {
private:
    ClienteArchivo clienteArchivo;

public:
    void menu();
    //Cliente crearCliente();
    void mostrar(Cliente cliente);
    void buscarCliente();
    void cargarCliente();
    void listarClientes();
    void eliminarCliente();
    void modificarDireccionCliente();
};
