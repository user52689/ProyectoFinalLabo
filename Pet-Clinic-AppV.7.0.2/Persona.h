#pragma once
#include <string>

class Persona {
protected:
    char _nombre[20];
    char _telefono[20];
    char _email[30];
    char _direccion[40];
    bool _estado;

public:
    Persona();
    Persona(std::string nombre, std::string telefono, std::string email, std::string direccion, bool estado);

    void cargar();
    void mostrar();

    void setNombre(std::string nombre);
    void setTelefono(std::string telefono);
    void setEmail(std::string email);
    void setDireccion(std::string direccion);
    void setEstado(bool estado);

    const char* getNombre();
    const char* getTelefono();
    const char* getEmail();
    const char* getDireccion();
    bool getEstado();
};
