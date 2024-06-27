#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include "Interfaz.h"
#include "VeterinarioManager.h"
#include "Veterinario.h"
#include "VeterinarioArchivo.h"
#include "FechaHora.h"

using namespace std;

void VeterinarioManager::cargarVeterinario() {
    int legajo;
    Interfaz interfaz;

    VeterinarioArchivo veterinarioArchivo;

    int cantidadRegistros = veterinarioArchivo.getCantidadRegistros(); // Asignacion automatica del numero de legajo
    legajo = cantidadRegistros + 1;

    interfaz.mostrarTitulo();

    interfaz.moverCursor(30, 15);
    cout << "Numero de Legajo: " << legajo << endl;

    Persona persona;
    persona.cargar();

    FechaHora fechaHora = FechaHora();

    Veterinario veterinario(legajo, persona.getNombre(), persona.getTelefono(), persona.getEmail(), persona.getDireccion(), fechaHora, persona.getEstado());

    if (veterinarioArchivo.guardar(veterinario)) {
        interfaz.moverCursor(30, 23);
        cout << "Veterinario guardado con exito!" << endl;
    } else {
        interfaz.moverCursor(30, 23);
        cout << "No se pudo guardar el veterinario." << endl;
    }
}
void VeterinarioManager::buscarVeterinario() {
    Interfaz interfaz;

    int index, legajo;
    Veterinario veterinario;

    interfaz.mostrarTitulo();
    interfaz.moverCursor(30, 16);

    cout << "Ingrese el legajo del veterinario a buscar: ";
    cin >> legajo;

    VeterinarioArchivo veterinarioArchivo;

    index = veterinarioArchivo.buscar(legajo);

    if (index >= 0) {
        veterinario = veterinarioArchivo.leer(index);
        if (veterinario.getEstado()) {
            mostrar(veterinario);
        } else {
            interfaz.moverCursor(30, 17);
            cout << "El veterinario no esta registrado." << endl;
        }
    } else {
        interfaz.moverCursor(30, 17);
        cout << "El veterinario no se encuentra." << endl;
    }
}

void VeterinarioManager::listarVeterinarios() {
    Interfaz interfaz;

    VeterinarioArchivo veterinarioArchivo;
    int cantidad = veterinarioArchivo.getCantidadRegistros();

    interfaz.mostrarTitulo();
    interfaz.moverCursor(30, 16);

    for (int i = 0; i < cantidad; i++) {
        Veterinario veterinario = veterinarioArchivo.leer(i);
        mostrar(veterinario);
    }
}

void VeterinarioManager::mostrar(Veterinario veterinario) {
    Interfaz interfaz;

    if (veterinario.getEstado()) {
        interfaz.mostrarTitulo();
        interfaz.moverCursor(30, 16);
        cout << "Legajo de Veterinario: " << veterinario.getLegajo() << endl;
        interfaz.moverCursor(30, 17);
        cout << "Nombre: " << veterinario.getNombre() << endl;
        interfaz.moverCursor(30, 18);
        cout << "Telefono: " << veterinario.getTelefono() << endl;
        interfaz.moverCursor(30, 19);
        cout << "Email: " << veterinario.getEmail() << endl;
        interfaz.moverCursor(30, 20);
        cout << "Direccion: " << veterinario.getDireccion() << endl;
        interfaz.moverCursor(30, 21);
        cout << "Fecha y Hora: " << veterinario.getFechaHora().mostrarFechaHora() << endl;
        interfaz.moverCursor(30, 22);
        cout << "Estado: " << (veterinario.getEstado() ? "Activo" : "Inactivo") << endl;
        interfaz.moverCursor(30, 23);
        cout << "-------------------------------" << endl;
    } else {
        interfaz.moverCursor(30, 16);
        cout << "El veterinario no esta registrado." << endl;
    }
}

void VeterinarioManager::eliminarVeterinario() {
    Interfaz interfaz;

    int legajo, index;

    interfaz.mostrarTitulo();
    interfaz.moverCursor(30, 16);

    cout << "Ingrese el numero de legajo del veterinario que quiere eliminar: ";
    cin >> legajo;

    VeterinarioArchivo veterinarioArchivo;

    index = veterinarioArchivo.buscar(legajo);

    if (index != -1) {
        Veterinario veterinario = veterinarioArchivo.leer(index);
        bool eliminar;

        mostrar(veterinario);

        interfaz.moverCursor(30, 17);
        cout << "Esta seguro que quiere eliminar el veterinario? [1-SI] || [0-NO] ";
        cin >> eliminar;

        if (eliminar) {
            if (veterinarioArchivo.eliminar(legajo)) {
                interfaz.moverCursor(30, 17);
                cout << "El veterinario se elimino correctamente!" << endl;
            } else {
                interfaz.moverCursor(30, 17);
                cout << "El veterinario no se pudo eliminar." << endl;
            }
        } else {
            interfaz.moverCursor(30, 17);
            cout << "El veterinario no se elimino." << endl;
        }
    } else {
        interfaz.moverCursor(30, 17);
        cout << "El veterinario no esta registrado." << endl;
    }
}

void VeterinarioManager::modificarTelefono() {
    Interfaz interfaz;

    int legajo, index;
    Veterinario veterinario;

    interfaz.mostrarTitulo();
    interfaz.moverCursor(30, 16);

    cout << "Ingrese el legajo del veterinario que desea modificar: ";
    cin >> legajo;

    VeterinarioArchivo veterinarioArchivo;
    index = veterinarioArchivo.buscar(legajo);

    if (index != -1) {
        veterinario = veterinarioArchivo.leer(index);
        mostrar(veterinario);

        interfaz.moverCursor(30, 17);
        cout << "Desea modificar el Telefono? [1-SI] || [0-NO]: ";
        int confirmacion;
        cin >> confirmacion;

        if (confirmacion == 1) {
            string telefono;
            system("cls");

            interfaz.mostrarTitulo();
            interfaz.moverCursor(30, 16);
            cout << "Ingrese el nuevo telefono: ";
            getline(cin, telefono);

            veterinario.setTelefono(telefono.c_str());

            if (veterinarioArchivo.guardar(index, veterinario)) {
                interfaz.moverCursor(30, 16);
                cout << " El Legajo se modifico correctamente!" << endl;
            } else {
                interfaz.moverCursor(30, 16);
                cout << "No se pudo modificar el legajo." << endl;
            }
        } else {
            interfaz.moverCursor(30, 16);
            cout << "No se modifico el legajo." << endl;
        }
    } else {
        interfaz.moverCursor(30, 16);
        cout << "El veterinario no existe." << endl;
    }
}

void VeterinarioManager::menu() {
    int opcion;
    Interfaz interfaz;

    do {
        system("cls");
        interfaz.mostrarTitulo();
        interfaz.moverCursor(30, 15);
        cout << "------- MENU VETERINARIOS -------" << endl;
        interfaz.moverCursor(30, 16);
        cout << "---------------------------------" << endl;
        interfaz.moverCursor(30, 17);
        cout << "1- CARGAR VETERINARIO" << endl;
        interfaz.moverCursor(30, 18);
        cout << "2- BUSCAR VETERINARIO POR LEGAJO" << endl;
        interfaz.moverCursor(30, 19);        cout << "3- LISTAR TODOS LOS VETERINARIOS" << endl;
        interfaz.moverCursor(30, 20);
        cout << "4- MODIFICAR TELEFONO" << endl;
        interfaz.moverCursor(30, 21);
        cout << "5- ELIMINAR VETERINARIO" << endl;
        interfaz.moverCursor(30, 22);
        cout << "---------------------------------" << endl;
        interfaz.moverCursor(30, 23);
        cout << "0- SALIR" << endl;
        interfaz.moverCursor(30, 24);
        cout << "---------------------------------" << endl;
        interfaz.moverCursor(30, 25);
        cout << "Opcion: ";
        interfaz.moverCursor(38, 26);
        cin >> opcion;

        switch (opcion) {
            case 1:
                system("cls");
                cargarVeterinario();
                break;
            case 2:
                system("cls");
                buscarVeterinario();
                break;
            case 3:
                system("cls");
                listarVeterinarios();
                break;
            case 4:
                system("cls");
                modificarTelefono();
                break;
            case 5:
                system("cls");
                eliminarVeterinario();
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
