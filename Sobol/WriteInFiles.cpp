//WriteInFiles.cpp
#pragma once
#include "WriteInFiles.h"

void TwoDHaltonToLatex(int p1, int p2){ //p1 and p2 are two primes
	Halton H1=Halton(p1); //first dimension
	Halton H2=Halton(p2); //second
	vector<vector<double>> matrix(2);
	matrix[0]=H1.Get_HSVecDouble(256); //first sequence
	matrix[1]=H2.Get_HSVecDouble(256); //second
	TwoDimensionInFile(matrix,"H" + std::to_string((long double)p1)+"_"+std::to_string((long double)p2) +".txt");
}

void ThreeDHaltonToLatex(int p1, int p2,int p3){
	Halton H1=Halton(p1);
	Halton H2=Halton(p2);
	Halton H3=Halton(p3);
	vector<vector<double>> matrix(3);
	matrix[0]=H1.Get_HSVecDouble(512);
	matrix[1]=H2.Get_HSVecDouble(512);
	matrix[2]=H3.Get_HSVecDouble(512);
	ThreeDimensionInFile(matrix,"H" + std::to_string((long double)p1)+"_"+std::to_string((long double)p2)+"_"+std::to_string((long double)p3) +".txt");
}


void TwoDSobolToLatex(int d1, int d2, vector<vector<unsigned>>& polynomials){
	vector<unsigned> p1=polynomials[d1-1]; //first polynomial + initialisation numbers 
	vector<unsigned> p2=polynomials[d2-1]; //second
	int intP1=p1[0]; //polynomial representation
	int intP2=p2[0]; 
	p1.erase(p1.begin()); //initialisation numbers
	p2.erase(p2.begin());
	Sobol S1=Sobol(p1,intP1,256); //construction of the original sequence: we need the initial IN
	Sobol S2=Sobol(p2,intP2,256);

	vector<vector<double>> matrix(2);
	matrix[0]=S1.Get_SobolSequence(matrix[0]);
	matrix[1]=S2.Get_SobolSequence(matrix[1]);
	TwoDimensionInFile(matrix,"S" + std::to_string((long double)d1)+"_"+std::to_string((long double)d2) +".txt");
}
void ThreeDSobolToLatex(int d1, int d2, int d3, vector<vector<unsigned>>& polynomials){
	vector<unsigned> p1=polynomials[d1-1];
	vector<unsigned> p2=polynomials[d2-1];
	vector<unsigned> p3=polynomials[d3-1];
	int intP1=p1[0];
	int intP2=p2[0];
	int intP3=p3[0];
	p1.erase(p1.begin());
	p2.erase(p2.begin());
	p3.erase(p3.begin());
	Sobol S1=Sobol(p1,intP1,512);
	Sobol S2=Sobol(p2,intP2,512);
	Sobol S3=Sobol(p3,intP3,512);
	vector<vector<double>> matrix(3);
	matrix[0]=S1.Get_SobolSequence(matrix[0]);
	matrix[1]=S2.Get_SobolSequence(matrix[1]);
	matrix[2]=S3.Get_SobolSequence(matrix[2]);
	ThreeDimensionInFile(matrix,"S" + std::to_string((long double)d1)+"_"+std::to_string((long double)d2)+"_"+std::to_string((long double)d3) +".txt");
}

void TwoDSobolIToLatex(int d1, int d2, vector<vector<unsigned>>& polynomials){
	vector<unsigned> p1=polynomials[d1-1];
	vector<unsigned> p2=polynomials[d2-1];
	int intP1=p1[0];
	int intP2=p2[0];
	p1.erase(p1.begin());
	p2.erase(p2.begin());
	Sobol S1=Sobol(p1.size(),intP1,256); //construction of the modified sequence : we need the degree of the polynomial
	Sobol S2=Sobol(p2.size(),intP2,256);

	vector<vector<double>> matrix(2);
	matrix[0]=S1.Get_SobolSequence(matrix[0]);
	matrix[1]=S2.Get_SobolSequence(matrix[1]);
	TwoDimensionInFile(matrix,"SI" + std::to_string((long double)d1)+"_"+std::to_string((long double)d2) +".txt");
}

void ThreeDSobolIToLatex(int d1, int d2, int d3, vector<vector<unsigned>>& polynomials){
	vector<unsigned> p1=polynomials[d1-1];
	vector<unsigned> p2=polynomials[d2-1];
	vector<unsigned> p3=polynomials[d3-1];
	int intP1=p1[0];
	int intP2=p2[0];
	int intP3=p3[0];
	p1.erase(p1.begin());
	p2.erase(p2.begin());
	p3.erase(p3.begin());
	Sobol S1=Sobol(p1.size(),intP1,512);
	Sobol S2=Sobol(p2.size(),intP2,512);
	Sobol S3=Sobol(p3.size(),intP3,512);
	vector<vector<double>> matrix(3);
	matrix[0]=S1.Get_SobolSequence(matrix[0]);
	matrix[1]=S2.Get_SobolSequence(matrix[1]);
	matrix[2]=S3.Get_SobolSequence(matrix[2]);
	ThreeDimensionInFile(matrix,"SI" + std::to_string((long double)d1)+"_"+std::to_string((long double)d2)+"_"+std::to_string((long double)d3) +".txt");
}

