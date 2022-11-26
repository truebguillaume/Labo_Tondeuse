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

#include <iostream>

#include "annexe.h"
#include "tondeuse.h"

using namespace std;

//peut être déplacé par la suite
array<char,4> affichageTopologie ={'X','#','~','.'};


// Fonction permettant de calculer le déplacement de la tondeuse en fonction du random trouvé.
// Les axes de déplacements sont :
// nbr = 1 → la tondeuse monte
// nbr = 2 → la tondeuse va vers la droite
// nbr = 3 → la tondeuse descends
// nbr = 4 → la tondeuse va vers la gauche
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

// Fonction permettant de contrôler si le déplacement de la tondeuse est possible. Si la fonction
// retourne true c'est que le déplacement est possible. Sinon on recommence un nouveau déplacement.
bool deplacementPossible(Terrain& terrain, size_t posV, size_t posH){

    // Si la nouvelle position est égale à une case limite ou une case obstacle
    if(terrain[posV][posH] == Topologie::L || terrain[posV][posH] == Topologie::X)
        return false;

    return true;
}

// Fonction permettant l'affichage du terrain
void affichageTerrain(Terrain& terrain){
    for(LigneTerrain& ligneTerrain : terrain)
    {
        for(Topologie t : ligneTerrain)
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

    const int VAL_MIN = 1;
    const int VAL_MAX = 4;

    for(int i = 0 ; i < nbreDeplacements ; ++i){

        posV = (size_t)tondeuse[0];
        posH = (size_t)tondeuse[1];

        nbr  = nbrAleatoire(VAL_MIN,VAL_MAX);

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