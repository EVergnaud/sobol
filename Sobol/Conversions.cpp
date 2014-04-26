//Conversions.cpp
#include "Conversions.h"

int IntToGrayC(int i){  //returns the Gray Code but in the decimal system 
	//e.g IntToGrayC(3)=(011)_2 XOR (001)_2= (010)_2 = (2)_10
	int a=floor((double) i/2);
	return a^i;
} //IntToGrayC


vector<int> DecToBin(int n) { //be careful : vector[0] corresponds to 2^(vector.size())
								//to be able to XOR FBin of different sizes
	vector<int> bin;
	if(n>1){
		while(n>1){
			bin.insert(bin.begin(),n%2);
			n=n >> 1; //right shift (in binary representation)
		}
		bin.insert(bin.begin(),n); //add the last digit that can't be added with the while
	}
	else if(n==1){
		bin.insert(bin.begin(),1);
	}
	else{
		bin.insert(bin.begin(),0);
	}
	
	return bin;
}  //DecToBin 

vector<int> IntToPolynomial(int n, int degree){ //the result is with the powers of 2 needed for the initialization numbers
									//the +1 (x^0) is included but x^order is excluded
									//and the length of result is only the highest not null power in the primitive polynomial 
									//except for the order
	vector<int> result;
	result=DecToBin(n);
	result.push_back(1); //corresponds to x^0
	int s=result.size();
	for(int i=0;i<s;i++){
		result[s-1-i]=result[s-1-i]*pow((double) 2, (double) degree-i);  //vérifier la formule
	}
	return result;
}//IntToPolynomial
