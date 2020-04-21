#pragma once
#include<vector> // pour les std::vector
#include <iostream>
#include "vector.hpp"

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
    Matrice (const std::string name_file); //constructeur input
    ~Matrice() = default;

         
    int size() const;
    double & operator() (int i, int j);     // Accès à la référence
    double operator() (int i, int j) const; // Accès à la valeur (recopie)

};
void write_file(const Matrice & m, const std::string name_file);

std::ostream & operator<<(std::ostream & os, const Matrice &A);

Matrice operator+(const Matrice & m, const Matrice & n);

Matrice operator-(const Matrice & m, const Matrice & n);

Matrice operator*(const Matrice & m, double x) ;
Matrice operator*(double x, const Matrice & m);

Matrice operator*(const Matrice & m, const Matrice & n);

Vecteur operator*(const Matrice & A, const Vecteur & x);