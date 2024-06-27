#include "VeterinarioArchivo.h"
using namespace std;

VeterinarioArchivo::VeterinarioArchivo() {
    _fileName = "veterinarios.dat";
}

VeterinarioArchivo::VeterinarioArchivo(string fileName) {
    _fileName = fileName;
}

bool VeterinarioArchivo::guardar(Veterinario veterinario) {
    int grabo;

    if (abrir("ab") == false) {
        return false;
    }

    grabo = fwrite(&veterinario, sizeof(Veterinario), 1, _pFile);

    cerrar();

    return grabo;
}

///Metodo para guardar el registro en la posicion especificada por el index en el archivo
bool VeterinarioArchivo::guardar(int index, Veterinario veterinario) {
    int grabo;

    if (abrir("rb+") == false) {
        return false;
    }

    fseek(_pFile, index * sizeof(Veterinario), SEEK_SET);

    grabo = fwrite(&veterinario, sizeof(Veterinario), 1, _pFile);

    cerrar();

    return grabo;
}

Veterinario VeterinarioArchivo::leer(int index) {
    Veterinario veterinario;

    if (abrir("rb") == false) {
        return veterinario;
    }

    fseek(_pFile, index * sizeof(Veterinario), SEEK_SET);

    fread(&veterinario, sizeof(Veterinario), 1, _pFile);

    cerrar();

    return veterinario;
}

int VeterinarioArchivo::getCantidadRegistros() {
    if (abrir("rb") == false) {
        return 0;
    }

    fseek(_pFile, 0, SEEK_END);
    int tam = ftell(_pFile);

    cerrar();

    return tam / sizeof(Veterinario);
}

bool VeterinarioArchivo::isExist(int legajo) {
    return buscar(legajo) != -1;
}

int VeterinarioArchivo::buscar(int legajo) {
    Veterinario veterinario;
    int index = 0;

    if (!abrir("rb")) {
        return -1;
    }

    while (fread(&veterinario, sizeof(Veterinario), 1, _pFile)) {
        if (veterinario.getLegajo() == legajo) {
            cerrar();
            return index;
        }
        index++;
    }

    cerrar();
    return -1;
}

bool VeterinarioArchivo::eliminar(int legajo) {
    int index = buscar(legajo);
    if (index != -1) {
        Veterinario veterinario = leer(index);
        veterinario.setEstado(false);
        return guardar(index, veterinario);
    }
    return false;
}
