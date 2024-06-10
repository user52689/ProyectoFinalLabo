#pragma once

class Persona {
protected:
    char _nombre[20];
    char _telefono[20];
    char _email[30];
    char _direccion[40];
    bool _estado;

public:
    // Constructor
    Persona(const char* nombre, const char* telefono, const char* email, const char* direccion, bool estado);

    // Métodos de acceso para Nombre
    const char* getNombre();
    void setNombre(const char* nombre);

    // Métodos de acceso para Teléfono
    const char* getTelefono();
    void setTelefono(const char* telefono);

    // Métodos de acceso para Email
    const char* getEmail();
    void setEmail(const char* email);

    // Métodos de acceso para Dirección
    const char* getDireccion();
    void setDireccion(const char* direccion);

    // Métodos de acceso para Estado
    bool getEstado();
    void setEstado(bool estado);
};

