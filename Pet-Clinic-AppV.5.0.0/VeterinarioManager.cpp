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

    VeterinarioArchivo veterinarioArchivo;

    int cantidadRegistros = veterinarioArchivo.getCantidadRegistros(); // Asignacion automatica del numero de legajo
    legajo = cantidadRegistros + 1;

    cout << "Numero de Legajo: " << legajo << endl;

    Persona persona;
    persona.cargar();

    FechaHora fechaHora = FechaHora();

    Veterinario veterinario(legajo, persona.getNombre(), persona.getTelefono(), persona.getEmail(), persona.getDireccion(), fechaHora, persona.getEstado());

    if (veterinarioArchivo.guardar(veterinario)) {
        cout << "Veterinario guardado con exito!!" << endl;
    } else {
        cout << "No se pudo guardar el veterinario :(" << endl;
    }
}
void VeterinarioManager::buscarVeterinario() {
    int index, legajo;
    Veterinario veterinario;

    cout << "Ingrese el legajo del veterinario a buscar: ";
    cin >> legajo;

    VeterinarioArchivo veterinarioArchivo;

    index = veterinarioArchivo.buscar(legajo);

    if (index >= 0) {
        veterinario = veterinarioArchivo.leer(index);
        if (veterinario.getEstado()) {
            mostrar(veterinario);
        } else {
            cout << "El veterinario esta desactivado" << endl;
        }
    } else {
        cout << "El veterinario no se encuentra :(" << endl;
    }
}

void VeterinarioManager::listarVeterinarios() {
    VeterinarioArchivo veterinarioArchivo;
    int cantidad = veterinarioArchivo.getCantidadRegistros();

    for (int i = 0; i < cantidad; i++) {
        Veterinario veterinario = veterinarioArchivo.leer(i);
        mostrar(veterinario);
    }
}

void VeterinarioManager::mostrar(Veterinario veterinario) {
    if (veterinario.getEstado()) {
        cout << "Legajo de Veterinario: " << veterinario.getLegajo() << endl;
        cout << "Nombre: " << veterinario.getNombre() << endl;
        cout << "Telefono: " << veterinario.getTelefono() << endl;
        cout << "Email: " << veterinario.getEmail() << endl;
        cout << "Direccion: " << veterinario.getDireccion() << endl;
        cout << "Fecha y Hora: " << veterinario.getFechaHora().mostrarFechaHora() << endl;
        cout << "Estado: " << (veterinario.getEstado() ? "Activo" : "Inactivo") << endl;
        cout << "-------------------------------" << endl;
    } else {
        cout << "El veterinario esta inactivo" << endl;
    }
}

void VeterinarioManager::eliminarVeterinario() {
    int legajo, index;

    cout << "Ingrese el numero de legajo del veterinario que quiere eliminar: ";
    cin >> legajo;

    VeterinarioArchivo veterinarioArchivo;

    index = veterinarioArchivo.buscar(legajo);

    if (index != -1) {
        Veterinario veterinario = veterinarioArchivo.leer(index);
        bool eliminar;

        mostrar(veterinario);

        cout << "Esta seguro que quiere eliminar el veterinario? [1-SI] || [0-NO] ";
        cin >> eliminar;

        if (eliminar) {
            if (veterinarioArchivo.eliminar(legajo)) {
                cout << "El veterinario se elimino correctamente!" << endl;
            } else {
                cout << "El veterinario no se pudo eliminar..." << endl;
            }
        } else {
            cout << "El veterinario no se elimino." << endl;
        }
    } else {
        cout << "El veterinario no existe..." << endl;
    }
}

void VeterinarioManager::modificarTelefono() {
    int legajo, index;
    Veterinario veterinario;

    cout << "Ingrese el legajo del veterinario que desea modificar: ";
    cin >> legajo;

    VeterinarioArchivo veterinarioArchivo;
    index = veterinarioArchivo.buscar(legajo);

    if (index != -1) {
        veterinario = veterinarioArchivo.leer(index);
        mostrar(veterinario);

        cout << "Desea modificar el Telefono? [1-SI] || [0-NO]: ";
        int confirmacion;
        cin >> confirmacion;

        if (confirmacion == 1) {
            string telefono;

            cout << "Ingrese el nuevo telefono: ";
            getline(cin, telefono);

            veterinario.setTelefono(telefono.c_str());

            if (veterinarioArchivo.guardar(index, veterinario)) {
                cout << " El Legajo se modifico correctamente!" << endl;
            } else {
                cout << "No se pudo modificar el legajo..." << endl;
            }
        } else {
            cout << "No se modifico el legajo." << endl;
        }
    } else {
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
                break;
        }
    } while (opcion != 0);
}
