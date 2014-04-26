//main.cpp
#pragma once

#include <iostream> //pour cout
#include <fstream>
#include <string>

#include <vector>
#include <math.h>
#include "Halton.h"
#include "Sobol.h"
#include "WriteInFiles.h"
#include "Polynomials.h"
using namespace std;

#include <iostream>  //cerr
#include <fstream> //read/write a flux


vector<int> PrimeNumbers(int n){ //if we want to know the ith prime number
	vector<int> result(n);
	ifstream file("1-1000000.csv", ios::in);  //flux declared and file read
		string line;
		if(file)  // if opening has succeeded
		{	
			int i=0;
			while(i<n && getline(file, line))  // tant que l'on peut mettre la ligne dans "contenu"
			{
				cout << line << endl;
				result[i]=atoi(line.c_str());  // on l'affiche
				i++;
			}
			file.close();  // file closed
		}
		else  // if it has not succeeded
		{
				cerr << "Erreur à l'ouverture !" << endl;
		}
		return result;
}



void main(){
	
	vector<vector<unsigned>> polynomials=Polynomials(1050);

/*Latex*/
	/*TwoDHaltonToLatex(2,3);
	TwoDHaltonToLatex(71,73);
	TwoDHaltonToLatex(1987,1993);
	
	ThreeDHaltonToLatex(2,3,5);
	ThreeDHaltonToLatex(71,73,79);
	ThreeDHaltonToLatex(1987,1993,1997);*/
	
/*	TwoDSobolToLatex(1,2,polynomials);
	TwoDSobolToLatex(20,21,polynomials);
	TwoDSobolToLatex(300,301,polynomials);
	TwoDSobolToLatex(1000,1001,polynomials);

	ThreeDSobolToLatex(1,2,3,polynomials);*/
//	ThreeDSobolToLatex(20,21,22,polynomials);
//	ThreeDSobolToLatex(300,301,302,polynomials);
//	ThreeDSobolToLatex(1000,1001,1002,polynomials);


//	TwoDSobolIToLatex(1,2,polynomials);
//	TwoDSobolIToLatex(20,21,polynomials);
//	TwoDSobolIToLatex(300,301,polynomials);
//	TwoDSobolIToLatex(1000,1001,polynomials);

//	ThreeDSobolIToLatex(1,2,3,polynomials);
//	ThreeDSobolIToLatex(20,21,22,polynomials);
//	ThreeDSobolIToLatex(300,301,302,polynomials);
//	ThreeDSobolIToLatex(1000,1001,1002,polynomials);

/*   */




	//Halton sequence for diehard
//	Halton H1(2);
//	vector<unsigned> H1Vec=H1.Get_HSVecInt(3000000);
//	OneDimensionInFile(H1Vec,"halton2.txt",true);
	


	//sobol sequence for diehard
/*	vector<unsigned> p1=polynomials[3];
	int intP1=p1[0];
	p1.erase(p1.begin());
	Sobol S1=Sobol(p1,intP1,3000000);
	vector<unsigned> s1=S1.Get_SobolSequence(s1);
	OneDimensionInFile(s1,"lastchance.txt",true);
	*/



}