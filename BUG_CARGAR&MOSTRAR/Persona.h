#pragma once
#include <string>

class Persona {
public:
    Persona();
    Persona(std::string nombre, std::string telefono, std::string email, std::string direccion, bool estado);

    std::string getNombre();
    void setNombre( std::string nombre);

    std::string getTelefono();
    void setTelefono(std::string telefono);

    std::string getEmail();
    void setEmail(std::string email);

    std::string getDireccion();
    void setDireccion(std::string direccion);

    bool getEstado();
    void setEstado(bool estado);

    ///Metodos agregados para llamar en clase CLiente & Veterinario
    void cargar();
    void mostrar();

protected:
    std::string _nombre;
    std::string _telefono;
    std::string _email;
    std::string _direccion;
    bool _estado;
};
