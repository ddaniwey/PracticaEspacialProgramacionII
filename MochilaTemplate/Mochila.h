#pragma once
#include <iostream>
#include <memory>
#include <vector>

template <class TBase>

class Mochila
{
private:
    std::vector<std::shared_ptr<TBase>> artilugios;
public:
    template <class TDerivada>
    void addArtilugio(std::shared_ptr<TDerivada> &artilug)
    {
        artilugios.push_back(artilug);
    }
    template <class TDerivada>
    void eliminarArtilugio(std::shared_ptr<TDerivada> &artilug)
    {
        bool eliminado = false;
        for (int i = 0; i < artilugios.size(); i++) {
            if (artilug == artilugios[i]) {
                std::cout << artilugios[i]->getNombre() << " tirado al espacio exterior" << std::endl;
                artilugios.erase(artilugios.begin() + i);
                eliminado = true;
                break;
            }
        }
            if (!eliminado)
            {
                std::cout<<artilug->getNombre() << " no se ha encontrado en la mochila. Imposible eliminar."<<std::endl;
            }
    }
    void verArtilugios()
    {   std::cout<<"Artilugios de mi mochila"<<std::endl;
        std::cout<<"------------------------------------"<<std::endl;
        int contador = 1;
        for ( const auto &artilugio : artilugios)
        {
            std::cout<<contador<<".-"<<std::endl;
            std::cout<<artilugio->getNombre()<<std::endl;
            contador++;
        }
    }
};