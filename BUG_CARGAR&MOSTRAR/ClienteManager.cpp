#include <iostream>
#include <cstdlib>
#include <string>
#include "ClienteManager.h"
#include "Cliente.h"
#include "ClienteArchivo.h"

using namespace std;

Cliente ClienteManager::crearCliente(){
    int numeroCliente;

    ClienteArchivo clienteArchivo;

    // Asignacion automatica del número de cliente
    int cantidadRegistros = clienteArchivo.getCantidadRegistros();
    numeroCliente = cantidadRegistros + 1;

    cout << "Numero de Cliente: " << numeroCliente << endl;

    // Crear un cliente temporal para cargar los datos de Persona
    Cliente clienteTemporal;
    clienteTemporal.cargar(); // Cargar los datos de Persona

    // Crear el cliente final con los datos cargados
    Cliente cliente(numeroCliente, clienteTemporal.getNombre(), clienteTemporal.getTelefono(), clienteTemporal.getEmail(), clienteTemporal.getDireccion(), clienteTemporal.getEstado());

    return cliente;
}

void ClienteManager::mostrar(Cliente cliente) {
    if (cliente.getEstado()) {
        std::cout << "Numero de Cliente: " << cliente.getNumeroCliente() << std::endl;
        std::cout << "Nombre: " << cliente.getNombre() << std::endl;
        std::cout << "Telefono: " << cliente.getTelefono() << std::endl;
        std::cout << "Email: " << cliente.getEmail() << std::endl;
        std::cout << "Direccion: " << cliente.getDireccion() << std::endl;
        std::cout << "Estado: " << (cliente.getEstado() ? "Activo" : "Inactivo") << std::endl;
        std::cout << "-------------------------------" << std::endl;
    } else {
        std::cout << "El cliente esta inactivo" << std::endl;
    }
}

/*
void ClienteManager::mostrar(Cliente cliente) {
    // Verifica que el estado del cliente sea verdadero (Activo)
    if (cliente.getEstado()) {
        cout << "Numero de Cliente paso: " << cliente.getNumeroCliente() << endl;
        cliente.mostrar(); // Llama al mtodo mostrar de Persona
        cout << "-------------------------------" << endl;
    } else {
        cout << "El cliente esta inactivo" << endl;
    }
}
*/

void ClienteManager::cargarCliente() {
    Cliente cliente = crearCliente();

    if (clienteArchivo.guardar(cliente)) {
        std::cout << "Cliente guardado con exito!!" << std::endl;
    } else {
        std::cout << "No se pudo guardar el cliente :(" << std::endl;
    }
}

void ClienteManager::buscarCliente() {
    int index, numero;
    Cliente cliente;

    std::cout << "Ingrese el numero de cliente a buscar: ";
    std::cin >> numero;

    index = clienteArchivo.buscar(numero);

    if (index >= 0) {
        cliente = clienteArchivo.leer(index);
        if (cliente.getEstado()) {
            mostrar(cliente);
        } else {
            std::cout << "El cliente esta desactivado" << std::endl;
        }
    } else {
        std::cout << "El cliente no se encuentra :(" << std::endl;
    }
}

void ClienteManager::listarClientes() {
    int cantidad = clienteArchivo.getCantidadRegistros();

    for (int i = 0; i < cantidad; i++) {
        Cliente cliente = clienteArchivo.leer(i);
        mostrar(cliente);
    }
}

void ClienteManager::eliminarCliente() {
    int numeroCliente, index;

    std::cout << "Ingrese numero de cliente que quiere eliminar: ";
    std::cin >> numeroCliente;

    index = clienteArchivo.buscar(numeroCliente);

    if (index != -1) {
        Cliente cliente = clienteArchivo.leer(index);
        bool eliminar;

        mostrar(cliente);

        std::cout << " Esta seguro que quiere eliminar el cliente? [1-SI] || [0-NO] ";
        std::cin >> eliminar;

        if (eliminar) {
            if (clienteArchivo.eliminar(numeroCliente)) {
                std::cout << " El cliente se elimino correctamente!" << std::endl;
            } else {
                std::cout << "El cliente no se pudo eliminar..." << std::endl;
            }
        } else {
            std::cout << "El cliente no se elimino." << std::endl;
        }
    } else {
        std::cout << "El cliente no existe..." << std::endl;
    }
}

void ClienteManager::modificarDireccionCliente() {
    int numeroCliente, index;
    Cliente cliente;

    std::cout << "Ingrese el numero de cliente que desea modificar: ";
    std::cin >> numeroCliente;

    index = clienteArchivo.buscar(numeroCliente);

    if (index != -1) {
        cliente = clienteArchivo.leer(index);
        mostrar(cliente);

        std::cout << " Desea modificar la direccion? [1-SI] || [0-NO]: ";
        int confirmacion;
        std::cin >> confirmacion;

        if (confirmacion == 1) {
            std::string nuevaDireccion;
            std::cin.ignore(); // Ignorar el salto de linea despues del entero
            std::cout << "Ingrese la nueva direccion: ";
            std::getline(std::cin, nuevaDireccion);

            // Modificar la direccion del cliente
            cliente.setDireccion(nuevaDireccion);

            // Guardar el registro modificado en el mismo indice
            if (clienteArchivo.guardar(index, cliente)) {
                std::cout << "¡La direccion se modifico correctamente!" << std::endl;
            } else {
                std::cout << "No se pudo modificar la direccion..." << std::endl;
            }
        } else {
            std::cout << "No se modifico la direccion." << std::endl;
        }
    } else {
        std::cout << "El cliente no existe." << std::endl;
    }
}

void ClienteManager::crearReporte() {
    // Implementar la generacion de un reporte de clientes
}

void ClienteManager::menu() {
    int opcion;

    do {
        system("cls");
        std::cout << "--------- MENU CLIENTES -------" << std::endl;
        std::cout << "-------------------------------" << std::endl;
        std::cout << "1- CARGAR CLIENTE" << std::endl;
        std::cout << "2- BUSCAR CLIENTE POR NUMERO" << std::endl;
        std::cout << "3- LISTAR TODOS LOS CLIENTES" << std::endl;
        std::cout << "4- MODIFICAR DIRECCION" << std::endl;
        std::cout << "5- ELIMINAR CLIENTE" << std::endl;
        std::cout << "-------------------------------" << std::endl;
        std::cout << "0- SALIR" << std::endl;
        std::cout << "-------------------------------" << std::endl;
        std::cout << "Opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                system("cls");
                cargarCliente();
                break;
            case 2:
                system("cls");
                buscarCliente();
                break;
            case 3:
                system("cls");
                listarClientes();
                break;
            case 4:
                system("cls");
                modificarDireccionCliente();
                break;
            case 5:
                system("cls");
                eliminarCliente();
                break;
            case 0:
                system("cls");
                break;
            default:
                std::cout << "Opcion no valida. Intente nuevamente." << std::endl;
                break;
        }
        system("pause");

    } while (opcion != 0);
}
