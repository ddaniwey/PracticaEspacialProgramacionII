#pragma once
#include <iostream>
#include "../Artilugio/Artilugio.h"

class Escudo : public Artilugio
{
public:
    Escudo(std::string nomb, std::string desc) : Artilugio(nomb, desc) {};
    void usar() override
    {
        std::cout<< "Preparando artilugio..."<<std::endl;
        std::cout<<"Usando " <<nombre <<std::endl;
        std::cout<<"Te has protegido."<<std::endl;
        std::cout<<"Parece que hoy no será tu último dia de vida."<<std::endl;
    }
};
