#include "Interfaz.h"
#include "rlutil.h"

void Interfaz::establecerColorTexto(int color) {
    rlutil::setColor(color);
}
void Interfaz::establecerColorFondo(int color) {
    rlutil::setBackgroundColor(color);
}

char Interfaz::capturarTecla() {
    return rlutil::getkey();
}

void Interfaz::moverCursor(int x, int y) {
    rlutil::locate(x, y);
}

void Interfaz::fijarTamanoConsola() {
    system("mode con cols=102 lines=800");
}

///Con logo 2.00
void Interfaz::mostrarTitulo() {
    rlutil::locate(7, 7);
    std::cout << "     _  _      _____     _           _____ _ _       _                                " << std::endl;
    rlutil::locate(7, 8);
    std::cout << "  _ (_)(_) _  |  __ \\   | |         / ____| (_)     (_)             /\\                " << std::endl;
    rlutil::locate(7, 9);
    std::cout << " (_) ____ (_) | |__) |__| |_ ______| |    | |_ _ __  _  ___ ______ /  \\   _ __  _ __  " << std::endl;
    rlutil::locate(7, 10);
    std::cout << "    /    \\    |  ___/ _ \\ __|______| |    | | | '_ \\| |/ __|______/ /\\ \\ | '_ \\| '_ \\ " << std::endl;
    rlutil::locate(7, 11);
    std::cout << "   |      |   | |  |  __/ |_       | |____| | | | | | | (__      / ____ \\| |_) | |_) |" << std::endl;
    rlutil::locate(7, 12);
    std::cout << "    \\____/    |_|   \\___|\\__|       \\_____|_|_|_| |_|_|\\___|    /_/    \\_\\ .__/| .__/ " << std::endl;
    rlutil::locate(7, 13);
    std::cout << "                                                                         | |   | |    " << std::endl;
    rlutil::locate(7, 14);
    std::cout << "                                                              V5.0.0     |_|   |_|    " << std::endl;
    rlutil::locate(28, 35);
    std::cout << (char)184 << " Abraham Meza | Isaias Dabalos | Oscar Principi ";
}


void Interfaz::tituloConsola(){
    rlutil::setConsoleTitle("Pet-Clinic-App");
}

void Interfaz::interfazCliente(){
    int velocidadAparicion = 50;
    int velocidad = 30;

    std::cout << "    _____\n";
    rlutil::msleep(velocidadAparicion);

    std::cout << "   /     \\ \n";
    rlutil::msleep(velocidad);

    std::cout << "  | 0   0 | \n";
    rlutil::msleep(velocidad);

    std::cout << "   \\  ^  /\n";
    rlutil::msleep(velocidad);

    std::cout << "   /     \\\n";
    rlutil::msleep(velocidad);

    std::cout << " /  |||||  \\\n";

}

void Interfaz::obtenerDibujoEspecie(int especie) {
    int velocidadAparicion = 50;
    int velocidad = 30;

    switch (especie) {
        case 1:
            std::cout << "    .-\"-.\n";
            rlutil::msleep(velocidadAparicion);

            std::cout << "   /|6 6|\\\n";
            rlutil::msleep(velocidad);

            std::cout << "  {/(_0_)\\}\n";
            rlutil::msleep(velocidad);

            std::cout << "   _/ ^ \\_\n";
            rlutil::msleep(velocidad);

            std::cout << "  (/ /^\\ \\)-'\n";
            rlutil::msleep(velocidad);

            std::cout << "   \"\"' '\"\"\n";

            break;

        case 2:
            std::cout << "    / _ /  ( \n";
            rlutil::msleep(velocidadAparicion);

            std::cout << "   ( ^.^ ) _)\n";
            rlutil::msleep(velocidad);

            std::cout << "      \"/  (\n";
            rlutil::msleep(velocidad);

            std::cout << "   ( | | )\n";
            rlutil::msleep(velocidad);

            std::cout << "  (__d b__)\n";
            rlutil::msleep(velocidad);

            std::cout << "           \n";

            break;

        default:
            std::cout << "No se encontró dibujo para esta especie.\n";
            break;
    }
}


