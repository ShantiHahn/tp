#include "../include/direct_solvers.hpp"

Vecteur solve_diag(const Matrice & A, const Vecteur & b){
    Vecteur X(b.size());
    if( A.size()==b.size()){
        for(int i=0; i<X.size(); ++i){
            X(i) =b(i)/A(i,i);
        }
        return X;
    }
    else{
        std::cout << " le vecteur et la matrice n'ont pas la meme dimension" << std::endl;
        std::cout << A << std::endl;
        std::cout << b << std::endl;
        std::cout << X << std::endl;
        return X ;
    }


}
Vecteur solve_triang_inf(const Matrice &A, const Vecteur& b){
    Vecteur X(b.size());
    double b1;
    if( A.size()==b.size()){
        for(int i=0;i< X.size(); ++i){
            b1 =0 ;
            for(int j=0; j<i; ++j){

                b1 =+ A(i,j)*X(j);
            }
            X(i) = (b(i) -b1)/A(i,i);
        }
        return X ;
    }
    else{
        std::cout << "Systeme linéaire incompatible." << std::endl;
        std::cout << A << std::endl;
        std::cout << b << std::endl;
        return X;
    }
   

}

Vecteur solve_triang_sup(const Matrice &A, const Vecteur& b){
    Vecteur X(b.size());
    double b1;
    if( A.size()==b.size()){
        for(int i=b.size()-1;i>=0; --i){
            b1=0;
            for(int j=b.size()-1; j>i; --j){

                b1 =+ A(i,j)*X(j);
                //std::cout << b1 <<std::endl << A(i,j) <<std::endl<< X(j)<< std::endl;
            }
            X(i) = (b(i) -b1)/A(i,i);
        }
        return X ;
    }
    else{
        std::cout <<"Systeme linéaire incompatible."<< std::endl;
        std::cout << A << std::endl;
        std::cout << b << std::endl;
        return X;
    }
   

}

Vecteur solve_triang_inf_id(const Matrice &A, const Vecteur& b){
    Vecteur X(b.size());
    double b1;
    if( A.size()==b.size()){
        for(int i=0;i< X.size(); ++i){
            b1=0;
            for(int j=0; j<i; ++j){

                b1 =+ A(i,j)*X(j);
            }
            X(i) = b(i) -b1;
        }
        return X ;
    }
    else{
        std::cout <<"Systeme linéaire incompatible."<< std::endl;
        std::cout << A << std::endl;
        std::cout << b << std::endl;
        return X;
    }
   

}
Vecteur solve_triang_sup_id(const Matrice &A, const Vecteur& b){
    Vecteur X(b.size());
    double b1;
    if( A.size()==b.size()){
        for(int i=0;i< X.size(); ++i){
            b1=0;
            for(int j=i+1; j<X.size(); ++j){

                b1 =+ A(i,j)*X(j);
            }
            X(i) = b(i) - b1;
        }
        return X ;
    }
    else{
        std::cout << "Systeme linéaire incompatible."<< std::endl;
        std::cout << A << std::endl;
        std::cout << b << std::endl;
        return X;
    }
   

}



Matrice produit_LU(const Matrice &A){
    //assert(A.LU()==true);
    Matrice l=Lower(A);
    Matrice u=Upper(A);
    return l*u ;

}
Matrice Lower(const Matrice &A){
    //assertm(is_LU=true);
    Matrice L = Matrice(A.size());
    for(int i=0;i<A.size();++i){
        L(i,i)=1; //on remplit la diagonale de 1
        for(int j=0;j<i;j++){
            L(i,j)= A(i,j); //on copie les elements de A sous sa diagonale dans L
        }
    }
    return L;
}

Matrice Upper(const Matrice &A){
    //assertm(is_LU=true);
    Matrice U = Matrice(A.size());
    for(int i=0;i<A.size();++i){
        for(int j=i;j<A.size();j++){
            U(i,j)= A(i,j); //on copie les elements de A de la diagonale et au dessus dans U
        }
    }
    return U;
}
Vecteur solve_LU(const Matrice &A, const Vecteur &b){
    Vecteur x(b.size()) ;
    Matrice u = Upper(A) ;
    std::cout << u<< std::endl;
    Matrice l = Lower(A) ;
    std::cout << l<< std::endl;
    x= solve_triang_inf_id(l,b);
    std::cout << x << std::endl;
    x= solve_triang_sup(u, x);



    return x;
}

Vecteur solve_Cholevesky(const Matrice &A, const Vecteur &b){
    Vecteur y(b.size());
    Vecteur x(b.size());
    y = solve_triang_inf(A,b);
    //std::cout << y << std::endl;
    double b2;
    //double b3;
    for(int i=b.size()-1;i>=0; --i){
        b2=0;
        for(int j=b.size()-1; j>i; --j){
            //b3=0;
            //b3 =transpose_Cholvesky(A,i,j);
            b2 =+ A(j,i)*x(j);
            //std::cout << b1 <<std::endl << A(i,j) <<std::endl<< X(j)<< std::endl;
        }
        x(i) = (y(i) -b2)/A(i,i);
    }
    return x ;
    
}

double transpose_Cholvesky(const Matrice &A,int i, int j){
    double a ;
    a = A(j,i);
    return a;
}