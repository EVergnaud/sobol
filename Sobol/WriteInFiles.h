//WriteinFiles.h
#pragma once

#include<vector>
#include<string>
using namespace std;
#include "Halton.h"
#include "Sobol.h"
#include <iostream>  //cerr
#include <fstream> //read/write a flux

template <class T>
void OneDimensionInFile(T& t, string path, bool hex=false){ //write a sequence (contained in a vector) in a file
										//either a number by line, either ready for diehard
		ofstream file(path.c_str(), ios::out);  //flux declared and file read
    if(file)  // if opening has succeeded
    {	
		if(hex==false){
			for(unsigned i=0; i<t.size(); i++){			
				file << t[i] << "\n";
			}
		}
		else{
			for(unsigned i=0; i<t.size(); i++){		
				char buffer[33]; //32 bits
				_itoa_s(t[i],buffer,16); 
				string b=string(buffer);//conversion to string
				while(b.size()<8){  //in order to always have 8 digits (0 at the beginning if not)
					b.insert(b.begin(),'0');
				}
				file << b;
				if(i%10==9){
					file << "\n"; // 10 numbers by line
				}
			}
		}
		file.close();  // file closed
    }
    else  // if it has not succeeded
	{
            cerr << "Erreur à l'ouverture !" << endl;
	}
}

template <class T>
void TwoDimensionInFile(T& t, string path, string delimiter=" "){ // t must be a vector<vector<>> of length 2
				//the two subvectors are written in a file; each line has two terms separated by a delimiter from each subvector	
		ofstream file(path.c_str(), ios::out);  //flux declared and file read
    if(file)  // if opening has succeeded
    {	
		for(unsigned i=0; i<t[0].size(); i++){			
			file << t[0][i] << delimiter << t[1][i] << "\n";
		}
		file.close();  // file closed
    }
    else  // if it has not succeeded
	{
            cerr << "Erreur à l'ouverture !" << endl;
	}
}

template <class T>
void ThreeDimensionInFile(T& t, string path, string delimiter=" "){// t must be a vector<vector<>> of length 3
				//the three subvectors are written in a file; each line has three terms separated by a delimiter from each subvector
		ofstream file(path.c_str(), ios::out);  //flux declared and file read
    if(file)  // if opening has succeeded
    {	
		for(unsigned i=0; i<t[0].size(); i++){			
			file << t[0][i] << delimiter << t[1][i] << delimiter << t[2][i] << "\n";
		}
		file.close();  // file closed
    }
    else  // if it has not succeeded
	{
            cerr << "Erreur à l'ouverture !" << endl;
	}
}


void TwoDHaltonToLatex(int p1, int p2); //make a file ready for latex (Halton, 2 dimensions)
void ThreeDHaltonToLatex(int p1, int p2,int p3); //make a file ready for latex (Halton, 3 dimensions)
void TwoDSobolToLatex(int d1, int d2, vector<vector<unsigned>>& polynomials); //make a file ready for latex (Sobol, 2 dimensions)
void ThreeDSobolToLatex(int d1, int d2, int d3, vector<vector<unsigned>>& polynomials);//make a file ready for latex (Sobol, 3 dimensions)
void TwoDSobolIToLatex(int d1, int d2, vector<vector<unsigned>>& polynomials);//make a file ready for latex (Sobol improved, 2 dimensions)
void ThreeDSobolIToLatex(int d1, int d2, int d3, vector<vector<unsigned>>& polynomials); //make a file ready for latex (Sobol improved, 3 dimensions)

