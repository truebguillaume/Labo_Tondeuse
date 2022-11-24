//---------------------------------------------------------
// Demo           : Labo_Tondeuse_Groupe_06_G
// Fichier        : tondeuse.cpp
// Auteur(s)      : Mariaux Ewan & Trüeb Guillaume
// But            : Modèle pour démarrer un projet en C++
// Modifications  :
// Remarque(s)    : -
// Compilateur    : MinGW w64 9.0.0 / Apple clang version 14.0.0
// C++ version    : C++20
//---------------------------------------------------------


#include "annexe.h"
#include "tondeuse.h"

using namespace std;

//peut être déplacé par la suite
array<char,4> affichageTopologie ={'X','#','~','.'};


void deplaceTondeuse(int nbr, size_t& posV, size_t& posH){

    switch (nbr) {
        case 1:
            posV--;
            break;
        case 2:
            posH++;
            break;
        case 3:
            posV++;
            break;
        case 4:
            posH--;
            break;
        default:
            break;
    }
}

bool deplacementPossible(Terrain& terrain, size_t posV, size_t posH){

    if(terrain[posV][posH] == Topologie::L || terrain[posV][posH] == Topologie::X)
        return false;

    return true;
}

void affichageTerrain(Terrain& terrain){
    for(vector<Topologie>& vec : terrain)
    {
        for(Topologie t : vec)
        {
            cout << affichageTopologie[(size_t)t] << " ";
        }
        cout << endl;
    }
}

void tondre(Terrain& terrain, Tondeuse& tondeuse, int nbreDeplacements, bool afficher){

    //positon Verticale et horizontale
    size_t posV, posH;
    int nbr;

    for(int i = 0 ; i < nbreDeplacements ; ++i){

        posV = (size_t)tondeuse[0];
        posH = (size_t)tondeuse[1];

        nbr  = nbrAleatoire(1,4);

        deplaceTondeuse(nbr, posV, posH);

        if(deplacementPossible(terrain, posV, posH)){
            tondeuse[0] = (int)posV;
            tondeuse[1] = (int)posH;
            terrain[posV][posH] = Topologie::h;
        }
        else
        {
            --i;
        }

        if(afficher){
            system("clear");
            affichageTerrain(terrain);
        }

    }
    affichageTerrain(terrain);
}