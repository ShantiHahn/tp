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
//std::vector<double> v(9, 1);
Matrice a(3);
a(0,0) =1 ;
a(0,1) = 2 ;
a(1,1) = 6;
a(2,1) =3 ;
a(2,2) = 4;
//std::cout << "a(0,0) et a(1,1)" << a.size() <<std::endl<< a(0,0) << std::endl << a(1,1) << std::endl;

std::cout << "a" << std::endl << a << std::endl;
std::string const vecteur_test("vecteur_test.txt");
Vecteur b(vecteur_test);
std::cout << b << std::endl;

std::string const matrix_test("matrix_test.txt");
Matrice m(matrix_test);
std::cout << m << std::endl;

std::string const vecteur_test_retour("vecteur_test_retour.txt");
write_file(b, vecteur_test_retour);

std::string const matrix_test_retour("matrix_test_retour.txt");
write_file(m, matrix_test_retour);
return 0;


}