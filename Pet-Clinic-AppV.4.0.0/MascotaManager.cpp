#include <string>
#include <cstdlib>
#include <iostream>
#include "MascotaManager.h"
#include "Mascota.h"
#include "MascotaArchivo.h"
#include "ClienteArchivo.h"

using namespace std;

Mascota MascotaManager::crearMascota(){
    int especie, numeroCliente;
    Fecha fechaNacimiento;
    string nombre;
    bool estado;

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

    while (true) {
        cout << "Ingrese el numero de cliente: ";
        cin >> numeroCliente;

        if (clienteArchivo.isExist(numeroCliente)) {
            break;
        } else {
            cout << "El numero de cliente no existe. Por favor, ingrese otro numero." <<endl;
        }
    }

    return Mascota(numeroMascota, nombre, especie, fechaNacimiento, numeroCliente, true);
}

void MascotaManager::mostrar(Mascota mascota){
    ///Verifica que el estado de la mascota sea verdadero (Activo)
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

    index = mascotaArchivo.buscar(numero);

    if (index >= 0) {
        mascota = mascotaArchivo.leer(index);
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
    int cantidad = mascotaArchivo.getCantidadRegistros();

    for (int i = 0; i < cantidad; i++) {
        Mascota mascota = mascotaArchivo.leer(i);
        mostrar(mascota);
    }
}

void MascotaManager::eliminarMascota() {
    int numeroMascota, index;

    cout << "Ingrese numero de mascota que quiere eliminar: ";
    cin >> numeroMascota;

    index = mascotaArchivo.buscar(numeroMascota);

    if (index != -1) {
        Mascota mascota = mascotaArchivo.leer(index);
        bool eliminar;

        mostrar(mascota);

        cout << "¿Esta seguro que quiere eliminar la mascota? [1-SI] || [0-NO] ";
        cin >> eliminar;

        if (eliminar) {
            if (mascotaArchivo.eliminar(numeroMascota)) {
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

    index = mascotaArchivo.buscar(numeroMascota);

    if (index != -1) {
        mascota = mascotaArchivo.leer(index);
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
            mascotaArchivo.eliminar(numeroMascota);

            // Sobreescribir el registro con la nueva fecha
            mascotaArchivo.guardar(index, mascota);

            cout << "¡La fecha de nacimiento se modifico correctamente!" << endl;
        } else {
            cout << "No se modifico la fecha de nacimiento." << endl;
        }
    } else {
        cout << "La mascota no existe." << endl;
    }
}

void MascotaManager::crearReporte(){

}

void MascotaManager::menu() {
    int opcion;

    do {
        system("cls");
        cout << "--------- MENU MASCOTAS -------" << endl;
        cout << "-------------------------------" << endl;
        cout << "1- CARGAR MASCOTA" << endl;
        cout << "2- BUSCAR MASCOTA POR NUMERO" << endl;
        cout << "3- LISTAR TODAS LAS MASCOTAS" << endl;
        cout << "4- MODIFICAR FECHA DE NACIMIENTO" << endl;
        cout << "5- ELIMINAR MASCOTA" << endl;
        cout << "-------------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "-------------------------------" << endl;
        cout << "Opcion: ";
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
                cout << "OpciOn no vAlida. Intente nuevamente." << endl;
                break;
        }
        system("pause");

    } while (opcion != 0);
}
