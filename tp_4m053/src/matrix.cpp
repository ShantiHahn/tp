#include "../include/matrix.hpp"
#include <iomanip>

Matrice::Matrice(){
N_=0;
coef_ = std::vector<double>(); //constructeur par default de vector
}

Matrice::Matrice(int N){
N_=N;
coef_ = std::vector<double>( N, 0);
}

Matrice::Matrice(const Matrice & M){
//Constructeur par recopie
N_ = M.N_ ;
coef_ = M.coef_ ;
}

int Matrice::size() const {
    return N_;
}

double & Matrice::operator() (int i, int j) {
    return coef_[i+j*N_] ;
}

double Matrice::operator() (int i, int j) const {
    return coef_[i+j*N_] ;
}

std::ostream & operator<<(std::ostream &os, const Matrice &A){

    for(int i=0; i<A.size() ; ++i){
        for(int j=0; j<A.size() ; ++j)
        {os<<std::setw(20)<< A(i,j);}
        os << std::endl;}
    os << std::endl;
    return os; 
}