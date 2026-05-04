#pragma once
#include <iostream>
#include "Recurso.h"

class RecursoTecnologico : public Recurso {
private:
    int nivelComplejidad;

public:
    RecursoTecnologico(std::string nombre, int cantidad, int nivel, int precio)
        : Recurso(nombre, cantidad, precio), nivelComplejidad(nivel)
    {
        setNivelComplejidad(nivel);
    }

    void mostrarInfo() const override {
        std::cout << "Recurso: " << nombre << " | Cantidad: " << cantidad;
        std::cout << " | Complejidad: Nivel " << nivelComplejidad << std::endl;
    }

    void setNivelComplejidad(int nivel){
        if (nivel < 0)
        {
            throw std::invalid_argument("Nivel inválido");
        }
        nivelComplejidad = nivel;
    }
    int getNivelComplejidad() const { return nivelComplejidad; }

    float calcularCoste () override
    {
        return cantidad * precio;
    }

    RecursoTecnologico& operator++(int) override
    {
        setCantidad(cantidad + 1);
        return *this;
    }
};
