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
    Interfaz interfaz;
    int X=30;

    int especie, numeroCliente;
    Fecha fechaNacimiento;
    FechaHora fechaHoraRegistro;
    string nombre;
    bool estado = true;

    MascotaArchivo mascotaArchivo;
    ClienteArchivo clienteArchivo;

    ///asignacion del numero de mascota automatico
    interfaz.mostrarTitulo();
    interfaz.moverCursor(X, 16);
    int cantidadRegistros = mascotaArchivo.getCantidadRegistros();
    int numeroMascota = cantidadRegistros + 1;
    cout << "Numero de mascota " << numeroMascota << endl;


    cin.ignore();
    interfaz.moverCursor(X, 17);
    cout << "Ingrese nombre: ";
    getline(cin, nombre);

    do {
        interfaz.moverCursor(X, 19);
        cout << "[1] Perro   [2] Gato [3] Ave,    [4] Roedor "<< endl;
        interfaz.moverCursor(X, 20);
        cout << "[5] Reptil  [6] Pez  [7] Exotico [8] Otro "<< endl;
        interfaz.moverCursor(X, 21);
        cout << "Ingrese el numero de la especie: ";
        interfaz.moverCursor(63, 21);
        cin >> especie;
        if(especie < 1 || especie > 8) {
            interfaz.moverCursor(X, 18);
            interfaz.establecerColorTexto(4);
            cout << "Especie Incorrecta. Debe ser un numero entre 1 y 8." << endl;
            interfaz.establecerColorTexto(15);
        }
    } while(especie < 1 || especie > 8);
        interfaz.moverCursor(X, 22);

    cout << "Ingrese la fecha de Nacimiento: " << endl;
    interfaz.moverCursor(X, 23);
    fechaNacimiento.cargarFecha();

    fechaHoraRegistro = FechaHora();

    while (true) {
        interfaz.moverCursor(30, 26);                                                 ///Falta acomodar la linea en la que aparece por pantalla 57 - 64
        cout << "Ingrese el numero de cliente: ";
        interfaz.moverCursor(60, 26);
        cin >> numeroCliente;

        if (clienteArchivo.isExist(numeroCliente)) {
            break;
        } else {
            interfaz.moverCursor(30, 27);
            interfaz.establecerColorTexto(4);
            cout << "El cliente no esta registrado." <<endl;
            interfaz.establecerColorTexto(15);
        }
    }

    return Mascota(numeroMascota, nombre, especie, fechaNacimiento, fechaHoraRegistro, numeroCliente, estado);
}

void MascotaManager::mostrar(Mascota mascota){
    Interfaz interfaz;
    int posY =20;

    if (mascota.getEstado()){
        cout << endl;
        interfaz.moverCursor(1, posY++);
        interfaz.obtenerDibujoEspecie(mascota.getEspecie()); // Cambiado a imprimir directamente
        interfaz.moverCursor(16, posY);
        cout << "Num. Mascota " ;
        interfaz.moverCursor(20, posY+=2);
        cout << mascota.getNumeroMascota() ;
        interfaz.moverCursor(30, posY-=2);
        cout << "Nombre " ;
        interfaz.moverCursor(30, posY+=2);
        cout << mascota.getNombre() ;
        interfaz.moverCursor(40, posY-=2);
        cout << "F. de Nacimiento ";
        interfaz.moverCursor(40, posY+=2);
        cout << mascota.getAnioNacimiento().mostrarFecha();
        interfaz.moverCursor(60, posY-=2);
        cout << "Num. de Cliente " ;
        interfaz.moverCursor(65, posY+=2);
        cout << mascota.getNumeroCliente() ;
        interfaz.moverCursor(80, posY-=2);
        cout << "Estado ";
        interfaz.moverCursor(80, posY+=2);
        interfaz.establecerColorTexto(2);
        cout << (mascota.getEstado() ? "Disponible" : "No disponible");
        interfaz.establecerColorTexto(15);

    }else{
        interfaz.moverCursor(30, 16);
        cout<<"La mascota no esta registrada."<<endl;
    }
}

void MascotaManager::mostrar(Mascota mascota, int posY) {
    Interfaz interfaz;


    if (mascota.getEstado()){
        cout << endl;
        interfaz.moverCursor(1, posY++);
        interfaz.obtenerDibujoEspecie(mascota.getEspecie()); // Cambiado a imprimir directamente
        interfaz.moverCursor(16, posY);
        cout << "Num. Mascota " ;
        interfaz.moverCursor(20, posY+=2);
        cout << mascota.getNumeroMascota() ;
        interfaz.moverCursor(30, posY-=2);
        cout << "Nombre " ;
        interfaz.moverCursor(30, posY+=2);
        cout << mascota.getNombre() ;
        interfaz.moverCursor(40, posY-=2);
        cout << "F. de Nacimiento ";
        interfaz.moverCursor(40, posY+=2);
        cout << mascota.getAnioNacimiento().mostrarFecha();
        interfaz.moverCursor(60, posY-=2);
        cout << "Num. de Cliente " ;
        interfaz.moverCursor(65, posY+=2);
        cout << mascota.getNumeroCliente() ;
        interfaz.moverCursor(80, posY-=2);
        cout << "Estado ";
        interfaz.moverCursor(80, posY+=2);
        interfaz.establecerColorTexto(2);
        cout << (mascota.getEstado() ? "Disponible" : "No disponible");
        interfaz.establecerColorTexto(15);

    } else {
    }
}

void MascotaManager::cargarMascota(){
    Interfaz interfaz;

    MascotaArchivo mascotaArchivo;
    Mascota mascota;
    mascota = crearMascota();

    interfaz.mostrarTitulo();
    if(mascotaArchivo.guardar(mascota)){
        interfaz.moverCursor(30, 27);
        cout<< "Mascota guardada con exito!" <<endl;
    }else{
        interfaz.moverCursor(30, 27);
        cout<< "No se pudo cargar la Mascota." <<endl;

    }
}

void MascotaManager::buscarMascota(){
    Interfaz interfaz;

    int index, numero;
    Mascota mascota;

    interfaz.mostrarTitulo();
    interfaz.moverCursor(30, 16);

    cout << "Ingrese el numero de mascota a buscar: " << endl;
    interfaz.moverCursor(69, 16);
    cin >> numero;

    index = _mascotaArchivo.buscar(numero);

    if (index >= 0) {
        mascota = _mascotaArchivo.leer(index);
        if (mascota.getEstado()) {
            mostrar(mascota);
        } else {
            interfaz.moverCursor(30, 17);
            cout << "La mascota fue eliminada." << endl;
        }
    } else {
        interfaz.moverCursor(30, 17);
        cout << "La mascota no esta registrada." << endl;
    }
}

void MascotaManager::listarMascotas() {
        MascotaArchivo _mascotaArchivo;
        int cantidad = _mascotaArchivo.getCantidadRegistros();
        int posY = 3; ///posicion inicial de los regidtros

        for (int i = 0; i < cantidad; i++) {
            Mascota mascota = _mascotaArchivo.leer(i);
            mostrar(mascota, posY); /// pasar la posicion como parametro
            posY += 8; /// Ajustar la posicion para el proximo registro
        }
    }


void MascotaManager::eliminarMascota() {
    Interfaz interfaz;
    int numeroMascota, index;

    interfaz.mostrarTitulo();
    interfaz.moverCursor(30, 16);

    cout << "Ingrese numero de mascota que quiere eliminar: ";
    cin >> numeroMascota;

    index = _mascotaArchivo.buscar(numeroMascota);

    if (index != -1) {
        Mascota mascota = _mascotaArchivo.leer(index);
        bool eliminar;

        mostrar(mascota);

        interfaz.moverCursor(30, 30);
        cout << "¿Esta seguro que quiere eliminar la mascota? [1-SI] || [0-NO] ";
        cin >> eliminar;

        system("cls");

        interfaz.mostrarTitulo();
        //interfaz.moverCursor(30, 16);

        if (eliminar) {
            if (_mascotaArchivo.eliminar(numeroMascota)) {
                interfaz.moverCursor(30, 32);
                cout << "La mascota se elimino correctamente!" << endl;
            } else {
                 interfaz.moverCursor(30, 32);
                cout << "La mascota no se pudo eliminar." << endl;
            }
        } else {
             interfaz.moverCursor(30, 32);
            cout << "La mascota no se elimino." << endl;
        }
    } else {
         interfaz.moverCursor(30, 32);
        cout << "La mascota no esta registrada." << endl;
    }
}

void MascotaManager::modificarFechaNacimiento() {
    Interfaz interfaz;

    int numeroMascota, index;
    Mascota mascota;

    interfaz.mostrarTitulo();
    interfaz.moverCursor(30, 16);

    cout << "Ingrese el numero de mascota que desea modificar: ";
    cin >> numeroMascota;

    index = _mascotaArchivo.buscar(numeroMascota);


    if (index != -1) {
        mascota = _mascotaArchivo.leer(index);
        mostrar(mascota);
         interfaz.moverCursor(30, 30);

        cout << "¿Desea modificar la fecha de nacimiento? [1-SI] || [0-NO]: ";
        int confirmacion;
        cin >> confirmacion;

        system("cls");

        interfaz.mostrarTitulo();
        interfaz.moverCursor(30, 16);


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

             interfaz.moverCursor(30, 32);                                          ///Falta acomodar la linea en la que aparece por pantalla 244-251
            cout << "El cliente no esta registrado." <<endl;

             interfaz.moverCursor(30, 32);
            cout << "La fecha de nacimiento se modifico correctamente!" << endl;
        } else {
             interfaz.moverCursor(30, 32);
            cout << "No se modifico la fecha de nacimiento." << endl;
        }
    } else {
         interfaz.moverCursor(30, 32);
        cout << "La mascota no esta registrada." << endl;
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
        interfaz.moverCursor(38, 25);
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
                menu();
                break;
        }
        interfaz.capturarTecla();
    } while (opcion != 0);
}
