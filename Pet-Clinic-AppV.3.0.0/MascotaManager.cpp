#include <string>
#include <cstdlib>
#include <iostream>
#include "MascotaManager.h"
#include "Mascota.h"
#include "MascotaArchivo.h"

using namespace std;

Mascota MascotaManager::crearMascota(){
    int especie, numeroCliente;
    Fecha fechaNacimiento; ///verificar en clase fecha
    std::string nombre;
    bool estado;

    MascotaArchivo mascotaArchivo; // Creacion de un objeto de la clase MascotaArchivo
    ClienteArchivo clienteArchivo; // Creacion de un objeto de la clase ClienteArchivo

    ///asignacion del numero de mascota automatico
    int cantidadRegistros = mascotaArchivo.getCantidadRegistros();
    int numeroMascota = cantidadRegistros + 1;
    std::cout << "numero de mascota " << numeroMascota << std::endl;

    ///Ingreso de nombre
    std::cin.ignore();
    std::cout << "Ingrese nombre: ";
    std::getline(std::cin, nombre);

    ///ingreso del numero de especie, con validacion
    do {
        std::cout << "Ingrese el numero de la especie [1-8]: ";
        std::cout << "[1] Perro, [2] Gato, [3] Ave, [4] Roedor, [5] Reptil, [6] Pez, [7] Exotico [8] Otro ";
        std::cin >> especie;
        if(especie < 1 || especie > 8) {
            std::cout << "Especie Incorrecta. Debe ser un numero entre 1 y 8." << std::endl;
        }
    } while(especie < 1 || especie > 8);

    ///Ingreso de la fecha de Nacimiento
    cout << "Ingrese la fecha de Nacimiento: " << endl;
    fechaNacimiento.cargar();

    while (true) {
        std::cout << "Ingrese el numero de cliente: ";
        std::cin >> numeroCliente;

        if (clienteArchivo.isExist(numeroCliente)) {
            break;
        } else {
            std::cout << "El numero de cliente no existe. Por favor, ingrese otro numero." << std::endl;
        }
    }

    return Mascota(numeroMascota, nombre, especie, fechaNacimiento, numeroCliente, true);
}

void MascotaManager::mostrar(Mascota mascota){
    ///Verifica que el estado de la mascota sea verdadero (Activo)
    if (mascota.getEstado())[
        std::cout << "Numero de Mascota: " << mascota.getNumeroMascota() << std::endl;
        std::cout << "Nombre: " << mascota.getNombre()
        std::cout << "Especie: " << mascota.getEspecie() << std::endl;
        std::cout << "Anio de Nacimiento: " << mascota.getfecha().mostrar() << std::endl;
        std::cout << "Numero de Cliente: " << mascota.getNumeroCliente<< std::endl;
        std::cout << "Estado: " << (mascota.getEstado() ? "Disponible" : "No disponible") << std::endl;
        cout << "-------------------------------" << endl;
        cout << "-------------------------------" << endl;

    ]else{

    }
}

void MascotaManager::cargarMascota(){
    Mascota mascota
    mascota = crearMascota();

    if(mascotaArchivo.guardar(mascota)){
        std::cout<< "Mascota guardada con exito!!" std::endl;
    }else{
        std::cout<< "No se pudo encontrar la Mascota :( " std::endl;

    }
}

void MascotaManager::buscarMascota() {
    int index, numero;
    Mascota mascota;

    std::cout << "Ingrese el numero de mascota a buscar: " << std::endl;
    std::cin >> numero;

    index = mascotaArchivo.buscar(numero);

    if (index >= 0) {
        mascota = mascotaArchivo.leer(index);
        if (mascota.getEstado()) {
            mostrar(mascota);
        } else {
            std::cout << "La mascota esta desactivada" << std::endl;
        }
    } else {
        std::cout << "La mascota no se encuentra :(" << std::endl;
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

    std::cout << "Ingrese numero de mascota que quiere eliminar: ";
    std::cin >> numeroMascota;

    index = mascotaArchivo.buscar(numeroMascota);

    if (index != -1) {
        Mascota mascota = mascotaArchivo.leer(index);
        bool eliminar;

        mostrar(mascota);

        std::cout << "¿Esta seguro que quiere eliminar la mascota? [1-SI] || [0-NO] ";
        std::cin >> eliminar;

        if (eliminar) {
            if (mascotaArchivo.eliminar(numeroMascota)) {
                std::cout << "¡La mascota se elimino correctamente!" << std::endl;
            } else {
                std::cout << "La mascota no se pudo eliminar..." << std::endl;
            }
        } else {
            std::cout << "La mascota no se elimino." << std::endl;
        }
    } else {
        std::cout << "La mascota no existe..." << std::endl;
    }
}

void MascotaManager::modificarFechaNacimiento() {
    int numeroMascota, index;
    Mascota mascota;

    std::cout << "Ingrese el numero de mascota que desea modificar: ";
    std::cin >> numeroMascota;

    index = mascotaArchivo.buscar(numeroMascota);

    if (index != -1) {
        mascota = mascotaArchivo.leer(index);
        mostrar(mascota);

        std::cout << "¿Desea modificar la fecha de nacimiento? [1-SI] || [0-NO]: ";
        int confirmacion;
        std::cin >> confirmacion;

        if (confirmacion == 1) {
            Fecha nuevaFecha;
            std::cout << "Ingrese la nueva fecha de nacimiento:" << std::endl;
            nuevaFecha.cargar();

            // Modificar la fecha de nacimiento de la mascota
            mascota.setAnioNacimiento(nuevaFecha);

            // Eliminar el registro antiguo
            mascotaArchivo.eliminar(numeroMascota);

            // Sobreescribir el registro con la nueva fecha
            mascotaArchivo.guardar(index, mascota);

            std::cout << "¡La fecha de nacimiento se modifico correctamente!" << std::endl;
        } else {
            std::cout << "No se modifico la fecha de nacimiento." << std::endl;
        }
    } else {
        std::cout << "La mascota no existe." << std::endl;
    }
}

void MascotaManager::crearReporte(){

}

void MascotaManager::menu() {
    int opcion;

    do {
        system("cls");
        std::cout << "--------- MENU MASCOTAS -------" << std::endl;
        std::cout << "-------------------------------" << std::endl;
        std::cout << "1- CARGAR MASCOTA" << std::endl;
        std::cout << "2- BUSCAR MASCOTA POR NUMERO" << std::endl;
        std::cout << "3- LISTAR TODAS LAS MASCOTAS" << std::endl;
        std::cout << "4- MODIFICAR FECHA DE NACIMIENTO" << std::endl;
        std::cout << "5- ELIMINAR MASCOTA" << std::endl;
        std::cout << "-------------------------------" << std::endl;
        std::cout << "0- SALIR" << std::endl;
        std::cout << "-------------------------------" << std::endl;
        std::cout << "Opcion: ";
        std::cin >> opcion;

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
                std::cout << "OpciOn no vAlida. Intente nuevamente." << std::endl;
                break;
        }
        system("pause");

    } while (opcion != 0);
}
