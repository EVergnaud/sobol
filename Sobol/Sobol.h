//Sobol.h
#pragma once

#include<vector>
using namespace std;
#include <math.h> //for pow
#include <iostream> //pour cout
#include <random> //pour initialterm
#include <iso646.h> //pour opérateur XOR

#include "FBin.h"
#include "Conversions.h"
#include "LCG.h"
#include <time.h>

class Sobol
{
public:
	Sobol(vector<unsigned> , int , int);
	Sobol(int, int, int);  //Sobol improved
	~Sobol(void);

//accessors
	template <class T>
	T Get_SobolSequence(T& t){ //if T=vector<double>, returns the natural sequence
								//if T=vector<unsigned>, returns the sequence transformed in integers
		double factor=1;
		if(typeid(t)==typeid(vector<unsigned>)){
			factor=pow((double) 2, (double) 32);
		}
		T result(_sobolVec.size());
		for(int i=0;i<result.size();i++){
			result[i]=_sobolVec[i]*factor;
		}
		return result;
	}

private:
	vector<unsigned> _initialIN;//initial initialisation numbers
	FBin _initialTerm; //initial term
	vector<unsigned> _iN;//initialisation numbers
	vector<FBin> _dN;//direction numbers
	vector<double> _sobolVec; //sobol sequence
	void _InitialisationNumbers(int); //compute the initialisation numbers
	void _DirectionNumbers(); //compute the direction numbers
	void _InitialTerm(clock_t); //compute the initial term
	int _RightMostZero(int); //get the rightmost zero of an int
	void _InitialIN(int,clock_t); //compute the initial inialisation numbers for the sobol improved sequence

};

