#pragma once
#include <iostream>
#include "Recurso.h"

class RecursoNatural : public Recurso {

private:

    std::string bioma;

public:

    RecursoNatural(std::string nombre, int cantidad, std::string bioma) 
        : Recurso(nombre, cantidad), bioma(bioma) {}

    void mostrarInfo() const override {
        Recurso::mostrarInfo();
        std::cout << " | Origen: " << bioma << " (Renovable)" << std::endl;
    }
};