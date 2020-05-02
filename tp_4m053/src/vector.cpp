#include "../include/vector.hpp"
#include <iomanip>
//#include <vector>
#include <string>
#include <cmath>

Vecteur::Vecteur(){
//Constructeur vide
N_ = 0;
coef_ = std::vector<double>(); //utiliser le constructeur par default de std::vector
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
Vecteur::Vecteur (const std::string name_file){
     //constructeur input
    std::ifstream inFile;
    std::string buffer;
    inFile.open(name_file.c_str()); //ouvre le fichier au chemin
    if (!inFile) {
        std::cerr << "Unable to open file datafile.txt";
        std::exit(1);   // call system to stop
    }
    /*while (inFile >> x) { //read from the stream
        ;
        }*/
    //inFile >> buffer;
    int N;
    inFile >> N;
    std::vector<double> v(N, 0);
    for(int i =0;i<N; ++i ){
        inFile >> buffer;
        inFile >> v[i];

    }
    inFile.close(); //close the file
    N_=N;
    coef_= v;
}




int Vecteur::size() const {
    return N_ ;
}

std::vector<double> Vecteur::vector() {
    return coef_;
}

double Vecteur::norme() const{
    double norme = 0;
    for(int i =0; i<N_; i++){
        norme += (*this)(i);

    }

    return sqrt(norme);
}

double & Vecteur::operator() (int i){//acces a la reference
    return coef_[i];

}

double Vecteur::operator() (int i) const{//acces a la valeur
    return coef_[i];
}

void write_file(const Vecteur &v, const std::string name_file){
    std::ofstream myfile (name_file);
    myfile << v.size();
    myfile << "\n";
    for(int i=0; i<v.size(); ++i){
        myfile << i ;
        myfile << " ";
        myfile << v(i) ;
        myfile << "\n";

    }
    myfile.close();

}


std::ostream & operator<<(std::ostream &os, const Vecteur& v)
{
    for(int i = 0; i<v.size() ; ++i){
        os<<std::setw(10)<< v(i);
    }
    os<< std::endl;
    return os ;


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
    //std::cout <<"on a bien créer un vecteur "<< std::endl;
    for(int i = 0; i<v.size(); ++i){
        w(i) = x*(v(i)); //attention erreur
        //std::cout <<"w(" << i << ")" << w(i)<< std::endl ; 
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

