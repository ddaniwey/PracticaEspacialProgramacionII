#include <iostream>
#include "Mision/Mision.h"
#include <cassert>
#include "Artilugio/Artilugio.h"
#include "ArtilugiosDerivados/Escudo.h"
#include "ArtilugiosDerivados/Laser.h"
#include "MochilaTemplate/Mochila.h"
#include "Recursos/Recurso.h"
#include "Recursos/RecursoNatural.h"
#include "Recursos/RecursoTecnologico.h"

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
        assert(true);
    } catch (std::out_of_range &e)
    {
        std::cout<<"Error: " << e.what()<<std::endl;
    }

    std::cout<<marte;

    try
    {
        marte.setPosicionX(5000.4567);
        assert(false);
    } catch (std::out_of_range &e)
    {
        std::cout<<"Error: " << e.what()<<std::endl;
    }catch (...)
    {
        std::cout<< "Error genérico, algo ha ocurrido.";
    }
}

void pruebas2()
{
    auto laserVerde = std::make_shared<Laser>("Laser", "Sirve para disparar y freir a los enemigos");
    auto escudoMarine = std::make_shared<Escudo>("Escudo de la marina", "Escudo fabricado con escamas de sirena. No hay nada que pueda sobrepasarlo");

    auto escudoOvni = std::make_shared<Laser>("Escudo ovni", "Desconocido");

    Mochila<Artilugio> mochila;
    mochila.addArtilugio(laserVerde);
    mochila.addArtilugio(escudoMarine);

    mochila.eliminarArtilugio(escudoOvni);
    mochila.verArtilugios();
    std::cout<<""<<std::endl;

    Artilugio artilugioGenerico = {"Artilugio genérico", "Esto es una comprobación de la clase Base"};
    artilugioGenerico.usar();
    std::cout<<""<<std::endl;
    laserVerde->usar();
    std::cout<<""<<std::endl;
    escudoMarine->usar();

}

void pruebas3()
{
    RecursoNatural madera("Madera", 50, "Bosque", 1000);
    RecursoTecnologico circuitos("Circuitos", 25, 3, 1000);

    std::cout<<""<<std::endl;
    madera.mostrarInfo();
    std::cout<<""<<std::endl;
    circuitos.mostrarInfo();
    std::cout<<""<<std::endl;
}

void pruebasUltimaPractica()
{
    std::vector<std::unique_ptr<Recurso>> coleccion;
    try {
        coleccion.push_back(std::make_unique<RecursoNatural>("Madera", 10, "Bosque", 5));
        coleccion.push_back(std::make_unique<RecursoTecnologico>("MicroChip", 3, 2, 50));
        coleccion.push_back(std::make_unique<RecursoNatural>("Agua", 20, "Rio", 20500));
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error de argumento: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error general: " << e.what() << std::endl;
    }
        try
        {
            coleccion.push_back(std::make_unique<RecursoTecnologico>("IA", 1, -1, 100));
        } catch (std::invalid_argument &e)
        {
            std::cout<<"Error: " << e.what()<<std::endl;
        }

        std::cout << "  === LISTADO DE RECURSOS ===  "<<std::endl;

        float total = 0;

        for (const auto& recurso : coleccion) {
            recurso->mostrarInfo();
            float coste = recurso->calcularCoste();
            std::cout << "Coste: " << coste << std::endl;
            total += coste;
        }

        std::cout << "Coste total: " << total << std::endl;

    auto piedra = std::make_unique<RecursoNatural>("Piedra",43, "Caverna", 0);
    std::cout<<"Cantidad de piedras: " <<piedra->getCantidad()<<std::endl;
    (*piedra)++;
    std::cout<<"Cantidad de piedras: " <<piedra->getCantidad()<<std::endl;

}

int main()
{
    //pruebas1();
    //pruebas2();
    std::cout<<""<<std::endl;
   // pruebas3();
    pruebasUltimaPractica();
    return 0;
}
