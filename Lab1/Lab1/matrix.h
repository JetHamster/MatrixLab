#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include <fstream>
#include <type_traits>
#include <algorithm>
#include <math.h>
using namespace std;
class matrix{
protected:
	unsigned int row;
	unsigned int col;
	vector<double> vec;
public:
	matrix() {
		row = 0;
		col = 0;
	}
	matrix(const unsigned int m, const unsigned int n, vector<double> v1);
	matrix(const char* filename);
	matrix(initializer_list<double> l);
	void center();
	void scale();
friend matrix hadamard(matrix &m1, matrix &m2);
friend ostream& operator <<(ostream &s, const matrix &c);
friend matrix operator +(matrix &m1, matrix &m2);
friend matrix operator -(matrix &m1, matrix &m2);
//friend void operator -=(matrix &m1, matrix &m2);
friend matrix operator *(matrix &m1, const double a);
//friend void operator *=(matrix &m1, const double a);
friend matrix operator*(matrix &m1, matrix &m2);
void writebinmatrix(const char* name);
double matrixnorm();
double matrixdet();
int matrixrank();
matrix transpose();
//void inverse();
friend class PCA;
double trace();
void settrows(unsigned int m) {
	row = m;
}
void setcols(unsigned int m){
	col = m;
}
};
class idmatrix : public matrix {
private:
	int d;
public:
	idmatrix(const unsigned int a);
	idmatrix transpose();
	double matrixdet();
};
class diagmatrix: public matrix{
private:
	int d;
public:
	diagmatrix(const unsigned int a, vector<double> v1);
	double matrixdet();
	diagmatrix transpose();
};
class lowtriangmatrix : public matrix {
private:
	int d;
public:
	lowtriangmatrix(const unsigned int a, vector<double> v1);
	double matrixdet();
	friend class uptriangmatrix;
	uptriangmatrix transpose();
};
class uptriangmatrix : public matrix {
private:
	int d;
public:
	uptriangmatrix(const unsigned int a, vector<double> v1);
	double matrixdet();
	friend class lowtriangmatrix;
};

class symmatrix : public matrix {
private:
	int d;
public:
	symmatrix(const unsigned int a, vector<double> v1);
	symmatrix transpose();
};
class vect: public matrix {
private:
	int d;
public:
	vect(const unsigned int a, vector<double> v1);
	double maxnorm();
	friend double scalar(vect v1, vect v2);
	double euclidnorm();
	friend double cosvec(vect v1, vect v2);
	friend double angle(vect v1, vect v2);
};
void writematrix(const char* filename, matrix& m);
matrix readbinmatrix(const char* filename);
