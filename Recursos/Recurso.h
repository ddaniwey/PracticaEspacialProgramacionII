#pragma once
#include <iostream>
#include <stdexcept>


class Recurso {

protected:

    std::string nombre;
    int cantidad;
    float precio;

public:

    Recurso(std::string nombre, int cantidad, float precio) :precio(precio),  nombre(nombre), cantidad(cantidad)
    {
        setCantidad(cantidad);
        setPrecio(precio);
    }

    float getPrecio() const { return precio; }
    int getCantidad() const { return cantidad; }


    void setCantidad(int nuevaCantidad) {
        if (nuevaCantidad < 0)
        {
            throw std::invalid_argument("Cantidad no válida");
        }
        cantidad = nuevaCantidad;
    }

    void setPrecio(float nuevoPrecio) {
        if (nuevoPrecio < 0)
        {
            throw std::invalid_argument("Precio no válido");
        }
        precio = nuevoPrecio;
    }


    virtual ~Recurso() {};

    virtual void mostrarInfo() const = 0;

    virtual float calcularCoste() = 0;

    virtual Recurso& operator++(int)
    {
        setCantidad(cantidad + 1);
        return *this;
    };
};