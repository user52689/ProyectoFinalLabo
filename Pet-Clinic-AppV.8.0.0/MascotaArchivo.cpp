#include "MascotaArchivo.h"
using namespace std;

MascotaArchivo::MascotaArchivo(){
    _fileName = "mascotas.dat";
}

MascotaArchivo::MascotaArchivo(string filename){
    _fileName = filename;
}

bool MascotaArchivo::guardar(Mascota mascota){

    int grabo;

    if(abrir("ab") == false){
        return false;
    }

    grabo = fwrite(&mascota, sizeof (Mascota), 1, _pFile);

    cerrar();

    return grabo;
}

bool MascotaArchivo::guardar(int index, Mascota mascota) {
    int grabo;

    if (abrir("rb+") == false) {
        return false;
    }

    fseek(_pFile, index * sizeof(Mascota), SEEK_SET);

    grabo = fwrite(&mascota, sizeof(Mascota), 1, _pFile);

    cerrar();

    return grabo;
}

Mascota MascotaArchivo::leer(int index){
    Mascota mascota;

    if(abrir("rb") == false){
        return mascota;
    }

    fseek(_pFile, index * sizeof(Mascota), SEEK_SET);

    fread(&mascota, sizeof(Mascota), 1, _pFile);

    cerrar();

    return mascota;
}

int MascotaArchivo::getCantidadRegistros(){

    if(abrir("rb") == false){
        return 0;
    }

    fseek(_pFile, 0, SEEK_END);
    int tam = ftell(_pFile);

    cerrar();

    return tam / sizeof(Mascota);

}

bool MascotaArchivo::isExist(int numeroMascota){
    return buscar(numeroMascota) != -1;
}

int MascotaArchivo::buscar(int numeroMascota){
    int index = 0;
    Mascota mascota;

    if (abrir("rb+") == false) {
        return -1;
    }

    while (fread(&mascota, sizeof(Mascota), 1, _pFile)) {
        if (mascota.getNumeroMascota() == numeroMascota) {
            cerrar();
            return index;
        }

        index++;
    }

    cerrar();

    return -1;
}

bool MascotaArchivo::eliminar(int numeroMascota) {
    int index = buscar(numeroMascota);
    if (index != -1) {
        Mascota mascota = leer(index);
        mascota.setEstado(false);
        return guardar(index, mascota);
    }
    return false;
}
