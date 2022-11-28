cmake_minimum_required(VERSION 3.23)
project(Labo_Tondeuse)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(Labo_Tondeuse
        annexe.cpp
        annexe.h
        Labo_Tondeuse_Groupe_06_G.cpp tondeuse.cpp tondeuse.h)
