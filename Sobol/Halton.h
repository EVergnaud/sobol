//Halton.h
#pragma once

#include<vector>
using namespace std;
#include <math.h> //for pow
#include <iostream> //for cout

class Halton
{
public:
	Halton(int);
	~Halton(void);


//accessors
	int Get_prime(void);
	void Set_prime(int);
	vector<double> Get_HSVecDouble(int n); //returns the normal sequence 
	vector<unsigned> Get_HSVecInt(int n); //returns the sequence transformed in integers 
	
private:
	int _prime;
	vector<double> _hSVec;
	void _HaltonSequenceVec(int n); //computes the Halton sequence
	vector<int> _HaltonRepresentation(int n); //computes the Halton representation
};

