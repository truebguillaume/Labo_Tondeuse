//---------------------------------------------------------
// Demo           : Labo_Tondeuse_Groupe_06_G
// Fichier        : tondeuse.h
// Auteur(s)      : Mariaux Ewan & Trüeb Guillaume
// But            : Modèle pour démarrer un projet en C++
// Modifications  :
// Remarque(s)    : -
// Compilateur    : MinGW w64 9.0.0 / Apple clang version 14.0.0
// C++ version    : C++20
//---------------------------------------------------------

#ifndef LABO_TONDEUSE_TONDEUSE_H
#define LABO_TONDEUSE_TONDEUSE_H

#include <iostream>
#include <vector>
#include <array>

enum Topologie{X, L, H, h};

using Terrain = std::vector<std::vector<Topologie>>;
using Tondeuse = std::array<int, 2>;

void tondre(Terrain& terrain, Tondeuse& tondeuse, int nbreDeplacements, bool afficher);

#endif //LABO_TONDEUSE_TONDEUSE_H
