#include <string>
#include <iostream>
#include <cstring>
#include "AppManager.h"

using namespace std;

void AppManager::menuPrincipal(){
    int opcion;

    do{
            system("cls");
            cout << "--------- MENU PRINCIPAL -------" << endl;
            cout << "-------------------------------" << endl;
            cout << " |1| MENU MASCOTAS  " << endl;
            cout << " |2| MENU CLIENTES  " << endl;
            cout << " |3| MENU VETERINARIOS " << endl;
            cout << " |4| MENU CONSULTAS " << endl;
            cout << " |5| MENU CONFIGURACION " << endl;
            cout << "-------------------------------" << endl;
            cout << "0- SALIR " << endl;
            cout << "-------------------------------" << endl;
            cout << "Opcion: " << endl;
            cin >> opcion;

            switch(opcion){
            case 1:
                system("cls");
                mascotaManager.menu();
                break;
            case 2:
                system("cls");
                clienteManager.menu();
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
                cout << "Gracias por utilizar la aplicacion, por parte de cobro por usarla" << endl;
                cout << "    Debera aprobar a los estudiantes que la codificaron XD " << endl;
                system("pause");
            default:
                cout<<"Ingreso incorrecto, vuelva a intentarlo.\n";
                system("pause");
                AppManager.menuConfiguracion();
            }

    }while(opcion != 0);

}
void AppManager::menuConfiguracion(){
    Configuracion configuracion;

    cout << "--------- MENU CONFIGURACION -------" << endl;
    cout << "------------------------------------" << endl;
    cout << " |1| REALIZAR BACKUP MASCOTA" << endl;
    cout << " |2| LISTAR BACKUP MASCOTA" << endl;
    cout << " |3| RESTAURAR BACKUP MASCOTA" << endl;
    cout << " |4| REALIZAR BACKUP CLIENTE" << endl;
    cout << " |5| LISTAR BACKUP CLIENTE" << endl;
    cout << " |6| RESTAURAR BACKUP CLIENTE" << endl;
    cout << " |7| REALIZAR BACKUP VETERINARIO" << endl;
    cout << " |8| LISTAR BACKUP VETERINARIO" << endl;
    cout << " |9| RESTAURAR BACKUP VETERINARIO" << endl;
    cout << " |10| REALIZAR BACKUP CONSULTAS" << endl;
    cout << " |11| LISTAR BACKUP CONSULTAS" << endl;
    cout << " |12| RESTAURAR BACKUP CONSULTAS" << endl;
    cout << "-------------------------------" << endl;
    cout << "0- SALIR " << endl;
    cout << "-------------------------------" << endl;
    cout << "Opcion: " << endl;
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
        AppManager.menuPrincipal();
    default:
        cout<<"Ingreso incorrecto, vuelva a intentarlo.\n";
        system("pause");
        AppManager.menuConfiguracion();
    }
}
