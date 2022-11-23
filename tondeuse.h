//
// Created by Guillaume Trüeb on 22.11.22.
//

#ifndef LABO_TONDEUSE_TONDEUSE_H
#define LABO_TONDEUSE_TONDEUSE_H

#include <vector>
#include <array>

enum Topologie{X, L, H};

//peut être déplacé par la suite
//std::array<char,4> affichageTopologie ={'X','#','~','.'};

using Terrain = std::vector<std::vector<Topologie>>;
using Tondeuse = std::array<int, 2>;

void tondre(Terrain& terrain, Tondeuse& tondeuse, int nbreDeplacements, bool afficher);

#endif //LABO_TONDEUSE_TONDEUSE_H
