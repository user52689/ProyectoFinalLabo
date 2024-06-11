#include <string>
#include <iostream>
#include <cstring>
#include "AppManager.h"
#include "Interfaz.h"

using namespace std;

void AppManager::menu(){
    Interfaz interfaz;
    interfaz.mostrarTitulo();

    int opcion;

    do{
            system("cls");
            interfaz.mostrarTitulo();
            interfaz.moverCursor(35, 18);
            cout << "======== MENU PRINCIPAL ========" << endl;
            interfaz.dibujarLineaHorizontal(35, 19, 32);
            interfaz.moverCursor(40, 20);
            cout << " |1| MENU CLIENTES  " << endl;
            interfaz.moverCursor(40, 21);
            cout << " |2| MENU MASCOTAS  " << endl;
            interfaz.moverCursor(40, 22);
            cout << " |3| MENU VETERINARIOS " << endl;
            interfaz.moverCursor(40, 23);
            cout << " |4| MENU CONSULTAS " << endl;
            interfaz.dibujarLineaHorizontal(35, 24, 32);
            interfaz.moverCursor(35, 25);
            cout << "0- SALIR " << endl;
            interfaz.dibujarLineaHorizontal(35, 26, 32);
            interfaz.moverCursor(35, 27);
            cout << "Opcion: " << endl;
            interfaz.moverCursor(42, 27);
            cin >> opcion;

            switch(opcion){
            case 1:
                system("cls");
                clienteManager.menu();
                break;
            case 2:
                system("cls");
                //mascotaManager.menu();
                break;
            case 3:
                system("cls");
                //veterinarioManager.menu();
                break;
            case 4:
                system("cls");
                //consultasManager.menu();
                break;
            case 0:
                system("cls");
                cout << "Gracias por utilizar la aplicacion"<< endl;

                system("pause");
            }

    }while(opcion != 0);

}
