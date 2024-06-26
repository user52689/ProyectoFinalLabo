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
    void mostrar(Cliente cliente, int posY);///mostrar agregado para mostrar el forma de lista
    void buscarCliente();
    void cargarCliente();
    void listarClientes();
    void eliminarCliente();
    void modificarDireccionCliente();
};
