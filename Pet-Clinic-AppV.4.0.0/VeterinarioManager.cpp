#include <iostream>
#include <cstdlib>
#include <string>
#include "VeterinarioManager.h"
#include "Veterinario.h"
#include "VeterinarioArchivo.h"

using namespace std;

void VeterinarioManager::cargarVeterinario() {
    int legajo;

    VeterinarioArchivo veterinarioArchivo;

    int cantidadRegistros = veterinarioArchivo.getCantidadRegistros(); // Asignacion automatica del numero de legajo
    legajo = cantidadRegistros + 1;

    cout << "Numero de Legajo: " << legajo << endl;

    Persona persona;
    persona.cargar();

    Hora horaInicio, horaSalida;
    int hora, minuto; //segundo;

    cout << "Ingrese hora de inicio: "; ///idea: Se podria crear un metodo cargar dentro de hora como se hace con persona
    cin >> hora;
    cout << "Ingrese los minutos: ";
    cin >> minuto;
    //segundo = 00;

    horaInicio.setHora(hora);
    horaInicio.setMinuto(minuto);
    //horaInicio.setSegundo(segundo);

    cout << "Ingrese hora de salida: ";
    cin >> hora;
    cout << "Ingrese los minutos: ";
    cin >> minuto;
    //segundo = 0;

    horaSalida.setHora(hora);
    horaSalida.setMinuto(minuto);
    //horaSalida.setSegundo(segundo);

    Veterinario veterinario(legajo, persona.getNombre(), persona.getTelefono(), persona.getEmail(), persona.getDireccion(), persona.getEstado(), horaInicio, horaSalida);

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
        cout << "Horario de Inicio: " << veterinario.getHoraInicio().mostrarHora() << endl;
        cout << "Horario de Fin: " << veterinario.getHoraSalida().mostrarHora() << endl;
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

void VeterinarioManager::modificarHorario() {
    int legajo, index;
    Veterinario veterinario;

    cout << "Ingrese el legajo del veterinario que desea modificar: ";
    cin >> legajo;

    VeterinarioArchivo veterinarioArchivo;
    index = veterinarioArchivo.buscar(legajo);

    if (index != -1) {
        veterinario = veterinarioArchivo.leer(index);
        mostrar(veterinario);

        cout << "Desea modificar el horario? [1-SI] || [0-NO]: ";
        int confirmacion;
        cin >> confirmacion;

        if (confirmacion == 1) {
            Hora nuevaHoraInicio, nuevaHoraSalida;
            int hora, minuto, segundo;

            cout << "Ingrese la nueva hora de inicio (hh mm ss): ";
            cin >> hora >> minuto >> segundo;
            nuevaHoraInicio.setHora(hora);
            nuevaHoraInicio.setMinuto(minuto);
            nuevaHoraInicio.setSegundo(segundo);

            cout << "Ingrese la nueva hora de salida (hh mm ss): ";
            cin >> hora >> minuto >> segundo;
            nuevaHoraSalida.setHora(hora);
            nuevaHoraSalida.setMinuto(minuto);
            nuevaHoraSalida.setSegundo(segundo);

            veterinario.setHoraInicio(nuevaHoraInicio);
            veterinario.setHoraSalida(nuevaHoraSalida);

            if (veterinarioArchivo.guardar(index, veterinario)) {
                cout << " El horario se modifico correctamente!" << endl;
            } else {
                cout << "No se pudo modificar el horario..." << endl;
            }
        } else {
            cout << "No se modifico el horario." << endl;
        }
    } else {
        cout << "El veterinario no existe." << endl;
    }
}

void VeterinarioManager::crearReporte() {
    ///Implementar la creacion del reporte. Falta por hacer
}

void VeterinarioManager::menu() {
    int opcion;

    do {
        system("cls");
        cout << "--------- MENU VETERINARIOS -------" << endl;
        cout << "-----------------------------------" << endl;
        cout << "1- CARGAR VETERINARIO" << endl;
        cout << "2- BUSCAR VETERINARIO POR LEGAJO" << endl;
        cout << "3- LISTAR TODOS LOS VETERINARIOS" << endl;
        cout << "4- MODIFICAR HORARIO" << endl;
        cout << "5- ELIMINAR VETERINARIO" << endl;
        cout << "-----------------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "-----------------------------------" << endl;
        cout << "Opcion: ";
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
                modificarHorario();
                break;
            case 5:
                system("cls");
                eliminarVeterinario();
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
