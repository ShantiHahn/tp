#pragma once
#include "matrix.hpp"
#include <cassert>

Vecteur solve_diag(const Matrice & A, const Vecteur & b);//matrice diagonale
Vecteur solve_triang_inf(const Matrice &A, const Vecteur& b);//descente

Vecteur solve_triang_sup(const Matrice &A, const Vecteur& b); //remontee

Vecteur solve_triang_sup_id(const Matrice &A, const Vecteur& b);
Vecteur solve_triang_sup_id(const Matrice &A, const Vecteur& b);
//Matrice produit_LU(const Matrice &A); //Produit LU d'une matrice is_LU
Matrice Lower(const Matrice &A); // on obtient la partie L d'une matrice LU
Matrice Upper(const Matrice &A); // on obtient la partie U d'une matrice LU
Vecteur solve_LU(const Matrice &A, const Vecteur &b);
Vecteur solve_Cholevesky(const Matrice &A, const Vecteur &b);
double transpose_Cholvesky(const Matrice &A,int i, int j);