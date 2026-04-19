#include <iostream>
#include "Mision/Mision.h"
#include <cassert>


void pruebas1()
{
    Mision marte("12345M4RT3", 25, 100, 10, 20);
    assert(marte.getCodigoMision() == "12345M4RT3");
    assert(marte.getTemperatura() == 25);
    assert(marte.getCombustible() == 100);

    std::string nota = "Mision llegada a marte, no corre prisa. Está prevista para acabarla en 2030";
    marte.registrarEstado(nota);
    try
    {
      ++marte;
    } catch (std::out_of_range &e)
    {
        std::cout<< "Error: "<<std::endl;
    }

    std::cout<<marte;

    try
    {
        marte.setPosicionX(5000.4567);
    } catch (std::out_of_range &e)
    {
        std::cout<<"Error: ";
    }catch (...)
    {
        std::cout<< "Error genérico, algo ha ocurrido";
    }
}

int main()
{
    pruebas1();
    return 0;
}
