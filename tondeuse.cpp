//----------------------------------------------------------------------------------------------------------------------
// Demo           : Labo_Tondeuse_Groupe_06_G
// Fichier        : tondeuse.cpp
// Auteur(s)      : Mariaux Ewan & Trüeb Guillaume
// But            : Fonctions permettant de tondre le terrain spécifié par l'utilisateur
// Modifications  :
// Remarque(s)    : -
// Compilateur    : MinGW w64 9.0.0 / Apple clang version 14.0.0
// C++ version    : C++20
//----------------------------------------------------------------------------------------------------------------------

#include <iostream>

#include "annexe.h"
#include "tondeuse.h"

using namespace std;

// Définition graphique des éléments du terrain
array<char,4> affichageTopologie ={'X','#','~','.'};


/** Fonction permettant de calculer le déplacement de la tondeuse en fonction du random trouvé.
 * ---------------------------------------------------------------------------------------------------------------------
 * @param nbr           : axe de déplacement de la tondeuse.
 *                          nbr = 1 → la tondeuse monte
 *                          nbr = 2 → la tondeuse va vers la droite
 *                          nbr = 3 → la tondeuse descends
 *                          nbr = 4 → la tondeuse va vers la gauche
 * @param posV          : positon de la tondeuse sur l'axe verticale
 * @param posH          : positon de la tondeuse sur l'axe horizontale
 * ---------------------------------------------------------------------------------------------------------------------
 * @return                  : -
 * @exception               : -
 */
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

/** Fonction permettant de contrôler si le déplacement de la tondeuse est possible. Si la fonction
*   retourne true c'est que le déplacement est possible. Sinon on recommence un nouveau déplacement.
* ----------------------------------------------------------------------------------------------------------------------
* @param terrain            : vecteur composé de vecteur d'enum Topologie
* @param posV               : positon de la tondeuse sur l'axe verticale
* @param posH               : positon de la tondeuse sur l'axe horizontale
* ----------------------------------------------------------------------------------------------------------------------
* @return                  : retourne si le déplacement est possible. True s'il est possible
* @exception               : -
*/
bool deplacementPossible(const Terrain& terrain, size_t posV, size_t posH){

    // Si la nouvelle position est égale à une case limite ou une case obstacle
    if(terrain[posV][posH] == Topologie::L || terrain[posV][posH] == Topologie::X)
        return false;

    return true;
}

/** Fonction permettant l'affichage du terrain.
* ----------------------------------------------------------------------------------------------------------------------
* @param terrain            : vecteur composé de vecteur d'enum Topologie
* ----------------------------------------------------------------------------------------------------------------------
* @return                   : -
* @exception                : -
*/
void affichageTerrain(const Terrain& terrain){

    // Pour chaque ligne du terrain
    for(const LigneTerrain& ligneTerrain : terrain)
    {
        // Pour chaques éléments de la ligne
        for(const Topologie t : ligneTerrain)
        {
            // Affichage du type de terrain
            cout << affichageTopologie[(size_t)t] << " ";
        }
        cout << endl;
    }
}


void tondre(Terrain& terrain, Tondeuse& tondeuse, int nbreDeplacements, bool afficher){

    // Positon verticale et horizontale
    size_t posV, posH;
    int nbr;

    //Valeur min et max pour le random
    const int VAL_MIN = 1;
    const int VAL_MAX = 4;

    for(int i = 0 ; i < nbreDeplacements ; ++i){

        //position actuelle de la tondeuse
        posV = (size_t)tondeuse[0];
        posH = (size_t)tondeuse[1];

        nbr  = nbrAleatoire(VAL_MIN,VAL_MAX);

        deplaceTondeuse(nbr, posV, posH);

        if(deplacementPossible(terrain, posV, posH)){
            //retourne la nouvelle position à la tondeuse
            tondeuse[0] = (int)posV;
            tondeuse[1] = (int)posH;

            //coupe l'herbe haute
            terrain[posV][posH] = Topologie::h;
        }
        else
        {
            //le déplacement n'est pas comptabilisé
            --i;
        }

        if(afficher){
            // Clear l'affichage afin d'avoir un seul terrain d'afficher à la fois
            // Pour MacOs et Linux
            system("clear");

            // Pour Windows
            //system("cls");

            // Affichage du terrain
            affichageTerrain(terrain);
        }
    }
    // Affiche du terrain final
    affichageTerrain(terrain);
}