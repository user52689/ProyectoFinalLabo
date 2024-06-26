#include "Interfaz.h"
#include "rlutil.h"

void Interfaz::establecerColorTexto(int color) {
    rlutil::setColor(color);
}
void Interfaz::establecerColorFondo(int color) {
    rlutil::setBackgroundColor(color);
}
void Interfaz::moverCursor(int x, int y) {
    rlutil::locate(x, y);
}
void Interfaz::fijarTamanoConsola() {
    system("mode con cols=100 lines=35");
}
void Interfaz::mostrarTitulo() {
    rlutil::locate(20, 7);
    std::cout << "  _____     _           _____ _ _       _                                " << std::endl;
    rlutil::locate(20, 8);
    std::cout << " |  __ \\   | |         / ____| (_)     (_)             /\\                " << std::endl;
    rlutil::locate(20, 9);
    std::cout << " | |__) |__| |_ ______| |    | |_ _ __  _  ___ ______ /  \\   _ __  _ __  " << std::endl;
    rlutil::locate(20, 10);
    std::cout << " |  ___/ _ \\ __|______| |    | | | '_ \\| |/ __|______/ /\\ \\ | '_ \\| '_ \\ " << std::endl;
    rlutil::locate(20, 11);
    std::cout << " | |  |  __/ |_       | |____| | | | | | | (__      / ____ \\| |_) | |_) |" << std::endl;
    rlutil::locate(20, 12);
    std::cout << " |_|   \\___|\\__|       \\_____|_|_|_| |_|_|\\___|    /_/    \\_\\ .__/| .__/ " << std::endl;
    rlutil::locate(20, 13);
    std::cout << "                                                            | |   | |    " << std::endl;
    rlutil::locate(20, 14);
    std::cout << "                                                  V5.0.0    |_|   |_|    " << std::endl;
}
void Interfaz::tituloConsola(){
    rlutil::setConsoleTitle("Pet-Clinic-App");
}
