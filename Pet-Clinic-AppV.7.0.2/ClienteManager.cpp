#include <iostream>
#include <cstdlib>
#include <string>
#include "Interfaz.h"
#include "ClienteManager.h"
#include "Cliente.h"
#include "ClienteArchivo.h"

using namespace std;

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
        interfaz.moverCursor(38, 25);
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
                menu();
                break;
        }
        interfaz.capturarTecla();
    } while (opcion != 0);
}
void ClienteManager::cargarCliente() {
    int numeroCliente;
    Interfaz interfaz;

    ClienteArchivo clienteArchivo;

    int cantidadRegistros = clienteArchivo.getCantidadRegistros();// Asignacion automatica del numero de cliente
    numeroCliente = cantidadRegistros + 1;

    interfaz.mostrarTitulo();
    interfaz.moverCursor(30, 15);

    cout << "Numero de Cliente: " << numeroCliente << endl;

    Persona persona;
    persona.cargar();

    Cliente cliente(numeroCliente, persona.getNombre(), persona.getTelefono(), persona.getEmail(), persona.getDireccion(), persona.getEstado());


    if (clienteArchivo.guardar(cliente)) {
        interfaz.moverCursor(30, 23);
        cout << "Cliente guardado con exito!!" << endl;
    } else {
        interfaz.moverCursor(30, 23);
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
    int posY = 3;

    for (int i = 0; i < cantidad; i++) {
        Cliente cliente = clienteArchivo.leer(i);
        mostrar(cliente, posY);
        posY += 8;
    }
}

void ClienteManager::mostrar(Cliente cliente, int posY) {
    Interfaz interfaz;
    if (cliente.getEstado()) {
        interfaz.moverCursor(1, posY++);
        interfaz.interfazCliente();
        interfaz.moverCursor(14, posY);
        cout << "N. Cliente";
        interfaz.moverCursor(18, posY+=2);
        cout << cliente.getNumeroCliente() << endl;
        interfaz.moverCursor(28, posY-=2);
        cout << "Nombre";
        interfaz.moverCursor(25, posY+=2);
        cout << cliente.getNombre() << endl;
        interfaz.moverCursor(40, posY-=2);
        cout << "Telefono";
        interfaz.moverCursor(40, posY+=2);
        cout << cliente.getTelefono() << endl;
        interfaz.moverCursor(57, posY-=2);
        cout << "Email";
        interfaz.moverCursor(53, posY+=2);
        cout << cliente.getEmail() << endl;
        interfaz.moverCursor(80, posY-=2);
        cout << "Direccion";
        interfaz.moverCursor(77, posY+=2);
        cout << cliente.getDireccion() << endl;
        interfaz.moverCursor(95, posY-=2);
        cout << "Estado";
        interfaz.moverCursor(95, posY+=2);
        cout << (cliente.getEstado() ? "Activo" : "Inactivo") << endl;

    } else {
    }
}
/*
void ClienteManager::mostrar(Cliente cliente) {
    Interfaz interfaz;
    if (cliente.getEstado()) {
        interfaz.mostrarTitulo();
        interfaz.moverCursor(30, 15);
        cout << "Numero de Cliente: " << cliente.getNumeroCliente() << endl;
        interfaz.moverCursor(30, 16);
        cout << "Nombre: " << cliente.getNombre() << endl;
        interfaz.moverCursor(30, 17);
        cout << "Telefono: " << cliente.getTelefono() << endl;
        interfaz.moverCursor(30, 18);
        cout << "Email: " << cliente.getEmail() << endl;
        interfaz.moverCursor(30, 19);
        cout << "Direccion: " << cliente.getDireccion() << endl;
        interfaz.moverCursor(30, 20);
        cout << "Estado: " << (cliente.getEstado() ? "Activo" : "Inactivo") << endl;
        interfaz.moverCursor(30, 21);
        interfaz.interfazCliente();

    } else {
        interfaz.mostrarTitulo();
        interfaz.moverCursor(30, 15);
        cout << "El cliente esta inactivo" << endl;
        system("pause");
    }
}
*/
void ClienteManager::mostrar(Cliente cliente) {
    Interfaz interfaz;
    int posY =20;
    if (cliente.getEstado()) {
        interfaz.mostrarTitulo();
        interfaz.moverCursor(1, posY++);
        interfaz.interfazCliente();
        interfaz.moverCursor(14, posY);
        cout << "N. Cliente";
        interfaz.moverCursor(18, posY+=2);
        cout << cliente.getNumeroCliente() << endl;
        interfaz.moverCursor(28, posY-=2);
        cout << "Nombre";
        interfaz.moverCursor(25, posY+=2);
        cout << cliente.getNombre() << endl;
        interfaz.moverCursor(40, posY-=2);
        cout << "Telefono";
        interfaz.moverCursor(40, posY+=2);
        cout << cliente.getTelefono() << endl;
        interfaz.moverCursor(57, posY-=2);
        cout << "Email";
        interfaz.moverCursor(53, posY+=2);
        cout << cliente.getEmail() << endl;
        interfaz.moverCursor(80, posY-=2);
        cout << "Direccion";
        interfaz.moverCursor(77, posY+=2);
        cout << cliente.getDireccion() << endl;
        interfaz.moverCursor(95, posY-=2);
        cout << "Estado";
        interfaz.moverCursor(95, posY+=2);
        cout << (cliente.getEstado() ? "Activo" : "Inactivo") << endl;

    } else {
        interfaz.mostrarTitulo();
        interfaz.moverCursor(30, posY);
        cout << "El cliente esta inactivo" << endl;
        interfaz.capturarTecla();
    }
}

void ClienteManager::eliminarCliente() {
    int numeroCliente, index;
    Interfaz interfaz;

    cout << "Ingrese numero de cliente que quiere eliminar: ";
    cin >> numeroCliente;

    ClienteArchivo clienteArchivo;

    index = clienteArchivo.buscar(numeroCliente);

    if (index != -1) {
        Cliente cliente = clienteArchivo.leer(index);
        bool eliminar;

        mostrar(cliente);

        interfaz.moverCursor(30, 28);
        cout << " Esta seguro que quiere eliminar el cliente? [1-SI] || [0-NO] ";
        cin >> eliminar;

        if (eliminar) {
            if (clienteArchivo.eliminar(numeroCliente)) {
                interfaz.moverCursor(30, 30);
                cout << " El cliente se elimino correctamente!" << endl;
            } else {
                interfaz.moverCursor(30, 30);
                cout << "El cliente no se pudo eliminar..." << endl;
            }
        } else {
            interfaz.moverCursor(30, 30);
            cout << "El cliente no se elimino." << endl;
        }
    } else {
        interfaz.moverCursor(30, 30);
        cout << "El cliente no existe..." << endl;
    }
}

void ClienteManager::modificarDireccionCliente() {
    Interfaz interfaz;
    int numeroCliente, index;
    Cliente cliente;

    cout << "Ingrese el numero de cliente que desea modificar: ";
    cin >> numeroCliente;

    ClienteArchivo clienteArchivo;
    index = clienteArchivo.buscar(numeroCliente);

    if (index != -1) {
        cliente = clienteArchivo.leer(index);
        mostrar(cliente);

        interfaz.moverCursor(30, 28);
        cout << " Desea modificar la direccion? [1-SI] || [0-NO]: ";
        int confirmacion;
        cin >> confirmacion;

        if (confirmacion == 1) {
            string nuevaDireccion;
            cin.ignore();
            interfaz.moverCursor(30, 29);
            cout << "Ingrese la nueva direccion: ";
            getline(cin, nuevaDireccion);

            cliente.setDireccion(nuevaDireccion);

            if (clienteArchivo.guardar(index, cliente)) {
                interfaz.moverCursor(30, 30);
                cout << "¡La direccion se modifico correctamente!" << endl;
            } else {
                interfaz.moverCursor(30, 30);
                cout << "No se pudo modificar la direccion..." << endl;
            }

        } else {
            interfaz.moverCursor(30, 30);
            cout << "No se modifico la direccion." << endl;
        }
    } else {
        interfaz.moverCursor(30, 30);
        cout << "El cliente no existe." << endl;
    }
}
