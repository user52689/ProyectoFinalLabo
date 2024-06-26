#include <iostream>
#include <cstdlib>
#include <string>
#include "Interfaz.h"
#include "ClienteManager.h"
#include "Cliente.h"
#include "ClienteArchivo.h"

using namespace std;

void ClienteManager::cargarCliente() {
    int numeroCliente;

    ClienteArchivo clienteArchivo;

    int cantidadRegistros = clienteArchivo.getCantidadRegistros();// Asignacion automatica del numero de cliente
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
            cin.ignore();
            cout << "Ingrese la nueva direccion: ";
            getline(cin, nuevaDireccion);

            cliente.setDireccion(nuevaDireccion);

            if (clienteArchivo.guardar(index, cliente)) {
                cout << "�La direccion se modifico correctamente!" << endl;
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
void ClienteManager::menu() {
    int opcion;
    Interfaz interfaz;

    do {
        system("cls");
        interfaz.mostrarTitulo();
        interfaz.moverCursor(30, 15);
        cout << "--------- MENU CLIENTES -------" << endl;
        interfaz.moverCursor(30, 16);
        cout << "-------------------------------" << endl;
        interfaz.moverCursor(30, 17);
        cout << "1- CARGAR CLIENTE" << endl;
        interfaz.moverCursor(30, 18);
        cout << "2- BUSCAR CLIENTE POR NUMERO" << endl;
        interfaz.moverCursor(30, 19);
        cout << "3- LISTAR TODOS LOS CLIENTES" << endl;
        interfaz.moverCursor(30, 20);
        cout << "4- MODIFICAR DIRECCION" << endl;
        interfaz.moverCursor(30, 21);
        cout << "5- ELIMINAR CLIENTE" << endl;
        interfaz.moverCursor(30, 22);
        cout << "-------------------------------" << endl;
        interfaz.moverCursor(30, 23);
        cout << "0- SALIR" << endl;
        interfaz.moverCursor(30, 24);
        cout << "-------------------------------" << endl;
        interfaz.moverCursor(30, 25);
        cout << "Opcion: ";
        interfaz.moverCursor(38, 26);
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
                system("cls");
                break;
        }
    } while (opcion != 0);
}
