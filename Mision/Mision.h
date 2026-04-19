#pragma once
#include <iostream>


class Mision
{
private:
    std::string codigo;
    float temperatura;
    float cantidad;
    float x;
    float y;
    bool activa = false;
    std::string nota = "Añade una nota";
    int prioridad = 404;

public:

    Mision(std::string cod, float temp, float cant, float x, float y)
    {
        setCodigoMision(cod);
        setTemperatura(temp);
        setCombustible(cant);
        setPosicionX(x);
        setPosicionY(y);
    }

    void setCodigoMision(std::string &cod){ validarCodigo(cod);  codigo = cod;}
    std::string getCodigoMision() const {  return codigo; }
    void setTemperatura(float temp) { validarTemperatura(temp);  temperatura = temp;}
    float getTemperatura() const { return temperatura; }
    void setCombustible(float cant) { validarCombustible(cant);   cantidad = cant; }
    float getCombustible() const { return cantidad; }
    void setPosicionX (float x) { validarPosicionX(x);   this->x = x;}
    float getPosicionX () const { return x; }
    void setPosicionY (float y) { validarPosicionY(y);   this->y = y;}
    float getPosicionY () const { return y; }


    void validarCodigo(const std::string& cod)
    {
        if (cod == "")
        {
            throw std::invalid_argument("El código no puede estar vacío.");
        }
    }
    void validarTemperatura(float &temp)
    {
        if (temp < -273.15f) {
            throw std::out_of_range("Temperatura no permitida, demasiado baja.");
        }
        if (temp > 1000.0f) {
            throw std::out_of_range("Temperatura excesiva.");
        }
    }
    void validarCombustible(float &cant)
    {
        if (cant <= 0)
        {
            throw std::out_of_range("Inserte un combustible válido. Mayor a 0.");
        }
    }
    void validarPosicionX(float &x)
    {
        if (x < -1000 || x > 1000)
        {
            throw std::out_of_range("Posición X incorrecta.");
        }
    }
    void validarPosicionY(float &y)
    {
        if (y < -1000 || y > 1000)
        {
            throw std::out_of_range("Posición Y incorrecta.");
        }
    }

    void registrarEstado()
    {
        bool activa = true;
    }

    void registrarEstado(std::string &note)
    {
        nota = note;
        registrarEstado();
    }
    void registrarEstado(std::string &note, int &prio)
    {
        registrarEstado();
        nota = note;
        if (prio<=0 || prio = 404)
        {
            throw std::out_of_range("La prioridad tiene que ser mayor a 0 y no puede ser 404");
        }
        prioridad = prio;
    }

    void verEstado()
    {
        imprimir(std::cout);
    }
    void imprimir(std::ostream &os) const
    {
        if (activa == false)
        {
            os<<"Para ver el estado de la misión primero debes activarla en el apartado -Registrar Estado- "<<std::endl;
        }
        os << "Misión: " << codigo <<std::endl;
        os << " | Temp: " << temperatura <<std::endl;
        os << " | Combustible: " << cantidad <<std::endl;
        os << " | Pos(" << x << ", " << y << ")" <<std::endl;
        os << " | Nota: " << nota <<std::endl;
        os << " | Prioridad: " << prioridad <<std::endl;
        os<<std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Mision &mis) {
        mis.imprimir(os);
        return os;
    }

    Mision& operator++()
    {
        if (prioridad <=0 || prioridad == 404)
        {
            throw std::out_of_range("La prioridad tiene que ser mayor a 0 y no pude ser 404");
        }
        ++prioridad;
        return *this; // *this retorna directamente el OBJETO
    }
};