#include <string>
#include <iostream>
#include <cstring>
#include "AppManager.h"

using namespace std;

void AppManager::menu(){
    int opcion;

    do{
            system("cls");
            cout << "--------- MENU PRINCIPAL -------" << endl;
            cout << "-------------------------------" << endl;
            cout << " |1| MENU MASCOTAS  " << endl;
            cout << " |2| MENU CLIENTES  " << endl;
            cout << " |3| MENU VETERINARIOS " << endl;
            cout << " |4| MENU CONSULTAS " << endl;
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
            case 0:
                system("cls");
                cout << "Gracias por utilizar la aplicacion, por parte de cobro por usarla" << endl;
                cout << "    Debera aprobar a los estudiantes que la codificaron XD " << endl;
                system("pause");
            }

    }while(opcion != 0);

}
