//Polynomials.cpp

#include "Polynomials.h"

vector<vector<unsigned>> Polynomials(int n){  //v[i][0] is the decimal representation of the ith polynomial
											  //v[i][1:...] are the initialisation numbers
	vector<vector<unsigned>> result(n);
	ifstream file("polynomials.txt", ios::in);  //flux declared and file read
		string line;
		if(file)  // if opening has succeeded
		{	
			int i=0;
			while(i<n && getline(file, line)) 
			{
				string temp=line; //line=dimension;degree;decimal representation;m1,m2,...
				vector<string> splittedLine=Split(temp,';');
				vector<unsigned> polynomial(1);
				polynomial[0]=atoi(splittedLine[2].c_str()); //decimal representation
				vector<string> sL2=Split(splittedLine[3],','); //initialisation numbers
				for(int j=0; j<sL2.size()-1;j++){  //-1 because there is a comma too many
					polynomial.push_back(atoi(sL2[j].c_str()));
				}
				result[i]=polynomial;
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