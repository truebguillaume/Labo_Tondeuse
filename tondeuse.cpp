//
// Created by Guillaume Trüeb on 22.11.22.
//

#include <random>

#include "tondeuse.h"

using namespace std;

int nbrAleatoire(int min, int max){

    random_device rd;                           // obtain a random number from hardware
    mt19937 gen(rd());                          // seed the generator
    uniform_int_distribution<> distr(min, max); // define the range

    return distr(gen);
}

void deplaceTondeuse(int nbr, int& posX, int& posY){

    switch (nbr) {
        case 1:
            posY--;
            break;
        case 2:
            posX++;
            break;
        case 3:
            posY++;
        case 4:
            posX--;
        default:
            break;

    }
}

bool deplacementPossible(Terrain& terrain, int posX, int posY){

    if(terrain[posX][posY] == Topologie::L || terrain[posX][posY] == Topologie::X)
        return false;

    return true;
}

void tondre(Terrain& terrain, Tondeuse& tondeuse, int nbreDeplacements, bool afficher){

    int posX, posY, nbr;

    for(int i = 0 ; i < nbreDeplacements ; ++i){

        cout << "Position (x,y) : (" << tondeuse[0] << "," << tondeuse[1] << ")" << endl;

        posX = tondeuse[0];
        posY = tondeuse[1];
        nbr  = nbrAleatoire(1,4);

        deplaceTondeuse(nbr, posX, posY);

        if(deplacementPossible(terrain,posX,posY)){
            tondeuse[0] = posX;
            tondeuse[1] = posY;
        }
    }
}