#include <iostream>
#include "Interfaz.h"
#include "Reporte.h"
#include "ReporteManager.h"
#include "ReporteArchivo.h"
#include "AppManager.h"

using namespace std;

void ReporteManager::menuReporte(){
    Interfaz interfaz;
    AppManager app;
    int opcion;

    do {
        system("cls");
        interfaz.mostrarTitulo();
        interfaz.moverCursor(30, 15);
        cout << "-------------- MENU REPORTES ------------" << endl;
        interfaz.moverCursor(30, 16);
        cout << "-----------------------------------------" << endl;
        interfaz.moverCursor(30, 17);
        cout << "1- TOTAL FACTURADO POR MES" << endl;
        interfaz.moverCursor(30, 18);
        cout << "2- VETERINARIO CON MAS ATENCIONES POR MES" << endl;
        interfaz.moverCursor(30, 19);
        cout << "3- DUEÑO DE CADA MASCOTA" << endl;
        cout << "-----------------------------------------" << endl;
        interfaz.moverCursor(30, 20);
        cout << "0- SALIR" << endl;
        interfaz.moverCursor(30, 21);
        cout << "-----------------------------------------" << endl;
        interfaz.moverCursor(30, 22);
        cout << "Opcion: ";
        interfaz.moverCursor(38, 23);
        cin >> opcion;

        switch (opcion) {
            case 1:
                system("cls");
                Reporte1();
                break;
            case 2:
                system("cls");
                Reporte2();
                break;
            case 3:
                system("cls");
                Reporte3();
                break;
            case 0:
                system("cls");
                app.menuPrincipal();
                break;
            default:
                system("cls");
                menuReporte();
                break;
        }
        system("pause");
    } while (opcion != 0);
}

void ReporteManager::Reporte1(){
    ///TOTAL FACTURADO POR MES
    Interfaz interfaz;
    Reporte reporte = Reporte("Total Facturado-> ");
    ReporteArchivo archReporte;
    int mes;

    interfaz.mostrarTitulo();
    interfaz.moverCursor(30, 15);
    cout << "-------------  REPORTES  1 ----------" << endl;
    interfaz.moverCursor(30, 16);
    cout << "-------TOTAL FACTURADO MENSUAL-------" << endl;
    interfaz.moverCursor(30, 17);
    cout << "-------------------------------------" << endl;
    interfaz.moverCursor(30, 18);
    cout << "Ingrese el mes que quiere consultar: ";
    cin>>mes;
    interfaz.moverCursor(30, 19);
    cout<<reporte.getNombre()<< " || Mes: " << mes <<" || $"<<archReporte.totalFacturadoMensual(mes);
}
void ReporteManager::Reporte2(){
    ///NOMBRE VETERINARIO CON MAS ATENCIONES POR MES
    Interfaz interfaz;
    Veterinario veterinario;
    Veterinario *pVeterinario = nullptr;
    int *cantidadConsultasPorVeterinario = nullptr;
    VeterinarioArchivo archVeterinario;
    Consultas turno;
    ConsultasArchivo archTurno;
    int cantidadRegistrosVeterinarios;
    int cantidadRegistrosTurnos;

    interfaz.mostrarTitulo();
    interfaz.moverCursor(30, 15);
    cout << "----------------  REPORTES  2 -------------" << endl;
    interfaz.moverCursor(30, 16);
    cout << "-------VETERINARIO CON MAS CONSULTAS-------" << endl;
    interfaz.moverCursor(30, 17);
    cout << "-------------------------------------------" << endl;
    interfaz.moverCursor(30, 18);

    cantidadRegistrosTurnos = archTurno.getCantidadRegistros();
    cantidadRegistrosVeterinarios = archVeterinario.getCantidadRegistros();

    pVeterinario = new Veterinario[cantidadRegistrosVeterinarios];
    cantidadConsultasPorVeterinario = new int[cantidadRegistrosVeterinarios];

    if( pVeterinario == nullptr || cantidadConsultasPorVeterinario == nullptr){
        return;
    }

    for(int i=0; i<cantidadRegistrosVeterinarios ; i++){///Almacena los veterinarios en el vector dinamico, y cuenta la cantidad de consultas por cada uno.
        veterinario = archVeterinario.leer(i);
        pVeterinario[i]=veterinario;

        for(int j=0; j<cantidadRegistrosTurnos ; j++){
            turno = archTurno.leer(j);

            if(turno.getLegajoVeterinarioAsignado() == veterinario.getLegajo() && turno.getEstado() && veterinario.getEstado()){
                cantidadConsultasPorVeterinario[i]++;
            }
        }
    }

    int maxConsultas = -1;
    int indexVeterinarioMax = -1;

    for (int i = 0; i < cantidadRegistrosVeterinarios; i++) {///Algoritmo de busqueda del mayor
        if (cantidadConsultasPorVeterinario[i] > maxConsultas) {
            maxConsultas = cantidadConsultasPorVeterinario[i];
            indexVeterinarioMax = i;
        }
    }
    interfaz.moverCursor(30, 19);
    cout<<"El veterinario con más consultas es: "<< pVeterinario[indexVeterinarioMax].getNombre()<<" || Cantidad consultas: "<<maxConsultas<<endl;

    delete pVeterinario;
    delete cantidadConsultasPorVeterinario;

}
void ReporteManager::Reporte3(){
    ///DUEÑO DE CADA MASCOTA
    Interfaz interfaz;
    Mascota mascota;
    MascotaArchivo archMascota;
    int cantidadRegistrosMascotas;
    Cliente cliente;
    ClienteArchivo archCliente;
    int cantidadRegistrosClientes;


    interfaz.mostrarTitulo();
    interfaz.moverCursor(30, 15);

    cout << "------------  REPORTES  3 ----------" << endl;
    interfaz.moverCursor(30, 16);
    cout << "------- DUEÑO DE CADA MASCOTA-------" << endl;
    interfaz.moverCursor(30, 17);

    cantidadRegistrosClientes = archCliente.getCantidadRegistros();
    cantidadRegistrosMascotas = archMascota.getCantidadRegistros();

    interfaz.moverCursor(30, 18);
    for(int i=0; i <cantidadRegistrosMascotas; i++){
        mascota = archMascota.leer(i);
        for(int j=0;j<cantidadRegistrosClientes; j++){
            cliente = archCliente.leer(j);
            if(mascota.getNumeroCliente() == cliente.getNumeroCliente() && mascota.getEstado() && cliente.getEstado()){
                cout<<"Mascota: "<<mascota.getNombre()<<" -> Dueño: "<<cliente.getNombre()<<endl;
            }
        }
    }
}

