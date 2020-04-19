#include "../include/vector.hpp"
#include <iomanip>
#include <vector>

Vecteur::Vecteur(){
//Constructeur vide
N_ = 0;
coef_ = std::vector<double>(); //vector() ou bien coef_() ? pour utiliser le constructeur par default de std::vector
}

Vecteur::Vecteur(int N){
//Constructeur du vecteur nul de taille N
N_ = N ;
coef_ = std::vector<double>( N, 0);//coef_ = 0;
}

Vecteur::Vecteur(const Vecteur &v){
//Constructeur par recopie
N_ = v.N_ ;
coef_ = v.coef_ ;
}

int Vecteur::size() const {
    return N_ ;
}

double & Vecteur::operator() (int i){//acces a la reference
    return coef_[i];

}

double Vecteur::operator() (int i) const{//acces a la valeur
    return coef_[i];
}
std::ostream & operator<<(std::ostream &os, const Vecteur& v)
{
    for(int i = 0; i<v.size() ; ++i){
        os<<std::setw(10)<< v(i);
    }
    os<< std::endl;
//std::cout << "v.N_ = " << v.N_ << endl ;
//std::cout << " v.coef_ = " << v.coef_ << endl ;

}

Vecteur operator+(const Vecteur &v, const Vecteur &w){
    Vecteur x(v.size()) ;
    if(v.size() == w.size()){
        for(int i =0; i< v.size(); ++i){
            x(i)=v(i)+w(i);

        }
    return x;  // attention au scope de x
    }
    
    else{
        std::cout<< " les vecteurs n'ont pas la meme longueur.";
    }

}

Vecteur operator-(const Vecteur &v, const Vecteur &w){
    Vecteur x(v.size()) ;
    if(v.size() == w.size()){
        for(int i =0; i< v.size(); ++i){
            x(i)=v(i)-w(i);

        }
    return x;  // attention au scope de x
    }
    else{
        std::cout<< " les vecteurs n'ont pas la meme longueur.";
    }

}

Vecteur operator*(double &x, const Vecteur &v){
    Vecteur w(v.size());
    for(int i = 0; i<v.size(); ++i){
        w(i) = x*v(i);
    }
    return w;
}

Vecteur operator*(const Vecteur &v, double &x){
    Vecteur w(v.size());
    for(int i = 0; i<v.size(); ++i){
        w(i) = x*v(i);
    }
    return w;
}

Vecteur operator*(const Vecteur &v,const Vecteur &w){
    Vecteur x(v.size());
    if(v.size() == w.size()){
        for(int i = 0; i<v.size(); ++i){
            x(i) = v(i)*w(i);

        }
    return x ; // attention au scope de x
    }

    else{
        std::cout<< " les vecteurs n'ont pas la meme longueur.";
    }

}