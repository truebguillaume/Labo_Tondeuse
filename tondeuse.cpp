//
// Created by Guillaume Trüeb on 22.11.22.
//

#include <random>

#include "tondeuse.h"

using namespace std;

int nombreAleatoire(int min, int max){

    random_device rd;                           // obtain a random number from hardware
    mt19937 gen(rd());                          // seed the generator
    uniform_int_distribution<> distr(min, max); // define the range

    return distr(gen);
}

bool deplacementPossible(){

}

void tondre(Terrain& terrain, Tondeuse& tondeuse, int nbreDeplacements, bool afficher){

}