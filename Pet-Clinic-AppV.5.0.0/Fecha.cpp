#include <iostream>
#include <string>
#include "Fecha.h"

using namespace std;

Fecha::Fecha(int dia, int mes, int anio){
    if(esFechaValida(dia, mes, anio)){
        _dia = dia;
        _mes = mes;
        _anio = anio;
    }
    else{
        cout<<"La fecha no es valida!"<<endl;
        ///Falta hacer la validacion desde el menu para que cuando la fecha ingresada no sea valida, vuelva a pedir el ingreso de datos de la fecha
    }
}
Fecha::Fecha() {
    time_t t = time(nullptr);
    tm* fechaActual = localtime(&t);

    _dia = fechaActual->tm_mday;
    _mes = fechaActual->tm_mon + 1;
    _anio = fechaActual->tm_year + 1900;
}
bool Fecha::cargarFecha(){
    int dia, mes, anio;

    cout<<"Dia: ";
    cin>>dia;
    cout<<"Mes: ";
    cin>>mes;
    cout<<"Anio: ";
    cin>>anio;
    if(esFechaValida(dia, mes, anio)){
        _dia = dia;
        _mes = mes;
        _anio = anio;
        return true;
    }
    return false;
}
string Fecha::mostrarFecha(){
    return "Fecha: " + to_string(_dia) + "/" + to_string(_mes) + "/" + to_string(_anio);
}
bool Fecha::esFechaValida(int dia, int mes, int anio) {
    int diasPorMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (esBisiesto(anio)) {
        diasPorMes[1] = 29;
    }
    if (mes < 1 || mes > 12) {
        return false;
    }
    if (dia < 1 || dia > diasPorMes[mes - 1]) {
        return false;
    }
    return true;
}
bool Fecha::esBisiesto(int anio){
    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
        return true;
    }
    return false;
}
bool Fecha::operator==(Fecha fecha){
    if(_dia == fecha.getDia() && _mes == fecha.getMes() &&  _anio == fecha.getAnio()){
        return true;
    }
    return false;
}

int Fecha::getDia(){
    return _dia;
}
int Fecha::getMes(){
    return _mes;
}
int Fecha::getAnio(){
    return _anio;
}

void Fecha::setDia(int dia){
    int maximosDiasPorMes = 31;
    if (_mes == 2) {
        maximosDiasPorMes = esBisiesto(_anio) ? 29 : 28;
    } else if (_mes == 4 || _mes == 6 || _mes == 9 || _mes == 11) {
        maximosDiasPorMes = 30;
    }
    if (dia >= 1 && dia <= maximosDiasPorMes) {
        _dia = dia;
    }
}
void Fecha::setMes(int mes){
    if (mes >= 1 && mes <= 12) {
        _mes = mes;
    }
}
void Fecha::setAnio(int anio) {
    if(anio >= 1900 && anio <= Fecha().getAnio()){
        _anio = anio;
    }
}
