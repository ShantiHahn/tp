// Fichier include/vecteur.hpp
#pragma once
#include<vector> // pour les std::vector
#include <iostream>
#include <fstream>

class Vecteur{
private:
  int N_;
  std::vector<double> coef_;
public: 
  // Les méthodes et constructeurs  à venir
  // ...
  Vecteur (); // constructeur vide
  Vecteur (int N); // constructeur créant un vecteur de taille N et rempli de zéros
  Vecteur (int N, double x); //constructeur
  Vecteur (int N, std::vector<double> &v); //constructeur
  Vecteur (const Vecteur &v); // constructeur par recopie
  Vecteur (const std::string  name_file); //constructeur input
  ~Vecteur()=default; // destructeur par défaut


  //methode constante qui renvoie la taille du vecteur
  int size() const;
  //methode qui renvoie un vector
  std::vector<double> vector() ;
  //norme
  double norme() const;
  //accesseurs
  double & operator() (int i);      // Accès a la reference
  double operator() (int i) const; // Accès a la valeur (recopie)

};
void write_file(const Vecteur &v, const std::string name_file);

std::ostream & operator<<(std::ostream &os, const Vecteur& v);
// En dehors de la classe Vecteur
Vecteur operator+(const Vecteur &v, const Vecteur &w);

Vecteur operator-(const Vecteur &v, const Vecteur &w);

Vecteur operator*(double x, const Vecteur &v);

Vecteur operator*(const Vecteur &v,double x);

Vecteur operator*(const Vecteur &v,const Vecteur &w);


