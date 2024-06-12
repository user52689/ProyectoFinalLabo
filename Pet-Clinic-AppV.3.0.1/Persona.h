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

    const char* getNombre();
    void setNombre(std::string nombre);

    const char* getTelefono();
    void setTelefono(std::string telefono);

    const char* getEmail();
    void setEmail(std::string email);

    const char* getDireccion();
    void setDireccion(std::string direccion);

    bool getEstado();
    void setEstado(bool estado);

    ///Metodos agregados para llamar en clase Cliente & Veterinario
    void cargar();
    void mostrar();
};
