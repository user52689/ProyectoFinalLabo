#include <iostream>
#include "Interfaz.h"
#include "ConsultasManager.h"
#include "ConsultasArchivo.h"

using namespace std;

void ConsultasManager::menu(){
    Interfaz interfaz;

    int opcion;

    do {
        system("cls");
        interfaz.mostrarTitulo();
        interfaz.moverCursor(30, 15);
        cout << "--------- MENU TURNOS --------" << endl;
        interfaz.moverCursor(30, 16);
        cout << "------------------------------" << endl;
        interfaz.moverCursor(30, 17);
        cout << "1- CARGAR TURNO" << endl;
        interfaz.moverCursor(30, 18);
        cout << "2- BUSCAR TURNO" << endl;
        interfaz.moverCursor(30, 19);
        cout << "3- LISTAR TODOS LOS TURNOS" << endl;
        interfaz.moverCursor(30, 20);
        cout << "4- MODIFICAR VETERINARIO" << endl;
        interfaz.moverCursor(30, 21);
        cout << "5- ELIMINAR TURNO " << endl;
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
                cargarTurno();
                break;
            case 2:
                system("cls");
                buscarTurno();
                break;
            case 3:
                system("cls");
                listarTurnos();
                break;
            case 4:
                system("cls");
                modificarVeterinarioAsignado();
                break;
            case 5:
                system("cls");
                eliminarTurno();
                break;
            case 0:
                system("cls");
                break;
            default:
                system("cls");
                menu();
                break;
        }
        system("pause");
    } while (opcion != 0);
}
void ConsultasManager::mostrar(Consultas turno){
    Interfaz interfaz;

    interfaz.mostrarTitulo();

    if (turno.getEstado()) {
        interfaz.moverCursor(30, 16);
        cout << "Numero de turno: " << turno.getNumeroTurno() << endl;
        interfaz.moverCursor(30, 17);
        cout << "Fecha y Hora de Turno: " << turno.getFechaHora().mostrarFechaHora() << endl;
        interfaz.moverCursor(30, 18);        cout << "Legajo veterinario asignado: " << turno.getLegajoVeterinarioAsignado() << endl;
        interfaz.moverCursor(30, 19);
        cout << "Numero mascota: " << turno.getMascotaInvolucrada() << endl;
        interfaz.moverCursor(30, 20);        cout << "Diagnostico y tratamiento: " << turno.getDiagnosticoTratamiento() << endl;
        interfaz.moverCursor(30, 21);
        cout << "Importe: " << turno.getImporte() << endl;
        interfaz.moverCursor(30, 22);
        cout << "Estado: " << (turno.getEstado() ? "Activo" : "Inactivo") << endl;
        interfaz.moverCursor(30, 23);
        cout << "-------------------------------" << endl;
    } else {
        interfaz.moverCursor(30, 16);
        cout << "El cliente no esta registrado." << endl;
    }
}
void ConsultasManager::buscarTurno(){
    Interfaz interfaz;

    int index, numero;
    Consultas turno;

    interfaz.mostrarTitulo();

    cout << "Ingrese el numero de turno a buscar: ";
    cin >> numero;

    ConsultasArchivo turnoArchivo;

    index = turnoArchivo.buscar(numero);

    if (index >= 0) {
        turno = turnoArchivo.leer(index);
        if (turno.getEstado()) {
            mostrar(turno);
        } else {
            cout << "El turno fue eliminado" << endl;
        }
    } else {
        cout << "El turno no se encuentra." << endl;
    }
}
void ConsultasManager::cargarTurno(){
    Interfaz interfaz;

    int numeroTurno;
    FechaHora fechaHoraTurno;
    int legajoVeterinarioAsignado;
    int mascotaInvolucrada;
    string diagnosticoTratamiento;
    float importe;
    bool estado = true;

    interfaz.mostrarTitulo();
    int X=30;

    Consultas turno;
    ConsultasArchivo turnoArchivo;

    int cantidadRegistros = turnoArchivo.getCantidadRegistros();// Asignacion automatica del numero de cliente
    numeroTurno = cantidadRegistros + 1;

    interfaz.moverCursor(X, 16);
    cout << "Numero de Turno: " << numeroTurno << endl;
    turno.setNumeroTurno(numeroTurno);

    interfaz.moverCursor(X, 16);
    cout << "Fecha del Turno: "<< endl;
    fechaHoraTurno.cargarFechaHora();
    turno.setFechaHora(fechaHoraTurno);

    cout<<"Legajo veterinario asignado: ";
    cin>>legajoVeterinarioAsignado;
    turno.setLegajoVeterinarioAsignado(legajoVeterinarioAsignado);

    cout<<"Numero de mascota: ";
    cin>>mascotaInvolucrada;
    turno.setMascotaInvolucrada(mascotaInvolucrada);

    cin.ignore();
    cout<<"Diagnostico y tratamiento: ";
    getline(cin, diagnosticoTratamiento);
    turno.setDiagnosticoTratamiento(diagnosticoTratamiento.c_str());

    cout<<"Importe de consulta: ";
    cin>>importe;
    turno.setImporte(importe);



    turno.setEstado(estado);


    if (turnoArchivo.guardar(turno)) {
        cout << "Turno guardado con exito!" << endl;
    } else {
        cout << "No se pudo guardar el turno." << endl;
    }
}
void ConsultasManager::listarTurnos(){
    ConsultasArchivo turnoArchivo;
    int cantidad = turnoArchivo.getCantidadRegistros();

    for (int i = 0; i < cantidad; i++) {
        Consultas turno = turnoArchivo.leer(i);
        mostrar(turno);
    }
}
void ConsultasManager::eliminarTurno(){
    int numeroTurno, index;

    cout << "Ingrese numero de turno que quiere eliminar: ";
    cin >> numeroTurno;

    ConsultasArchivo turnoArchivo;

    index = turnoArchivo.buscar(numeroTurno);

    if (index != -1) {
        Consultas turno = turnoArchivo.leer(index);
        bool eliminar;

        mostrar(turno);

        cout << " Esta seguro que quiere eliminar el turno? [1-SI] || [0-NO] ";
        cin >> eliminar;

        if (eliminar) {
            if (turnoArchivo.eliminar(numeroTurno)) {
                cout << " El turno se elimino correctamente!" << endl;
            } else {
                cout << "El turno no se pudo eliminar..." << endl;
            }
        } else {
            cout << "El turno no se elimino." << endl;
        }
    } else {
        cout << "El turno no existe..." << endl;
    }
}
void ConsultasManager::modificarVeterinarioAsignado(){
    int numeroTurno, index;
    Consultas turno;
    ConsultasArchivo turnoArchivo;

    cout << "Ingrese el numero de turno que desea modificar: ";
    cin >> numeroTurno;

    index = turnoArchivo.buscar(numeroTurno);

    if (index != -1) {
        turno = turnoArchivo.leer(index);
        mostrar(turno);

        cout << " Desea modificar el veterinario asignado al turno? [1-SI] || [0-NO]: ";
        int confirmacion;
        cin >> confirmacion;

        if (confirmacion == 1) {
            int nuevoLegajoVeterinario;

            cout << "Ingrese el legajo del nuevo veterinario: ";
            cin>>nuevoLegajoVeterinario;

            turno.setLegajoVeterinarioAsignado(nuevoLegajoVeterinario);

            if (turnoArchivo.guardar(index, turno)) {
                cout << "�El legajo del nuevo veterinario se modifico correctamente!" << endl;
            } else {
                cout << "No se pudo modificar el legajo..." << endl;
            }

        } else {
            cout << "No se modifico el legajo." << endl;
        }
    } else {
        cout << "El turno no existe." << endl;
    }
}
