#pragma once
#include <iostream>
#include <ctime>
#include <string>

class Hora {
private:
    int _hora;
    int _minuto;
    int _segundo;

public:

    Hora(int hora, int minuto, int segundo);
    Hora();

    std::string mostrarHora();
    bool esValida(int hora, int minutos, int segundos);

    int getHora();
    int getMinuto();
    int getSegundo();

    void setHora(int hora);
    void setMinuto(int minuto);
    void setSegundo(int segundo);
};

