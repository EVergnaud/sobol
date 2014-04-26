//Halton.cpp
#include "Halton.h"


Halton::Halton(int prime)
{
	_prime=prime;
}


Halton::~Halton(void)
{
}

vector<int> Halton::_HaltonRepresentation(int n) { //be careful : vector[0] corresponds to 2^(vector.size())
												//almost the same function than DecToBin
	vector<int> result;
	if(n>1){
		while(n>_prime-1){
			result.push_back(n%_prime);
			n=(n-n%_prime)/_prime; //right shift
		}
		result.push_back(n); //add the last digit that can't be added with the while
	}
	else if(n>0){
		result.push_back(n);
	}
	else{
		result.push_back(0);
	}
	
	return result;
}  

void Halton::_HaltonSequenceVec(int n){ //n in the number of terms that are to be computed
	for(int i=0; i<n; i++){
		vector<int> HR=_HaltonRepresentation(i+1); //compute the halton representation of the integer
		double temp=0;
		for(int j=0; j<HR.size(); j++){
			temp=temp+HR[j]/pow((double) _prime, (double) j+1); // and then do simple operations to get the halton term
		}
		_hSVec[i]=temp;
	}
}
		
		
int Halton::Get_prime(void){
	return _prime;
}
void Halton::Set_prime(int prime){
	_prime=prime;
}

vector<double> Halton::Get_HSVecDouble(int n){
	if(_hSVec.size()!=n){ //for the first time the function is called
		_hSVec.resize(n,0);
		_HaltonSequenceVec(n);
	}
	return _hSVec;
}
vector<unsigned> Halton::Get_HSVecInt(int n){
	if(_hSVec.size()!=n){ //for the first time the function is called
		_hSVec.resize(n,0);
		_HaltonSequenceVec(n);
	}
	vector<unsigned> result(n);
	for(int i=0;i<n;i++){
		result[i]=_hSVec[i]*pow((double) 2, (double) 32); // just multiply by 2^32 to get integers
														//between 0 and 2^32
	}
	return result;
}