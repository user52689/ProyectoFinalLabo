#pragma once

class Fecha {
private:
    int _dia;
    int _mes;
    int _anio;
    int _hora;
    int _minuto;
    int _segundo;

public:

    int getDia();
    void setDia(int dia);

    int getMes();
    void setMes(int mes);

    int getAnio();
    void setAnio(int anio);

    int getHora();
    void setHora(int hora);

    int getMinuto();
    void setMinuto(int minuto);

    int getSegundo();
    void setSegundo(int segundo);
};
