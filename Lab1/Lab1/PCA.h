#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "matrix.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include <fstream>
#include <type_traits>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <iterator>

class PCA {
private:
	matrix data, P, T, E;
public:
	PCA(matrix matr):data(matr){
	};
	void showdata();
	void nip();
	void center();
	void scale();

};