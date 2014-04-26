//Conversions.h
#pragma once

#include<vector>
using namespace std;
#include <math.h> //for pow, floor


int IntToGrayC(int);   //Converts an integer to its GrayCode with a decimal representation
vector<int> DecToBin(int);  //Converts from a decimal number to a binary number
							//be careful : vector[0] corresponds to 2^(vector.size())
							//to be able to XOR FBins of different sizes
vector<int> IntToPolynomial(int n, int degree); //Converts an integer
			//to its polynomial representation
			//e.g. n=2=10 and degree=4, then P=x^4+x^2+1
			//!result is with the powers of 2 needed for the initialization numbers