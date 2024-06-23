#include "ClienteArchivo.h"
using namespace std;

ClienteArchivo::ClienteArchivo(){
    _fileName = "clientes.dat";
}

ClienteArchivo::ClienteArchivo(string filename) {
    _fileName = filename;
}

bool ClienteArchivo::guardar(Cliente cliente){
    int grabo;

    if(abrir("ab") == false){
        return false;
    }

    grabo = fwrite(&cliente, sizeof (Cliente), 1, _pFile);

    cerrar();

    return grabo;
}

bool ClienteArchivo::guardar(int index, Cliente cliente) {
    int grabo;

    if (abrir("rb+") == false) {
        return false;
    }

    fseek(_pFile, index * sizeof(Cliente), SEEK_SET);

    grabo = fwrite(&cliente, sizeof(Cliente), 1, _pFile);

    cerrar();

    return grabo;
}

Cliente ClienteArchivo::leer(int index){
    Cliente cliente;

    if(abrir("rb") == false){
        return cliente;
    }

    fseek(_pFile, index * sizeof(Cliente), SEEK_SET);

    fread(&cliente, sizeof(Cliente), 1, _pFile);

    cerrar();

    return cliente;
}

int ClienteArchivo::getCantidadRegistros(){
    if(abrir("rb") == false){
        return 0;
    }

    fseek(_pFile, 0, SEEK_END);
    int tam = ftell(_pFile);

    cerrar();

    return tam / sizeof(Cliente);
}

bool ClienteArchivo::isExist(int numeroCliente) {
    return buscar(numeroCliente) != -1;
}

int ClienteArchivo::buscar(int numeroCliente) {
    Cliente cliente;
    int index = 0;

    if (!abrir("rb")) {
        return -1;
    }

    while (fread(&cliente, sizeof(Cliente), 1, _pFile)) {
        if (cliente.getNumeroCliente() == numeroCliente) {
            cerrar();
            return index;
        }
        index++;
    }

    cerrar();
    return -1;
}

bool ClienteArchivo::eliminar(int numeroCliente) {
    int index = buscar(numeroCliente);
    if (index != -1) {
        Cliente cliente = leer(index);
        cliente.setEstado(false);
        return guardar(index, cliente);
    }
    return false;
}
