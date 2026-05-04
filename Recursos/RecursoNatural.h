#pragma once
#include <iostream>
#include "Recurso.h"

class RecursoNatural : public Recurso {

private:

    std::string bioma;

public:

    RecursoNatural(std::string nombre, int cantidad, std::string bioma, float precio)
    : Recurso(nombre, cantidad, precio), bioma(bioma)
    {
        setBioma(bioma);
    }


    std::string getBioma() const {
        return bioma;
    }


    void setBioma(const std::string& nuevoBioma) {
        if (nuevoBioma.empty())
        {
            throw std::invalid_argument("El bioma no puede estar vacío");
        }
        bioma = nuevoBioma;
    }


    void mostrarInfo() const override {
        std::cout << "Recurso: " << nombre << " | Cantidad: " << cantidad;
        std::cout << " | Origen: " << bioma << " (Renovable)" << std::endl;
    }

    float calcularCoste () override
    {
        return cantidad * precio;
    }

    RecursoNatural& operator++(int) override
    {
        setCantidad(cantidad + 1);
        return *this;
    }

};