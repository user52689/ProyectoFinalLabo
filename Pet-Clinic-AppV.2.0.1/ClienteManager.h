#pragma once
#include "ClienteArchivo.h"

class ClienteManager {
private:
    ClienteArchivo _clienteArchivo;

public:
    void menu();
    void crearCliente();
    void mostrar(Cliente cliente);
    void buscarCliente();
    void cargarCliente();
    void listarClientes();
    void eliminarCliente();
    void modificarCliente();
    void crearReporte();
};
