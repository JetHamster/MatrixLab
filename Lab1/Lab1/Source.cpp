
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include <fstream>
#include <type_traits>
#include <algorithm>
#include "PCA.h"
#include <math.h>
#define A 5
using namespace std;
int main() {
#if A == 0
	vector<double> tri{ 1,2,3,0, 4,5,0,0, 6 }, v{ 2,3,5,2,4,7 }, s{ 1,2,3,4,5,6,7,8,9 }, v2{3,7,9,2,4,1};
	matrix m(2, 3, v), sq(3,3,s), m2(2,3, v2);
	cout << "matrixsum " <<endl << m + m2 << endl;
	cout << "matrixmult " << endl << m*sq << endl;
	cout << "Hadamard " << endl << hadamard(sq, sq) << endl;
	cout << "Your matrix " << endl << m << endl;
	cout <<"Transposed matrix " << endl <<  m.transpose() << endl;
	uptriangmatrix m1(3, tri);
	cout <<"Transposed diagonal matrix " << endl<< m1.transpose() << endl;

#elif A == 1
	vector<double> v1{ 2,3,5,5,2,5,4,7,10 };
	matrix m1(3, 3, v1);
	cout << "matrixnorm " << m1.matrixnorm() << endl;
	cout << "trace " << m1.trace() << endl;
#elif A == 2
	vector<double> v1{ 3, 2, 1, 4 }, v2{ 2, 9, 3, 8 };
	vect  m1(4, v1), m2(4, v2);
	cout << "scalar " << scalar(m1, m2) << endl;
	cout << "vectornorms " << m1.euclidnorm() <<" " << m2.euclidnorm()<< endl;
	cout << "cos " << cosvec(m1, m2) << " " <<"angle " << angle(m1, m2) << endl;
#elif A == 3
	vector<double> v1{ 2,3,5,5,2,5,4,7,10 }, v2 = { 2,3,5,5,2,5,4,6,10 }, v3 = {2,3,5,2,4,7};
	matrix m1(3, 3, v1), m2(3, 3, v2);
	idmatrix mid(2);
	uptriangmatrix m3(3, v3);
	cout << "determinants: " << m1.matrixdet() << " " << m2.matrixdet() << endl;
	cout << "ranks: " << m1.matrixrank() << " " <<m2.matrixrank() << endl;
	cout << "overloaded determinants " << mid.matrixdet() << " " << m3.matrixdet() << endl;
#elif A == 4
	vector<double> vv{ 3.5,2,1.3,4,3,5,1.0,8,9 }, vvv{1,2,3,4,5,6};
	matrix m(3, 3, vv), m2(2,3,vvv);
	matrix mr1("test.txt"), mr2("data.txt"), mr3("scores.txt");
	cout << mr1;
	cout << mr2;
	cout << mr3;
	writematrix("newfile.txt", m);
	m.writebinmatrix("bb.bin");
	cout << readbinmatrix("bb.bin");
	m2.writebinmatrix("kk.bin");
	cout << readbinmatrix("kk.bin");
#elif A == 5
	matrix m{ 1,2,3,4,5,6};
	PCA p(m);
	//p.center();
	p.scale();
	p.showdata();
	p.nip();
#endif
	
	system("pause");
	return 0;
}