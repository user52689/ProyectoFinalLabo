#include <iostream>
#include "Reporte.h"
#include "ReporteArchivo.h"
#include "Consultas.h"
#include "ConsultasArchivo.h"
#include "Veterinario.h"
#include "VeterinarioArchivo.h"
#include "Mascota.h"
#include "MascotaArchivo.h"

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

}
void ReporteArchivo::cantidadMascotasAtendidasMensual(int mes){

}
