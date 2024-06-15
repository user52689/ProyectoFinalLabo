#include "ClienteArchivo.h"
using namespace std;

ClienteArchivo::ClienteArchivo(){
    _fileName = "clientes.dat"; // Inicializacion del archivo
}

ClienteArchivo::ClienteArchivo(string filename) {
    _fileName = filename; // Inicializacion del archivo con el nombre proporcionado
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

///Metodo para guardar el registro en la posicion especificada por el index en el archivo
bool ClienteArchivo::guardar(int index, Cliente cliente) {
    int grabo;

    if (abrir("rb+") == false) {
        return false; //no se pudo abrir el archivo
    }

    fseek(_pFile, index * sizeof(Cliente), SEEK_SET); //mueve el puntero al indice especificado

    grabo = fwrite(&cliente, sizeof(Cliente), 1, _pFile); //escribe el cliente en la posicion del index

    cerrar(); //cierra el archivo

    return grabo; //devuelve valor booleano, si grabo o no
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
        return -1; // Error al abrir el archivo
    }

    while (fread(&cliente, sizeof(Cliente), 1, _pFile)) {
        if (cliente.getNumeroCliente() == numeroCliente) {
            cerrar();
            return index; // Se encontro el cliente, devuelve el indice
        }
        index++;
    }

    cerrar();
    return -1; // No se encontro el cliente
}

bool ClienteArchivo::eliminar(int numeroCliente) {
    int index = buscar(numeroCliente);
    if (index != -1) {
        Cliente cliente = leer(index);
        cliente.setEstado(false); // cambia el estado
        return guardar(index, cliente);
    }
    return false; // el cliente no existe
}
