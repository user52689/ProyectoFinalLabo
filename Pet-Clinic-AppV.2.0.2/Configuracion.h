#pragma once
#include "Mascota.h"
#include "Cliente.h"
#include "Veterinario.h"
#include "Consultas.h"

class Configuracion
{
    public:

        void copiaSeguridadMascotaBK();
        void listarCopiaSeguridadMascotaBK();
        void restaurarArchivoMascotaBK();

        void copiaSeguridadClienteBK();
        void listarCopiaSeguridadClienteBK();
        void restaurarArchivoClienteBK();

        void copiaSeguridadVeterinarioBK();
        void listarCopiaSeguridadVeterinarioBK();
        void restaurarArchivoVeterinarioBK();

        void copiaSeguridadConsultaBK();
        void listarCopiaSeguridadConsultaBK();
        void restaurarArchivoConsultaBK();
};

