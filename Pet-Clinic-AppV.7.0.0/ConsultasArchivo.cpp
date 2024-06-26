#include <iostream>
#include "ConsultasArchivo.h"

using namespace std;


ConsultasArchivo::ConsultasArchivo(){
    _fileName = "consultas.dat";
}

bool ConsultasArchivo::guardar(Consultas turno){
    int grabo;

    if(abrir("ab") == false){
        return false;
    }

    grabo = fwrite(&turno, sizeof (Consultas), 1, _pFile);

    cerrar();

    return grabo;
}
bool ConsultasArchivo::guardar(int index, Consultas turno){
    int grabo;

    if (abrir("rb+") == false) {
        return false;
    }

    fseek(_pFile, index * sizeof(Consultas), SEEK_SET);

    grabo = fwrite(&turno, sizeof(Consultas), 1, _pFile);

    cerrar();

    return grabo;
}
Consultas ConsultasArchivo::leer(int index){
    Consultas turno;

    if(abrir("rb") == false){
        return turno;
    }

    fseek(_pFile, index * sizeof(Consultas), SEEK_SET);

    fread(&turno, sizeof(Consultas), 1, _pFile);

    cerrar();

    return turno;
}
int ConsultasArchivo::getCantidadRegistros(){
    if(abrir("rb") == false){
        return 0;
    }

    fseek(_pFile, 0, SEEK_END);
    int tam = ftell(_pFile);

    cerrar();

    return tam / sizeof(Consultas);
}
bool ConsultasArchivo::isExist(int numeroTurno){
    return buscar(numeroTurno) != -1;
}
int ConsultasArchivo::buscar(int numeroTurno){
    Consultas turno;

    int index = 0;

    if (!abrir("rb")) {
        return -1;
    }

    while (fread(&turno, sizeof(Consultas), 1, _pFile)) {
        if (turno.getNumeroTurno() == numeroTurno) {
            cerrar();
            return index;
        }
        index++;
    }

    cerrar();
    return -1;
}
bool ConsultasArchivo::eliminar(int numeroTurno){
    int index = buscar(numeroTurno);
    if (index != -1) {
        Consultas turno = leer(index);
        turno.setEstado(false);
        return guardar(index, turno);
    }
    return false;
}
