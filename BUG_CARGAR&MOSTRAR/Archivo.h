#pragma once
#include <string>
#include <cstdio>
class Archivo {
public:

protected:
   std::string _fileName;
   FILE* _pFile;


   bool abrir(std::string modo="rb");
   void cerrar();
};

