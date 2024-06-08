#include "MascotaArchivo.h"
using namespace std;

MascotaArchivo::MascotaArchivo(){
    _fileName = "mascotas.dat";
}

MascotaArchivo::MascotaArchivo(string filename){
    _fileName = filename;
}

bool MascotaArchivo::guardar(Mascota Mascota){

    int grabo;

    if(abrir("ab") == false){
        return false;
    }

    grabo = fwrite(&mascota, sizeof (Mascota), 1, _pFile);

    cerrar();

    return grabo;
}

///metodo para guardar el registro en la posicion especificada por el index en el archivo
bool MascotaArchivo::guardar(int index, Mascota Mascota) {
    int grabo;

    if (abrir("rb+") == false) {
        return false; //no se pudo abrir el archivo
    }

    fseek(_pFile, index * sizeof(Mascota), SEEK_SET); //mueve el puntero al indice especificado

    grabo = fwrite(&mascota, sizeof(Mascota), 1, _pFile); //escribe la mascota en la posicion del index

    cerrar(); //cierra el archivo

    return grabo; //devuelve valor booleano, si grabo o no
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

Mascota MascotaArchivo::buscar(int numeroMascota){
    int index = 0;
    Mascota mascota;

    if (abrir("rb+") == false) {
        return -1; // Error al abrir el archivo
    }

    while (fread(&mascota, sizeof(Mascota), 1, _pFile)) {
        if (mascota.getNumero() == numeroMascota) {
            cerrar();
            return index; // Se encontro la mascota, devuelve el índice
        }

        index++;
    }

    cerrar();

    return -1; // No se encontro la mascota
}

bool MascotaArchivo::eliminar(int numeroMascota) {
    int index = buscar(numeroMascota);
    if (index != -1) {
        Mascota mascota = leer(index);
        mascota.setEstado(false); // cambia el estado
        return guardar(index, mascota);
    }
    return false; // La mascota no existe
}
