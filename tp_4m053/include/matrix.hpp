#pragma once
#include<vector> // pour les std::vector
#include <iostream>

class Matrice{
    //matrice carree stockage dense
    private :
    //donnees membres
    int N_ ;//nombres de lignes et colonnes
    std::vector<double> coef_ ;

    public:
    Matrice (); // constructeur vide
    Matrice (int N); // constructeur créant une matrice nulle de taille N
    Matrice (const Matrice & M); // constructeur par recopie
    ~Matrice() = default;

         
    int size() const;
    double & operator() (int i, int j);     // Accès à la référence
    double operator() (int i, int j) const; // Accès à la valeur (recopie)

};

std::ostream & operator<<(std::ostream & os, const Matrice &A);
