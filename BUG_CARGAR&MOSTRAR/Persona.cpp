#include <iostream>
#include <string>
#include <iostream>
#include <cstdlib>
#include "Persona.h"

using namespace std;

Persona::Persona() {
    _nombre = "";
    _telefono = "";
    _email = "";
    _direccion = "";
    _estado = false;
}

Persona::Persona(std::string nombre, std::string telefono, std::string email, std::string direccion, bool estado) {
    setNombre(nombre);
    setTelefono(telefono);
    setEmail(email);
    setDireccion(direccion);
    setEstado(estado);
}

string Persona::getNombre() {
    return _nombre;
}

void Persona::setNombre(string nombre) {
    if (nombre.size() <= 19) {
        _nombre = nombre;
    } else {
        _nombre = "SIN NOMBRE";
    }
}

string Persona::getTelefono() {
    return _telefono;
}

void Persona::setTelefono(string telefono) {
    if (telefono.size() <= 19) {
        _telefono = telefono;
    } else {
        _telefono = "SIN TELEFONO";
    }
}

string Persona::getEmail() {
    return _email;
}

void Persona::setEmail(string email) {
    if (email.size() <= 29) {
        _email = email;
    } else {
        _email = "SIN EMAIL";
    }
}

string Persona::getDireccion() {
    return _direccion;
}

void Persona::setDireccion(string direccion) {
    if (direccion.size() <= 39) {
        _direccion = direccion;
    } else {
        _direccion = "SIN DIRECCION";
    }
}

bool Persona::getEstado() {
    return _estado;
}

void Persona::setEstado(bool estado) {
    _estado = estado;
}


void Persona::cargar() {
    // Ingreso del nombre
    std::cin.ignore();
    std::cout << "Ingrese nombre: ";
    std::getline(std::cin, _nombre);

    // Ingreso del telefono
    std::cout << "Ingrese telefono: ";
    std::getline(std::cin, _telefono);

    // Ingreso del email
    std::cout << "Ingrese email: ";
    std::getline(std::cin, _email);

    // Ingreso de la direccion
    std::cout << "Ingrese direccion: ";
    std::getline(std::cin, _direccion);

    _estado = true;
}

void Persona::mostrar() {
    cout << "Nombre: " << _nombre << endl;
    cout << "Telefono: " << _telefono << endl;
    cout << "Email: " << _email << endl;
    cout << "Direccion: " << _direccion << endl;
    cout << "Estado: " << (_estado ? "Activo" : "Inactivo") << endl;
}
