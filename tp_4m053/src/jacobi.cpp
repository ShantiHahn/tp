#include "jacobi.hpp"
#include <iomanip>
#include <cmath>

Jacobi::Jacobi(const Matrice & A, const Vecteur & b, double tol, int maxit)
:A_(A),b_(b),x_(b.size())
{
    tol_=tol;
    n_max_=maxit;
    niter_ = 0 ;
}

void Jacobi::Solve(){
    niter_ = 0 ;
    Vecteur r = b_ ;
    resvec_.push_back(r.norme()/b_.norme());
    while(r.norme()/b_.norme()>tol_ && niter_<n_max_){
        Vecteur y = solve_diag(A_,r);
        x_ = x_ + y;
        r = b_ - (A_*x_);
        niter_ += 1 ;
        resvec_.push_back(r.norme()/b_.norme());
    }

    
}

Matrice Jacobi::A() const  {
        
    //retourne la matrice 
    return A_;
}
Vecteur Jacobi::b() const  {
    return b_;
} //retourne le vecteur

double Jacobi::tolerance() const {
    return tol_;
}
int Jacobi::nmax() const {
    return n_max_;
}

std::ostream & operator<<(std::ostream & os, const Jacobi & jaja) {
    os <<  "Matrice " <<std::endl<< jaja.A() << std::endl;
    os <<"Vecteur " <<std::endl<< jaja.b() << std::endl;
    os <<"Tolerance " <<std::setw(6)<< jaja.tolerance() << std::endl;
    os << "N_max iterations " << std::setw(6)<< jaja.nmax() << std::endl;
    os << "sol" << std::setw(6) << jaja.x_ << std::endl;
    os << "nombre iterations" << std::setw(6) << jaja.niter_  << std::endl;
    for(int i =0; i<jaja.resvec_.size(); i++){
        std::cout << jaja.resvec_[i] << std::setw(6) ;
    }
    return os ;
}

