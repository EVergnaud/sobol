//Fbin.cpp

#pragma once
#include "FBin.h"

#include <iostream> //pour cout

FBin::FBin(int n){
	_length=n;
	_vector.resize(n,0); //all elements are 0
}
FBin::FBin(vector<int> a){
	_length=a.size();
	_vector=a;
}
FBin::FBin(vector<int> a, int nbDecalage){ //nbDecalage the shift induced by  "/2^i" 
											//when computing direction numbers (cf proposition 2.2)
	_length=nbDecalage;
	_vector=a;
	while(_vector.size()<_length){ //we just add one are several 0 at the beginning f the vector
									//it is the beginning because FBin=0.v[0]v[1]...
		_vector.insert(_vector.begin(),0);
	}
}//FBin
FBin::FBin(void){
	_length=0;
	_vector.resize(0);
}


FBin::~FBin(void){
}


int FBin::operator[] (const int i)
{
	return _vector[i];
}

FBin FBin::operator^ (FBin fBin){ //bitwise XOR
	FBin result;
	if(_length<fBin._length){ //result must be at the start
								//the longest of the FBin
		result=fBin;
		result._length=fBin._length;
	}
	else{
		result=(*this);
		result._length=_length; 
	}
	for(int i=0; i<min(_length,fBin._length); i++){ //and then we can do a bitwise XOR
			result.SetElement(i,(_vector[i]+fBin[i])%2);
	}
	return result;
}

void FBin::SetElement(int i, int a){
	if (a==1 || a==0){
		_vector[i]=a;
	}
	else{
		_vector[i]=0;
	}
}
int FBin::GetLength(void){
	return _length;
}


double FBin::ToDec(void){
	double result=0;
	for(int i=0; i<_length; i++)
	{
		result=result+_vector[i]/pow((double) 2, (double) i+1);
	}
	return result;
}
int FBin::RightMostZero(void){ //if there are no zeros, then RMZ is length+1
	for(unsigned int i=0; i < _length;i++){
		if(_vector[_length-1-i]==0){
			return i+1;
		}
	}
	return _length+1;
}

void FBin::Print(void){
	for(int i=0;i<_vector.size();i++){
		cout << _vector[i];
	}
	cout << "\n";
}