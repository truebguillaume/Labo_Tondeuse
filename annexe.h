//---------------------------------------------------------
// Demo           : Labo_Tondeuse_Groupe_06_G
// Fichier        : annexe.h
// Auteur(s)      : Mariaux Ewan & Trüeb Guillaume
// But            : Modèle pour démarrer un projet en C++
// Modifications  :
// Remarque(s)    : -
// Compilateur    : MinGW w64 9.0.0 / Apple clang version 14.0.0
// C++ version    : C++20
//---------------------------------------------------------

#ifndef MODELCPP_ANNEXE_H
#define MODELCPP_ANNEXE_H

    /** Fonction permettant de choisir un nombre aléatoire se trouvant dans une plage d'entier donné en paramètre.
     * -----------------------------------------------------------------------------------------------------------------
     * @param min               : correspond à la borne minimale acceptable pour la saisie
     * @param max               : correspond à la borne maximale acceptable pour la saisie
     * -----------------------------------------------------------------------------------------------------------------
     * @return                  : une valeur de type int comprenant la saisie de l'utilisateur
     * @exception               : -
     */
    int nbrAleatoire(int min, int max);

#endif //MODELCPP_ANNEXE_H
