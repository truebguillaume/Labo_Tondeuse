//---------------------------------------------------------
// Demo           : Labo_Tondeuse_Groupe_06_G
// Fichier        : annexe.cpp
// Auteur(s)      : Mariaux Ewan & Trüeb Guillaume
// But            : Modèle pour démarrer un projet en C++
// Modifications  :
// Remarque(s)    : -
// Compilateur    : MinGW w64 9.0.0 / Apple clang version 14.0.0
// C++ version    : C++20
//---------------------------------------------------------

#include <iostream>
#include <random>

#include "annexe.h"

using namespace std;

random_device                  rand_dev;
default_random_engine          generator(rand_dev());

int nbrAleatoire(int min, int max){

    uniform_int_distribution<int>  distr(min, max);
    return distr(generator);
}