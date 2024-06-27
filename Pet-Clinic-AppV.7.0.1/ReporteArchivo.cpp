#include <iostream>
#include "Interfaz.h"
#include "Reporte.h"
#include "ReporteArchivo.h"
#include "Consultas.h"
#include "ConsultasArchivo.h"
#include "Veterinario.h"
#include "VeterinarioArchivo.h"
#include "Mascota.h"
#include "MascotaArchivo.h"
#include "Cliente.h"
#include "ClienteArchivo.h"

using namespace std;


float ReporteArchivo::totalFacturadoMensual(int mes){
    float total = 0;
    int cantidadRegistrosTurnos;
    Consultas turno;
    ConsultasArchivo archTurno;

    cantidadRegistrosTurnos = archTurno.getCantidadRegistros();

    for(int i=0; i<cantidadRegistrosTurnos; i++){
        turno = archTurno.leer(i);
        if(mes==turno.getFechaHora().getFecha().getMes() && turno.getEstado()){
            total += turno.getImporte();
        }
    }
    return total;
}
void ReporteArchivo::veterinarioConMasAtenciones(){
    Interfaz interfaz;
    Veterinario veterinario;
    Veterinario *pVeterinario = nullptr;
    int *cantidadConsultasPorVeterinario = nullptr;
    VeterinarioArchivo archVeterinario;
    Consultas turno;
    ConsultasArchivo archTurno;
    int cantidadRegistrosVeterinarios;
    int cantidadRegistrosTurnos;


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
void ReporteArchivo::duenioDeCadaMascota(){
    Mascota mascota;
    MascotaArchivo archMascota;
    int cantidadRegistrosMascotas;
    Cliente cliente;
    ClienteArchivo archCliente;
    int cantidadRegistrosClientes;

    cantidadRegistrosClientes = archCliente.getCantidadRegistros();
    cantidadRegistrosMascotas = archMascota.getCantidadRegistros();

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
