#pragma once
#include <iostream>
#include "Recurso.h"

class RecursoTecnologico : public Recurso {
private:
    int nivelComplejidad;

public:
    RecursoTecnologico(std::string nombre, int cantidad, int nivel)
        : Recurso(nombre, cantidad), nivelComplejidad(nivel) {}

    void mostrarInfo() const override {
        Recurso::mostrarInfo();
        std::cout << " | Complejidad: Nivel " << nivelComplejidad << std::endl;
    }
};
