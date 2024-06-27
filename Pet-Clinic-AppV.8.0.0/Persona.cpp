#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include "Interfaz.h"
#include "Persona.h"
#include "Funciones.h"

using namespace std;

Persona::Persona() {
    setNombre("");
    setTelefono("");
    setEmail("");
    setDireccion("");
    setEstado(false);
}

Persona::Persona(string nombre, string telefono, string email, string direccion, bool estado) {
    setNombre(nombre);
    setTelefono(telefono);
    setEmail(email);
    setDireccion(direccion);
    setEstado(estado);
}

const char* Persona::getNombre() {
    return _nombre;
}
void Persona::setNombre(string nombre) {
    if (nombre.size() <= 19) {
        strcpy(_nombre, nombre.c_str());
    } else {
        setNombre("SIN NOMBRE");
    }
}
const char* Persona::getTelefono() {
    return _telefono;
}
void Persona::setTelefono(string telefono) {
    if (telefono.size() <= 19) {
        strcpy(_telefono, telefono.c_str());
    } else {
        setTelefono("SIN TELEFONO");
    }
}
const char* Persona::getEmail() {
    return _email;
}
void Persona::setEmail(string email) {
    if (email.size() <= 29) {
        strcpy(_email, email.c_str());
    } else {
        setEmail("SIN EMAIL");
    }
}
const char* Persona::getDireccion() {
    return _direccion;
}
void Persona::setDireccion(string direccion) {
    if (direccion.size() <= 39) {
        strcpy(_direccion, direccion.c_str());
    } else {
        setDireccion("SIN DIRECCION");
    }
}
bool Persona::getEstado() {
    return _estado;
}
void Persona::setEstado(bool estado) {
    _estado = estado;
}


void Persona::cargar() {
    string nombre, telefono, email, direccion;
    Interfaz interfaz;

    cin.ignore();
    interfaz.mostrarTitulo();
    interfaz.moverCursor(30, 16);
    cout << "Ingrese nombre: ";
    getline(cin, nombre);
    setNombre(nombre);

    interfaz.moverCursor(30, 17);
    cout << "Ingrese telefono: ";
    getline(cin, telefono);
    setTelefono(telefono);

    interfaz.moverCursor(30, 18);
    cout << "Ingrese email: ";
    getline(cin, email);
    setEmail(email);
    interfaz.moverCursor(30, 19);
    cout << "Ingrese direccion: ";
    getline(cin, direccion);
    setDireccion(direccion);

    _estado = true;
}

void Persona::mostrar() {
    Interfaz interfaz;

    interfaz.mostrarTitulo();
    interfaz.moverCursor(30, 16);
    cout<<"Nombre: " << _nombre << endl;
    interfaz.moverCursor(30, 17);
    cout<<"Telefono: " << _telefono << endl;
    interfaz.moverCursor(30, 18);
    cout<<"Email: " << _email << endl;
    interfaz.moverCursor(30, 19);
    cout<<"Direccion: " << _direccion << endl;
    interfaz.moverCursor(30, 20);
    cout<<"Estado: " << (_estado ? "Activo" : "Inactivo") << endl;
}
