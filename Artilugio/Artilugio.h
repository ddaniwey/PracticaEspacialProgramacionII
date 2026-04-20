#pragma once
#include <iostream>


class Artilugio
{
protected:
    std::string nombre;
    std::string descripcion;

public:
    Artilugio(std::string nomb, std::string desc): nombre(nomb), descripcion(desc){}
    virtual void usar()
    {
        std::cout<< "Preparando artilugio..."<<std::endl;
        std::cout<<"Usando " <<nombre <<std::endl;
    }
    void setNombre(const std::string &nomb){ nombre = nomb; }
    std::string getNombre() const{ return nombre; }
    void setDescripcion(const std::string &desc){descripcion = desc; }
    std::string getDescripcion() const{ return descripcion; }
};