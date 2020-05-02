#include "../include/matrix.hpp"
#include <iomanip>
#include <cmath>

Matrice::Matrice(){
N_=0;
coef_ = std::vector<double>(); //constructeur par default de vector
is_LU = false;
}

Matrice::Matrice(int N){
N_=N;
coef_ = std::vector<double>( N*N, 0);
is_LU = false;
}

Matrice::Matrice(const Matrice & M){
//Constructeur par recopie
N_ = M.N_ ;
coef_ = M.coef_ ;
is_LU = M.is_LU;
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
    is_LU =false ;
    
}


int Matrice::size() const {
    return N_;
}
bool Matrice::LU() const {
    return is_LU ;
}

double & Matrice::operator() (int i, int j) {
    return coef_[i*N_+j] ;
}

double Matrice::operator() (int i, int j) const {
    return coef_[i*N_ +j] ;
}

void::Matrice::decomp_LU(){
    //Matrice L(N_);
    //Matrice U(N_);
    //Matrice S(*this);
    double pivot;
    for(int k=0;k<N_;++k){
        //pivot
        //double pivot = S(k,k);
        pivot = (*this)(k,k) ;
        std::cout << "pivot " << pivot << std::endl;
        //colonne de L
        //L(k,k) =1;
        for(int i=k+1;i<N_;++i){
            std::cout << "colonne de L - A(i,k) avant pivot" << (*this)(i,k)<< std::endl;
            (*this)(i,k)= (*this)(i,k)/pivot;
            std::cout << "colonne de L- A(i,k) apres pivot" << (*this)(i,k) << std::endl;
        }
        /*//ligne de U
        U(k,k)=S(k,k);
        for(int j=k+1;j<N_;++j){
            U(k,j)=S(k,j);
        }*/
        //complement de schur
        for (int i=k+1;i<N_;++i){
            std::cout << "Complement de Schur, i=" << i <<  std::endl;
            for (int j=k+1;j<N_;++j){
                std::cout << "j=" << j << std::endl;
                (*this)(i,j) -= (*this)(i,k)*((*this)(k,j));
            }
        }
    }
    (*this).is_LU = true;

}

void Matrice::decomp_Cholesky(){
//on modifie uniquement la diagonale ainsi que les cases en dessous
    for(int k=0;k<N_; ++k){
        //pivot
        (*this)(k,k)=sqrt((*this)(k,k));
        //colonnes de L
        for(int i=k+1;i<N_;i++){
            (*this)(i,k)=(*this)(i,k)/(*this)(k,k);
        
        }
        //complement de schur
        for(int i=k+1;i<N_;i++){
            for(int j=k+1;j<=i;++j){
                (*this)(i,j)=(*this)(i,j) - (*this)(i,k)*(*this)(j,k);
            }
        }
    }
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

void Tribande_sym(Matrice & M){

}
Matrice Tribande_sym(int N){
    Matrice M(N);
    for(int i=1; i<N-1; ++i){
        M(i,i)=2;
        M(i-1,i)= -1;
        M(i+1,i)= -1;
    }
    M(0,0)=2;
    M(1,0) =-1;
    M(N-1,N-1)=2;
    M(N-2,N-1)=-1;
    return M;

}
std::ostream & operator<<(std::ostream &os, const Matrice &A) {

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
                for(int k=0;k<m.size();++k){
                    M(i,j)+=m(i,k)*n(k,j);
                }
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

