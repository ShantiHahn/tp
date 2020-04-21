#include "vector.hpp"
#include "matrix.hpp"
int main(){

/*
Vecteur v(3) ; // constructeur d'un vecteur de taille 3
std::cout << v << std::endl ; //surcharge
v(1) = 1 ;
v(2)= 2 ;
std::cout <<"v" << v << "size" <<v.size() <<std::endl ; //surcharge
Vecteur w = v + v ;
std::cout << "w" << w <<  "size" <<w.size() <<std::endl ; //surcharge
Vecteur w1 = v - v ;
std::cout << "w1" << w1 <<  "size" <<w1.size() << std::endl ; //surcharge
Vecteur w2 = v*v ;
std::cout << "w2" << w2 <<  "size" <<w2.size() <<std::endl ; //surcharge
Vecteur x = v*3 ;
std::cout <<"x" << x <<  "size" <<x.size() << std::endl ; //surcharge
Vecteur x1 = 3*v ;
std::cout <<"x1" << x1 <<  "size" <<x1.size() << std::endl ; //surcharge
Vecteur y = w + x ;
std::cout <<"y" << y <<   " y size" <<y.size()<<std::endl; //surcharge
Vecteur z = y * x ;
std::cout <<"z" << z   << " z size" <<z.size()<< std::endl ; //surcharge
*/

Matrice a(3);
a(1,2) =2 ;
a(2,2) =3 ;
a(3,2) = 4;
std::cout << "a" << a.size() <<std::endl<< a(1,1) << std::endl;

return 0;


}