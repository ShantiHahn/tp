#include "../include/matrix.hpp"
#include <iomanip>

Matrice::Matrice(){
N_=0;
coef_ = std::vector<double>(); //constructeur par default de vector
}

Matrice::Matrice(int N){
N_=N;
coef_ = std::vector<double>( N*N, 0);
}

Matrice::Matrice(const Matrice & M){
//Constructeur par recopie
N_ = M.N_ ;
coef_ = M.coef_ ;
}

Matrice::Matrice (const std::string name_file){
     //constructeur input
    std::ifstream inFile;
    std::string buffer;
    //int a;
    //int b;
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
    std::vector<double> v(N*N, 0);
    for(int i =0;i<v.size(); ++i ){
        std::cout << "i"<<" "<< i << std::endl;
        inFile >> buffer;
        std::cout << buffer << std::endl;
        inFile >> buffer;
        std::cout << buffer << std::endl;
        inFile >> v[i];
        std::cout << "v["<< i <<"]" << " " << v[i] << std::endl;


    }
    inFile.close(); //close the file
    N_=N;
    coef_= v;
    
}


int Matrice::size() const {
    return N_;
}

double & Matrice::operator() (int i, int j) {
    return coef_[i*N_+j] ;
}

double Matrice::operator() (int i, int j) const {
    return coef_[i*N_ +j] ;
}

void write_file(const Matrice & m, const std::string name_file){
    std::ofstream myfile (name_file);
    myfile << m.size();
    myfile << "\n";
    for(int i=0; i<m.size(); ++i){
        for(int j=0; j<m.size(); j++){
            myfile << i ;
            myfile << " ";
            myfile <<  j ;
            myfile << " ";
            myfile << m(i,j) ;
            myfile << "\n";
        }

    }
    myfile.close();

}

std::ostream & operator<<(std::ostream &os, const Matrice &A){

    for(int i=0; i<A.size() ; ++i){
        for(int j=0; j<A.size() ; ++j)
        {os<<std::setw(20)<< A(i,j);}
        os << std::endl;}
    os << std::endl;
    return os; 
}

Matrice operator+(const Matrice & m, const Matrice & n){
    Matrice M(m.size()) ;
    if(m.size()== n.size()){
        for(int i=0; i<m.size(); ++i){
            for(int j=0; j<n.size(); ++j){
                M(i,j) = m(i,j) + n(i,j);
            }
        }
        return M ;
    }

    else{
        std::cout<< "les matrices n'ont pas la meme taille." << std::endl;
        return Matrice() ; //
    }
    
}

Matrice operator-(const Matrice & m, const Matrice & n){
    Matrice M(m.size()) ;
    if(m.size()== n.size()){
        for(int i=0; i<m.size(); ++i){
            for(int j=0; j<n.size(); ++j){
                M(i,j) = m(i,j) - n(i,j);
            }
        }
        return M ;
    }

    else{
        std::cout<< "les matrices n'ont pas la meme taille." << std::endl;
        return Matrice() ; //
    }
    
}


Matrice operator*(const Matrice & m, double x){
    Matrice n(m.size());
    for(int i =0; i<m.size(); ++i){
        for(int j=0; j<m.size(); ++j){
            n(i,j) = x*m(i,j);
        }
        
    }
    return n;    
}

Matrice operator*(double x, const Matrice & m){
    Matrice n(m.size());
    for(int i =0; i<m.size(); ++i){
        for(int j=0; j<m.size(); ++j){
            n(i,j) = x*m(i,j);
        }
        
    }
    return n;    
}


Matrice operator*(const Matrice & m, const Matrice & n){
    Matrice M(m.size());
    if(m.size()==n.size()){
        for(int i =0; i<m.size(); ++i){
            for(int j=0; j<m.size(); ++j){
                M(i,j) = m(i,j)*n(i,j);
            }
        }
        return M ;
    }
    else{
        std::cout <<" les matrices n'ont pas la meme taille." <<std::endl;
        return Matrice();
    }
}

Vecteur operator*(const Matrice & A, const Vecteur & x){
    Vecteur y(x.size());
    if(A.size()==x.size()){
        for(int i=0; i<x.size(); ++i){
            for(int j=0; j<x.size(); ++j){
                y(i)+= x(i)*A(i,j);
            }
        }
        return y;
    }
    else{
        std::cout << " le produit matrice vecteur n'est pas possible" << std::endl;
        std::cout << A << x << std::endl;
        return Vecteur();
    }

}
