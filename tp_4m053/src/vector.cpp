#include "../include/vector.hpp"
#include <vector>

Vecteur::Vecteur(){
//Constructeur vide
N_ = 0;
coef_ = vector(); //vector() ou bien coef_() ? pour utiliser le constructeur par default de std::vector
}

Vecteur::Vecteur(int N){
//Constructeur du vecteur nul de taille N
N_ = N ;
coef_ = vector( int N, 0);//coef_ = 0;
}

Vecteur::Vecteur(const Vecteur &v){
//Constructeur par recopie
N_ = v.N_ ;
coef_ = V.coef_ ;
}

Vecteur::size(){
    return N_ ;
}

Vecteur::operator() (int i){//acces a la reference
    return v(i);

}

Vecteur::operator() (int i) const{//acces a la valeur
    return v(i);
}
std::ostream & operator<<(std::ostream &os, const Vecteur& v)
{
    for(int i = 0; i<v.size() ; ++i){
        os<<setw(10)<< v(i);
    }
    os<< endl;
//std::cout << "v.N_ = " << v.N_ << endl ;
//std::cout << " v.coef_ = " << v.coef_ << endl ;

}

Vecteur operator+(const Vecteur &v, const Vecteur &w){
    if(v.size() == w.size()){
        Vecteur x(v.size()) ;
        for(int i =0; i< v.size(); ++i){
            x(i)=v(i)+w(i);

        }
    }
    return x;  // attention au scope de x
    else{
        std::cout<< " les vecteurs n'ont pas la meme longueur."
    }

}

Vecteur operator-(const Vecteur &v, const Vecteur &w){
    if(v.size() == w.size()){
        Vecteur x(v.size()) ;
        for(int i =0; i< v.size(); ++i){
            x(i)=v(i)-w(i);

        }
    }
    return x;  // attention au scope de x
    else{
        std::cout<< " les vecteurs n'ont pas la meme longueur."
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
    if(v.size() == w.size()){
        Vecteur x(v.size());
        for(int i = 0; i<v.size(); ++i){
            x(i) = v(i)*w(i);

        }
    return x ; // attention au scope de x

    else{
        std::cout<< " les vecteurs n'ont pas la meme longueur."
    }

}