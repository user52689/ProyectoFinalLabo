#include <iostream>
#include <cstdlib>
#include <string>
#include "ClienteManager.h"
#include "Cliente.h"
#include "ClienteArchivo.h"

using namespace std;

void ClienteManager::cargarCliente() {
    int numeroCliente;

    ClienteArchivo clienteArchivo;

    int cantidadRegistros = clienteArchivo.getCantidadRegistros();// Asignacion automatica del número de cliente
    numeroCliente = cantidadRegistros + 1;

    cout << "Numero de Cliente: " << numeroCliente << endl;

    Persona persona;
    persona.cargar();

    Cliente cliente(numeroCliente, persona.getNombre(), persona.getTelefono(), persona.getEmail(), persona.getDireccion(), persona.getEstado());

    if (clienteArchivo.guardar(cliente)) {
        cout << "Cliente guardado con exito!!" << endl;
    } else {
        cout << "No se pudo guardar el cliente :(" << endl;
    }
}


void ClienteManager::buscarCliente() {
    int index, numero;
    Cliente cliente;

    cout << "Ingrese el numero de cliente a buscar: ";
    cin >> numero;

    ClienteArchivo clienteArchivo;

    index = clienteArchivo.buscar(numero);

    if (index >= 0) {
        cliente = clienteArchivo.leer(index);
        if (cliente.getEstado()) {
            mostrar(cliente);
        } else {
            cout << "El cliente esta desactivado" << endl;
        }
    } else {
        cout << "El cliente no se encuentra :(" << endl;
    }
}

void ClienteManager::listarClientes() {
    ClienteArchivo clienteArchivo;
    int cantidad = clienteArchivo.getCantidadRegistros();

    for (int i = 0; i < cantidad; i++) {
        Cliente cliente = clienteArchivo.leer(i);
        mostrar(cliente);
    }
}
void ClienteManager::mostrar(Cliente cliente) {
    if (cliente.getEstado()) {
        cout << "Numero de Cliente: " << cliente.getNumeroCliente() << endl;
        cout << "Nombre: " << cliente.getNombre() << endl;
        cout << "Telefono: " << cliente.getTelefono() << endl;
        cout << "Email: " << cliente.getEmail() << endl;
        cout << "Direccion: " << cliente.getDireccion() << endl;
        cout << "Estado: " << (cliente.getEstado() ? "Activo" : "Inactivo") << endl;
        cout << "-------------------------------" << endl;
    } else {
        cout << "El cliente esta inactivo" << endl;
    }
}

void ClienteManager::eliminarCliente() {
    int numeroCliente, index;

    cout << "Ingrese numero de cliente que quiere eliminar: ";
    cin >> numeroCliente;

    ClienteArchivo clienteArchivo;

    index = clienteArchivo.buscar(numeroCliente);

    if (index != -1) {
        Cliente cliente = clienteArchivo.leer(index);
        bool eliminar;

        mostrar(cliente);

        cout << " Esta seguro que quiere eliminar el cliente? [1-SI] || [0-NO] ";
        cin >> eliminar;

        if (eliminar) {
            if (clienteArchivo.eliminar(numeroCliente)) {
                cout << " El cliente se elimino correctamente!" << endl;
            } else {
                cout << "El cliente no se pudo eliminar..." << endl;
            }
        } else {
            cout << "El cliente no se elimino." << endl;
        }
    } else {
        cout << "El cliente no existe..." << endl;
    }
}

void ClienteManager::modificarDireccionCliente() {
    int numeroCliente, index;
    Cliente cliente;

    cout << "Ingrese el numero de cliente que desea modificar: ";
    cin >> numeroCliente;

    ClienteArchivo clienteArchivo;
    index = clienteArchivo.buscar(numeroCliente);

    if (index != -1) {
        cliente = clienteArchivo.leer(index);
        mostrar(cliente);

        cout << " Desea modificar la direccion? [1-SI] || [0-NO]: ";
        int confirmacion;
        cin >> confirmacion;

        if (confirmacion == 1) {
            string nuevaDireccion;
            cin.ignore(); // Ignorar el salto de linea despues del entero
            cout << "Ingrese la nueva direccion: ";
            getline(cin, nuevaDireccion);

            // Modificar la direccion del cliente
            cliente.setDireccion(nuevaDireccion);

            // Guardar el registro modificado en el mismo indice
            if (clienteArchivo.guardar(index, cliente)) {
                cout << "¡La direccion se modifico correctamente!" << endl;
            } else {
                cout << "No se pudo modificar la direccion..." << endl;
            }
        } else {
            cout << "No se modifico la direccion." << endl;
        }
    } else {
        cout << "El cliente no existe." << endl;
    }
}

void ClienteManager::crearReporte() {
    // Implementar la generacion de un reporte de clientes
}

void ClienteManager::menu() {
    int opcion;

    do {
        system("cls");
        cout << "--------- MENU CLIENTES -------" << endl;
        cout << "-------------------------------" << endl;
        cout << "1- CARGAR CLIENTE" << endl;
        cout << "2- BUSCAR CLIENTE POR NUMERO" << endl;
        cout << "3- LISTAR TODOS LOS CLIENTES" << endl;
        cout << "4- MODIFICAR DIRECCION" << endl;
        cout << "5- ELIMINAR CLIENTE" << endl;
        cout << "-------------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "-------------------------------" << endl;
        cout << "Opcion: ";
        cin >> opcion;

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
                cout << "Opcion no valida. Intente nuevamente." << endl;
                break;
        }
        system("pause");

    } while (opcion != 0);
}
