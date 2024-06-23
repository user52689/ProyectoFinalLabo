#include <string>
#include <cstdlib>
#include <iostream>
#include "Interfaz.h"
#include "MascotaManager.h"
#include "Mascota.h"
#include "MascotaArchivo.h"
#include "ClienteArchivo.h"

using namespace std;

Mascota MascotaManager::crearMascota(){
    int especie, numeroCliente;
    Fecha fechaNacimiento;
    FechaHora fechaHoraRegistro;
    string nombre;
    bool estado = true;

    MascotaArchivo mascotaArchivo;
    ClienteArchivo clienteArchivo;

    ///asignacion del numero de mascota automatico
    int cantidadRegistros = mascotaArchivo.getCantidadRegistros();
    int numeroMascota = cantidadRegistros + 1;
    cout << "numero de mascota " << numeroMascota << endl;


    cin.ignore();
    cout << "Ingrese nombre: ";
    getline(cin, nombre);

    do {
        cout << "Ingrese el numero de la especie [1-8]: ";
        cout << "[1] Perro, [2] Gato, [3] Ave, [4] Roedor, [5] Reptil, [6] Pez, [7] Exotico [8] Otro ";
       cin >> especie;
        if(especie < 1 || especie > 8) {
            cout << "Especie Incorrecta. Debe ser un numero entre 1 y 8." << endl;
        }
    } while(especie < 1 || especie > 8);

    cout << "Ingrese la fecha de Nacimiento: " << endl;
    fechaNacimiento.cargarFecha();

    fechaHoraRegistro = FechaHora();

    while (true) {
        cout << "Ingrese el numero de cliente: ";
        cin >> numeroCliente;

        if (clienteArchivo.isExist(numeroCliente)) {
            break;
        } else {
            cout << "El numero de cliente no existe. Por favor, ingrese otro numero." <<endl;
        }
    }

    return Mascota(numeroMascota, nombre, especie, fechaNacimiento, fechaHoraRegistro, numeroCliente, estado);
}

void MascotaManager::mostrar(Mascota mascota){
    if (mascota.getEstado()){
        cout << "Numero de Mascota: " << mascota.getNumeroMascota() << endl;
        cout << "Nombre: " << mascota.getNombre();
        cout << "Especie: " << mascota.getEspecie() << endl;
        cout << "Fecha de Nacimiento: " << mascota.getAnioNacimiento().mostrarFecha() << endl;
        cout << "Numero de Cliente: " << mascota.getNumeroCliente()<< endl;
        cout << "Estado: " << (mascota.getEstado() ? "Disponible" : "No disponible") << endl;
        cout << "-------------------------------" << endl;
        cout << "-------------------------------" << endl;

    }else{
        cout<<"La mascota fue eliminada, no esta activa en el archivo."<<endl;
    }
}

void MascotaManager::cargarMascota(){
    MascotaArchivo mascotaArchivo;
    Mascota mascota;
    mascota = crearMascota();

    if(mascotaArchivo.guardar(mascota)){
        cout<< "Mascota guardada con exito!!" <<endl;
    }else{
        cout<< "No se pudo encontrar la Mascota :( " <<endl;

    }
}

void MascotaManager::buscarMascota() {
    int index, numero;
    Mascota mascota;

    cout << "Ingrese el numero de mascota a buscar: " << endl;
    cin >> numero;

    index = _mascotaArchivo.buscar(numero);

    if (index >= 0) {
        mascota = _mascotaArchivo.leer(index);
        if (mascota.getEstado()) {
            mostrar(mascota);
        } else {
            cout << "La mascota esta desactivada" << endl;
        }
    } else {
        cout << "La mascota no se encuentra :(" << endl;
    }
}

void MascotaManager::listarMascotas() {
    int cantidad = _mascotaArchivo.getCantidadRegistros();

    for (int i = 0; i < cantidad; i++) {
        Mascota mascota = _mascotaArchivo.leer(i);
        mostrar(mascota);
    }
}

void MascotaManager::eliminarMascota() {
    int numeroMascota, index;

    cout << "Ingrese numero de mascota que quiere eliminar: ";
    cin >> numeroMascota;

    index = _mascotaArchivo.buscar(numeroMascota);

    if (index != -1) {
        Mascota mascota = _mascotaArchivo.leer(index);
        bool eliminar;

        mostrar(mascota);

        cout << "¿Esta seguro que quiere eliminar la mascota? [1-SI] || [0-NO] ";
        cin >> eliminar;

        if (eliminar) {
            if (_mascotaArchivo.eliminar(numeroMascota)) {
                cout << "¡La mascota se elimino correctamente!" << endl;
            } else {
                cout << "La mascota no se pudo eliminar..." << endl;
            }
        } else {
            cout << "La mascota no se elimino." << endl;
        }
    } else {
        cout << "La mascota no existe..." << endl;
    }
}

void MascotaManager::modificarFechaNacimiento() {
    int numeroMascota, index;
    Mascota mascota;

    cout << "Ingrese el numero de mascota que desea modificar: ";
    cin >> numeroMascota;

    index = _mascotaArchivo.buscar(numeroMascota);

    if (index != -1) {
        mascota = _mascotaArchivo.leer(index);
        mostrar(mascota);

        cout << "¿Desea modificar la fecha de nacimiento? [1-SI] || [0-NO]: ";
        int confirmacion;
        cin >> confirmacion;

        if (confirmacion == 1) {
            Fecha nuevaFecha;
            cout << "Ingrese la nueva fecha de nacimiento:" << endl;
            nuevaFecha.cargarFecha();

            // Modificar la fecha de nacimiento de la mascota
            mascota.setAnioNacimiento(nuevaFecha);

            // Eliminar el registro antiguo
            _mascotaArchivo.eliminar(numeroMascota);

            // Sobreescribir el registro con la nueva fecha
            _mascotaArchivo.guardar(index, mascota);

            cout << "¡La fecha de nacimiento se modifico correctamente!" << endl;
        } else {
            cout << "No se modifico la fecha de nacimiento." << endl;
        }
    } else {
        cout << "La mascota no existe." << endl;
    }
}

void MascotaManager::menu() {
    int opcion;
    Interfaz interfaz;

    do {
        system("cls");
        interfaz.mostrarTitulo();
        interfaz.moverCursor(30, 15);
        cout << "--------- MENU MASCOTAS -------" << endl;
        interfaz.moverCursor(30, 16);
        cout << "-------------------------------" << endl;
        interfaz.moverCursor(30, 17);
        cout << "1- CARGAR MASCOTA" << endl;
        interfaz.moverCursor(30, 18);
        cout << "2- BUSCAR MASCOTA POR NUMERO" << endl;
        interfaz.moverCursor(30, 19);
        cout << "3- LISTAR TODAS LAS MASCOTAS" << endl;
        interfaz.moverCursor(30, 20);
        cout << "4- MODIFICAR FECHA DE NACIMIENTO" << endl;
        interfaz.moverCursor(30, 21);
        cout << "5- ELIMINAR MASCOTA" << endl;
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
                cargarMascota();
                break;
            case 2:
                system("cls");
                buscarMascota();
                break;
            case 3:
                system("cls");
                listarMascotas();
                break;
            case 4:
                system("cls");
                modificarFechaNacimiento();
                break;
            case 5:
                system("cls");
                eliminarMascota();
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
