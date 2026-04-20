#pragma once
#include <iostream>

#include "../Artilugio/Artilugio.h"

class Laser : public Artilugio
{
public:
    Laser(std::string nomb, std::string desc) : Artilugio(nomb, desc) {};
    void usar() override
    {
        std::cout<< "Preparando artilugio..."<<std::endl;
        std::cout<<"Usando " <<nombre <<std::endl;
        std::cout<<"Disparo ejecutado."<<std::endl;
        std::cout<<"Enemigo eliminado."<<std::endl;
    }
};
