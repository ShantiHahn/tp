#pragma once
#include "direct_solvers.hpp"
#include "matrix.hpp"


class Jacobi {

    private:
    //donnees membres prives
    Matrice  A_;
    Vecteur  b_;
    double tol_ ;
    int n_max_;


    public:
    //donnees membres publique
    Vecteur x_ ;
    int niter_ ;
    //Vecteur resvec_ ;
    std::vector<double> resvec_ ;

    //methodes
    Matrice A() const ;//retourne la matrice 
    Vecteur b() const  ; //retourne le vecteur
//    Vecteur x() const ; //sol
    double tolerance() const;
    int nmax() const;
    
    Jacobi (const Matrice &A, const Vecteur &b_, double tol, int maxit);
    void Solve();
    //
}
;

std::ostream & operator<<(std::ostream &os,const  Jacobi & jaja);