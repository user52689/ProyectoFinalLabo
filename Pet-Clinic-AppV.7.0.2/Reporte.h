#pragma once

class Reporte{
private:
    char _nombre[50];

public:
    Reporte(const char* nombre);

    void setNombre(std::string nombre);
    const char* getNombre();
};


