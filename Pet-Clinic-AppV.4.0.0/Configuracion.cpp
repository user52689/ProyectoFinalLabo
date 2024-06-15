#include <iostream>
#include "Configuracion.h"
#include "Mascota.h"
#include "Cliente.h"
#include "Veterinario.h"
#include "Consultas.h"
using namespace std;

void Configuracion::copiaSeguridadMascotaBK(){
    FILE* ptrMascotas;
    FILE* ptrMascotasBK;
    Mascota mascota;

    ptrMascotas = fopen("mascotas.dat", "rb");
    ptrMascotasBK = fopen("mascotas.bak", "wb");

    if(ptrMascotas == nullptr || ptrMascotasBK == nullptr){
        cout<<"No se pudo abrir el archivo: mascotas.dat || mascotas.bak"<<endl;
    }
    else{

        while(fread(&mascota, sizeof(Mascota), 1, ptrMascotas)){
            fwrite(&mascota, sizeof(Mascota), 1, ptrMascotasBK);
        }

         cout<<"BackUp del archivo mascotas.dat realizado con exito!"<<endl<<endl;
    }
    fclose(ptrMascotas);
    fclose(ptrMascotasBK);

    system("pause");
}
void Configuracion::listarCopiaSeguridadMascotaBK(){
    FILE* ptrMascotasBK;
    Mascota mascota;

    ptrMascotasBK = fopen("mascotas.bak", "rb");

    if(ptrMascotasBK == nullptr){
        cout<<"No se pudo abrir el archivo: mascotas.bak"<<endl;
    }
    else{
        cout<<"-----------------------BACKUP REGISTRO MUNICIPIOS-----------------"<<endl;
        while(fread(&mascota, sizeof(Mascota), 1, ptrMascotasBK)){
            cout<<"Numero: "<<mascota.getNumeroMascota()<<endl;
            cout<<"Nombre: "<<mascota.getNombre()<<endl;
            cout<<"Especie: "<<mascota.getEspecie()<<endl;
            cout<<"Nacimiento: "<<mascota.getAnioNacimiento().mostrarFecha()<<endl;
            cout<<"Cliente: "<< mascota.getNumeroCliente()<<endl;
            cout<<"-----------------------------------"<<endl;
            cout<<"-----------------------------------"<<endl;
        }
    }
    fclose(ptrMascotasBK);

    system("pause");
}
void Configuracion::restaurarArchivoMascotaBK(){
    FILE* ptrMascotas;
    FILE* ptrMascotasBK;
    Mascota mascota;
    int opcion;

    ptrMascotas = fopen("mascotas.dat", "wb");
    ptrMascotasBK = fopen("mascotas.bak", "rb");

    if(ptrMascotas == nullptr || ptrMascotasBK == nullptr){
        cout<<"No se pudo abrir el archivo: mascotas.dat || mascotas.bak"<<endl;
    }
    else{
        cout<<"Esta seguro que desea restaurar la copia de seguridad mascotas.bak? 1-Si || 0-No"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;
        if(opcion == 1){
            while(fread(&mascota, sizeof(Mascota), 1, ptrMascotasBK)){
                fwrite(&mascota, sizeof(Mascota), 1, ptrMascotas);
            }

            cout<<"Restauracion del archivo mascotas.bk realizada con exito!"<<endl<<endl;
        }
    }
    fclose(ptrMascotas);
    fclose(ptrMascotasBK);

    system("pause");
}

void Configuracion::copiaSeguridadClienteBK(){
    FILE* ptrClientes;
    FILE* ptrClientesBK;
    Cliente cliente;

    ptrClientes = fopen("clientes.dat", "rb");
    ptrClientesBK = fopen("clientes.bak", "wb");

    if(ptrClientes == nullptr || ptrClientesBK == nullptr){
        cout<<"No se pudo abrir el archivo: clientes.dat || clientes.bak"<<endl;
    }
    else{

        while(fread(&cliente, sizeof(Cliente), 1, ptrClientes)){
            fwrite(&cliente, sizeof(Cliente), 1, ptrClientesBK);
        }

         cout<<"BackUp del archivo clientes.dat realizado con exito!"<<endl<<endl;
    }
    fclose(ptrClientes);
    fclose(ptrClientesBK);

    system("pause");
}
void Configuracion::listarCopiaSeguridadClienteBK(){
    FILE* ptrClientesBK;
    Cliente cliente;

    ptrClientesBK = fopen("clientes.bak", "rb");

    if(ptrClientesBK == nullptr){
        cout<<"No se pudo abrir el archivo: clientes.bak"<<endl;
    }
    else{
        cout<<"-----------------------BACKUP REGISTRO CLIENTES-----------------"<<endl;
        while(fread(&cliente, sizeof(Cliente), 1, ptrClientesBK)){
            cout<<"Numero: "<<cliente.getNumeroCliente()<<endl;
            cout<<"Nombre: "<<cliente.getNombre()<<endl;
            cout<<"Telefono: "<<cliente.getTelefono()<<endl;
            cout<<"Email: "<<cliente.getEmail()<<endl;
            cout<<"Direccion: "<<cliente.getDireccion()<<endl;
            cout << "-----------------------------------" << endl;
            cout << "-----------------------------------" << endl;
        }
    }
    fclose(ptrClientesBK);

    system("pause");
}
void Configuracion::restaurarArchivoClienteBK(){
    FILE* ptrClientes;
    FILE* ptrClientesBK;
    Cliente cliente;
    int opcion;

    ptrClientes = fopen("clientess.dat", "wb");
    ptrClientesBK = fopen("clientes.bak", "rb");

    if(ptrClientes == nullptr || ptrClientesBK == nullptr){
        cout<<"No se pudo abrir el archivo: clientes.dat || clientes.bak"<<endl;
    }
    else{
        cout<<"Esta seguro que desea restaurar la copia de seguridad clientes.bak? 1-Si || 0-No"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;
        if(opcion == 1){
            while(fread(&cliente, sizeof(Cliente), 1, ptrClientesBK)){
                fwrite(&cliente, sizeof(Cliente), 1, ptrClientes);
            }
            cout<<"Restauracion del archivo clientes.bk realizada con exito!"<<endl<<endl;
        }
    }
    fclose(ptrClientes);
    fclose(ptrClientesBK);

    system("pause");
}

void Configuracion::copiaSeguridadVeterinarioBK(){
    FILE* ptrVeterinarios;
    FILE* ptrVeterinariosBK;
    Veterinario veterinario;

    ptrVeterinarios = fopen("veterinarios.dat", "rb");
    ptrVeterinariosBK = fopen("veterinarios.bak", "wb");

    if(ptrVeterinarios == nullptr || ptrVeterinariosBK == nullptr){
        cout<<"No se pudo abrir el archivo: veterinarios.dat || veterinarios.bak"<<endl;
    }
    else{

        while(fread(&veterinario, sizeof(Veterinario), 1, ptrVeterinarios)){
            fwrite(&veterinario, sizeof(Veterinario), 1, ptrVeterinariosBK);
        }

         cout<<"BackUp del archivo veterinarios.dat realizado con exito!"<<endl<<endl;
    }
    fclose(ptrVeterinarios);
    fclose(ptrVeterinariosBK);

    system("pause");
}
void Configuracion::listarCopiaSeguridadVeterinarioBK(){
    FILE* ptrVeterinariosBK;
    Veterinario veterinario;

    ptrVeterinariosBK = fopen("veterinarios.bak", "rb");

    if(ptrVeterinariosBK == nullptr){
        cout<<"No se pudo abrir el archivo: veterinarios.bak"<<endl;
    }
    else{
        cout<<"-----------------------BACKUP REGISTRO VETERINARIOS-----------------"<<endl;
        while(fread(&veterinario, sizeof(Veterinario), 1, ptrVeterinariosBK)){
            cout<<"Legajo: "<<veterinario.getLegajo()<<endl;
            cout<<"Nombre: "<<veterinario.getNombre()<<endl;
            cout<<"Telefono: "<<veterinario.getTelefono()<<endl;
            cout<<"Email: "<<veterinario.getEmail()<<endl;
            cout<<"Direccion: "<<veterinario.getDireccion()<<endl;
            cout << "-----------------------------------" << endl;
            cout << "-----------------------------------" << endl;
        }
    }
    fclose(ptrVeterinariosBK);

    system("pause");
}
void Configuracion::restaurarArchivoVeterinarioBK(){
    FILE* ptrClientes;
    FILE* ptrClientesBK;
    Cliente cliente;
    int opcion;

    ptrClientes = fopen("clientess.dat", "wb");
    ptrClientesBK = fopen("clientes.bak", "rb");

    if(ptrClientes == nullptr || ptrClientesBK == nullptr){
        cout<<"No se pudo abrir el archivo: clientes.dat || clientes.bak"<<endl;
    }
    else{
        cout<<"Esta seguro que desea restaurar la copia de seguridad clientes.bak? 1-Si || 0-No"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;
        if(opcion == 1){
            while(fread(&cliente, sizeof(Cliente), 1, ptrClientesBK)){
                fwrite(&cliente, sizeof(Cliente), 1, ptrClientes);
            }
            cout<<"Restauracion del archivo clientes.bk realizada con exito!"<<endl<<endl;
        }
    }
    fclose(ptrClientes);
    fclose(ptrClientesBK);

    system("pause");
}

void Configuracion::copiaSeguridadConsultaBK(){
    FILE* ptrConsultas;
    FILE* ptrConsultasBK;
    Consultas consulta;

    ptrConsultas = fopen("consultas.dat", "rb");
    ptrConsultasBK = fopen("consultas.bak", "wb");

    if(ptrConsultas == nullptr || ptrConsultasBK == nullptr){
        cout<<"No se pudo abrir el archivo: consultas.dat || consultas.bak"<<endl;
    }
    else{

        while(fread(&consulta, sizeof(Consultas), 1, ptrConsultas)){
            fwrite(&consulta, sizeof(Consultas), 1, ptrConsultasBK);
        }

         cout<<"BackUp del archivo consultas.dat realizado con exito!"<<endl<<endl;
    }
    fclose(ptrConsultas);
    fclose(ptrConsultasBK);

    system("pause");
}
void Configuracion::listarCopiaSeguridadConsultaBK(){
    FILE* ptrConsultasBK;
    Consultas consulta;

    ptrConsultasBK = fopen("consultas.bak", "rb");

    if(ptrConsultasBK == nullptr){
        cout<<"No se pudo abrir el archivo: consultas.bak"<<endl;
    }
    else{
        cout<<"-----------------------BACKUP REGISTRO CONSULTAS------"<<endl;
        while(fread(&consulta, sizeof(Consultas), 1, ptrConsultasBK)){
            cout<<"Turno: "<<consulta.getNumeroTurno()<<endl;
            cout<<"Fecha y Hora: "<<consulta.getFechaHora().mostrarFechaHora()<<endl;
            cout<<"Veterinario: "<<consulta.getVeterinarioAsignado()<<endl;
            cout<<"Mascota: "<<consulta.getMascotaInvolucrada()<<endl;
            cout<<"Diagnostico: "<<consulta.getDiagnosticoTratamiento()<<endl;
            cout<<"Importe: "<<consulta.getImporte()<<endl;
            cout << "-----------------------------------" << endl;
            cout << "-----------------------------------" << endl;
        }
    }
    fclose(ptrConsultasBK);

    system("pause");
}
void Configuracion::restaurarArchivoConsultaBK(){
    FILE* ptrConsultas;
    FILE* ptrConsultasBK;
    Consultas consulta;
    int opcion;

    ptrConsultas = fopen("consultas.dat", "wb");
    ptrConsultasBK = fopen("consultas.bak", "rb");

    if(ptrConsultas == nullptr || ptrConsultasBK == nullptr){
        cout<<"No se pudo abrir el archivo: consultas.dat || consultas.bak"<<endl;
    }
    else{
        cout<<"Esta seguro que desea restaurar la copia de seguridad consultas.bak? 1-Si || 0-No"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;
        if(opcion == 1){
            while(fread(&consulta, sizeof(Consultas), 1, ptrConsultasBK)){
                fwrite(&consulta, sizeof(Consultas), 1, ptrConsultas);
            }
            cout<<"Restauracion del archivo consultas.bk realizada con exito!"<<endl<<endl;
        }
    }
    fclose(ptrConsultas);
    fclose(ptrConsultasBK);

    system("pause");
}
