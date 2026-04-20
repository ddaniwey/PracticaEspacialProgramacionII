#pragma once
#include <iostream>


class Recurso {

protected:

    std::string nombre;
    int cantidad;

public:

    Recurso(std::string nombre, int cantidad) : nombre(nombre), cantidad(cantidad) {}

    virtual ~Recurso() {};

    virtual void mostrarInfo() const {
        std::cout << "Recurso: " << nombre << " | Cantidad: " << cantidad;
    }
};