cmake_minimum_required(VERSION 4.1)
project(PracticaEspacioPrograII)

set(CMAKE_CXX_STANDARD 20)

add_executable(PracticaEspacioPrograII main.cpp
        Mision/Mision.h
        Artilugio/Artilugio.h
        ArtilugiosDerivados/Laser.h
        ArtilugiosDerivados/Escudo.h
        MochilaTemplate/Mochila.h
)
