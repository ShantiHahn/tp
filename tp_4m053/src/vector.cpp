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

Vecteur::Vecteur(int N, double x){
//
N_ = N ;
coef_ = std::vector<double>( N, x ) ; //coef_ = vecteur de x

}

Vecteur::Vecteur(int N, std::vector<double> &v){

N_ = N ;
coef_ = v ;
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
    return os ;
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
        std::cout<< " les vecteurs n'ont pas la meme longueur."<< std::endl;
        return Vecteur() ; //temporaire attention
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
        std::cout<< " les vecteurs n'ont pas la meme longueur."<< std::endl;
        return Vecteur() ; //temporaire attention

    }

}

Vecteur operator*(double x, const Vecteur &v){
    Vecteur w(v.size());
    std::cout <<"on a bien créer un vecteur "<< std::endl;
    for(int i = 0; i<v.size(); ++i){
        w(i) = x*(v(i)); //attention erreur
        std::cout <<"w(" << i << ")" << w(i)<< std::endl ; 
    }
    return w;
}

Vecteur operator*(const Vecteur &v, double x){
    Vecteur w(v.size());
    std::cout <<"on a bien créer un vecteur "<< std::endl;
    for(int i = 0; i<v.size(); ++i){
        w(i) = x*(v(i)); //attention erreur
        std::cout <<"w(" << i << ")" << w(i)<< std::endl ; 
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
        std::cout<< " les vecteurs n'ont pas la meme longueur."<<std::endl;
        return Vecteur() ; //temporaire attention
    }

}