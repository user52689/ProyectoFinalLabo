#pragma once
#include "MascotaManager.h"
#include "ClienteManager.h"
//#include "ConsultasManager.h"
#include "VeterinarioManager.h"

class AppManager{
public:
    void menuPrincipal();
    void menuConfiguracion();
private:
    MascotaManager mascotaManager;
    ClienteManager clienteManager;
    VeterinarioManager veterinarioManager;
    //ConsultasManager consultasManager;
};
