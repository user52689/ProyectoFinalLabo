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

    // M�todos de acceso para Nombre
    const char* getNombre();
    void setNombre(const char* nombre);

    // M�todos de acceso para Tel�fono
    const char* getTelefono();
    void setTelefono(const char* telefono);

    // M�todos de acceso para Email
    const char* getEmail();
    void setEmail(const char* email);

    // M�todos de acceso para Direcci�n
    const char* getDireccion();
    void setDireccion(const char* direccion);

    // M�todos de acceso para Estado
    bool getEstado();
    void setEstado(bool estado);
};

