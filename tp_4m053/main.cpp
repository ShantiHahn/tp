#include "vector.hpp"
#include "matrix.hpp"
#include "direct_solvers.hpp"
#include "jacobi.hpp"
#include <ctime>
#include "json.hpp"
#include <iomanip>
#include <fstream>
#include <iostream>


// for convenience
using json = nlohmann::json;

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
/*
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

Matrice c= Tribande_sym(10);
Vecteur x(10, 1);
std::string const matrix_tribande_sym("matrix_tribande_sym.txt");
write_file(Tribande_sym(10), matrix_tribande_sym);
std::cout << Tribande_sym(7) << std::endl;

Vecteur y = solve_diag(c, x );
std::cout << y << std::endl;
*/
/*
Matrice c = Tribande_sym(5);
std::cout << c << std::endl;
c.decomp_LU();*/
/*std::cout << c << std::endl;
Matrice l = Lower(c);
Matrice u = Upper(c);
Matrice c = Tribande_sym(5);
std::cout << l << std::endl;
std::cout << u << std::endl;
std::cout << l*u << std::endl;*/
//c.decomp_LU();
//std::cout << produit_LU(c) << std::endl;
/*
Vecteur b(5,1);
std::cout << b<< std::endl;

Vecteur X=solve_LU(c, b);
std::cout << X<< std::endl;

Matrice d =Tribande_sym(5);
d.decomp_Cholesky();
std::cout << d << std::endl;
Vecteur Y = solve_Cholevesky(d,b);
std::cout << Y<< std::endl;
*/

/*
//Mesure du temps d'execution
Matrice a =Tribande_sym(1000);
Vecteur b(1000,1);
//mesurer le temps d'exectution
clock_t start, end ;
start = clock();
 

a.decomp_Cholesky();
Vecteur X =solve_Cholevesky(a,b);

end = clock();
double temps_en_secondes = static_cast<double>(end - start) / CLOCKS_PER_SEC ;

std::cout << temps_en_secondes << std::endl;

json j;
j["cholevsky"]["methode"] = "cholevsky";
j["cholvesky"]["resvec"] = X.vector();
j["cholevsky"]["cputime"] = temps_en_secondes;

std::ofstream f("data.json");

f<< std::setw(2)<<j;
f.close();
*/

Matrice A= Tribande_sym(5);
Vecteur b(5,1);
int nmax =5000;
double tol =0.0000001;
std::cout << A << std::endl;
std::cout << nmax << std::endl;
std::cout << tol << std::endl;
std::cout << b << std::endl;
//instance jacobi
Jacobi jaja(A,b,tol,nmax);
std::cout << jaja << std::endl;
jaja.Solve() ;

std::cout << jaja << std::endl;

return 0;


}