#include <string>
#include <iostream>
#include <cstring>
#include "AppManager.h"
#include "Interfaz.h"
#include "Configuracion.h"

using namespace std;

void AppManager::menuPrincipal(){
    int opcion;
    Interfaz interfaz;
    interfaz.mostrarTitulo();

    interfaz.establecerColorFondo(9);
    interfaz.establecerColorTexto(15);
    do{
            system("cls");
            interfaz.mostrarTitulo();
            interfaz.moverCursor(30, 15);
            cout << "-------- MENU PRINCIPAL --------" << endl;
            interfaz.moverCursor(30, 16);
            cout << "--------------------------------" << endl;
            interfaz.moverCursor(30, 17);
            cout << "1- MENU CLIENTES  " << endl;
            interfaz.moverCursor(30, 18);
            cout << "2- MENU MASCOTAS  " << endl;
            interfaz.moverCursor(30, 19);
            cout << "3- MENU VETERINARIOS " << endl;
            interfaz.moverCursor(30, 20);
            cout << "4- MENU TURNOS " << endl;
            interfaz.moverCursor(30, 21);
            cout << "5- MENU CONFIGURACION " << endl;
            interfaz.moverCursor(30, 22);
            cout << "--------------------------------" << endl;
            interfaz.moverCursor(30, 23);
            cout << "0- SALIR " << endl;            interfaz.moverCursor(30, 24);
            cout << "--------------------------------" << endl;
            interfaz.moverCursor(30, 25);
            cout << "Opcion: " << endl;
            interfaz.moverCursor(38, 25);
            cin >> opcion;

            switch(opcion){
            case 1:
                system("cls");
                clienteManager.menu();
                break;
            case 2:
                system("cls");
                mascotaManager.menu();
                break;
            case 3:
                system("cls");
                veterinarioManager.menu();
                break;
            case 4:
                system("cls");
                consultasManager.menu();
                break;
            case 5:
                system("cls");
                menuConfiguracion();
                break;
            case 0:
                system("cls");
                interfaz.mostrarTitulo();
                interfaz.moverCursor(45, 20);
                cout << "Gracias por utilizar la aplicacion!" << endl;
                break;
            default:
                system("cls");
                break;
            }
    }while(opcion != 0);

}

void AppManager::menuConfiguracion(){
    int opcion;
    Configuracion configuracion;
    Interfaz interfaz;

    interfaz.mostrarTitulo();

    do{
        interfaz.mostrarTitulo();
        interfaz.moverCursor(30, 15);
        cout << "--------- MENU CONFIGURACION -------" << endl;
        interfaz.moverCursor(30, 16);
        cout << "------------------------------------" << endl;
        interfaz.moverCursor(30, 17);
        cout << " |1| REALIZAR BACKUP MASCOTA" << endl;
        interfaz.moverCursor(30, 18);
        cout << " |2| LISTAR BACKUP MASCOTA" << endl;
        interfaz.moverCursor(30, 19);
        cout << " |3| RESTAURAR BACKUP MASCOTA" << endl;
        interfaz.moverCursor(30, 20);
        cout << " |4| REALIZAR BACKUP CLIENTE" << endl;
        interfaz.moverCursor(30, 21);
        cout << " |5| LISTAR BACKUP CLIENTE" << endl;
        interfaz.moverCursor(30, 22);
        cout << " |6| RESTAURAR BACKUP CLIENTE" << endl;
        interfaz.moverCursor(30, 23);
        cout << " |7| REALIZAR BACKUP VETERINARIO" << endl;
        interfaz.moverCursor(30, 24);
        cout << " |8| LISTAR BACKUP VETERINARIO" << endl;
        interfaz.moverCursor(30, 25);
        cout << " |9| RESTAURAR BACKUP VETERINARIO" << endl;
        interfaz.moverCursor(30, 26);
        cout << " |10| REALIZAR BACKUP CONSULTAS" << endl;
        interfaz.moverCursor(30, 27);
        cout << " |11| LISTAR BACKUP CONSULTAS" << endl;
        interfaz.moverCursor(30, 28);
        cout << " |12| RESTAURAR BACKUP CONSULTAS" << endl;
        interfaz.moverCursor(30, 29);
        cout << "-------------------------------" << endl;
        interfaz.moverCursor(30, 30);
        cout << "0- SALIR " << endl;
        interfaz.moverCursor(30, 31);
        cout << "-------------------------------" << endl;
        interfaz.moverCursor(30, 32);
        cout << "Opcion: " << endl;
        interfaz.moverCursor(38, 33);
        cin >> opcion;

        switch(opcion){
        case 1:
            system("cls");
            configuracion.copiaSeguridadMascotaBK();
            break;
        case 2:
            system("cls");
            configuracion.listarCopiaSeguridadMascotaBK();
            break;
        case 3:
            system("cls");
            configuracion.restaurarArchivoMascotaBK();
            break;
        case 4:
            system("cls");
            configuracion.copiaSeguridadClienteBK();
            break;
        case 5:
            system("cls");
            configuracion.listarCopiaSeguridadClienteBK();
            break;
        case 6:
            system("cls");
            configuracion.restaurarArchivoClienteBK();
            break;
        case 7:
            system("cls");
            configuracion.copiaSeguridadVeterinarioBK();
            break;
        case 8:
            system("cls");
            configuracion.listarCopiaSeguridadVeterinarioBK();
            break;
        case 9:
            system("cls");
            configuracion.restaurarArchivoVeterinarioBK();
            break;
        case 10:
            system("cls");
            configuracion.copiaSeguridadConsultaBK();
            break;
        case 11:
            system("cls");
            configuracion.listarCopiaSeguridadConsultaBK();
            break;
        case 12:
            system("cls");
            configuracion.restaurarArchivoConsultaBK();
            break;
        case 0:
            system("cls");
            menuPrincipal();
        default:
            system("cls");
            interfaz.mostrarTitulo();
            interfaz.moverCursor(45, 20);
            cout << "Opcion no valida. Intente nuevamente." << endl;
            break;
        }
        system("pause");
    }while(opcion!=0);
}
