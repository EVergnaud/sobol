//FBin.h

#pragma once
using namespace std;
#include <iostream> //for Print
#include <vector>
#include <math.h> //for min in operator ^


class FBin //FBin corresponds to a binary fraction
		   //designed to bitwise XOR easily
		   // !the first element of FBin corresponds to the last power 2^i
		   // (or the first 2^(-i) i.e 2^-1)
{
public:
	FBin(int);
	FBin(vector<int>); //if there is no 2^i that induces a shift
	FBin(vector<int>, int); //if there is  2^i
	FBin(void);
	~FBin(void);

	//operators
	int operator[] (const int);
	FBin operator^ (const FBin); //bitwise XOR

	//accessors
	void SetElement(int i, int);
	int GetLength(void);

	double ToDec(void); //Converts a FBin to its decimal value
	int RightMostZero(void);
	void Print(void);

private:
	int _length;
	vector<int> _vector;
};