//Sobol.cpp

#include "Sobol.h"


Sobol::Sobol(vector<unsigned> initialIN, int intPolynomial, int n) //compute n terms of the original sobol sequence 
{
	clock_t t=clock()-intPolynomial; //to generate random numbers
	_initialIN=initialIN; //set the initial initialisation numbers
	_InitialisationNumbers(intPolynomial); //compute the rest of the IN
	_DirectionNumbers(); //compute the direction numbers
	_InitialTerm(t); //compute the initial term
	

	_sobolVec.resize(n,0);
	FBin previousTerm=_initialTerm;
	_sobolVec[0]=previousTerm.ToDec(); // first term
	//recurrence relation described in the paper (s_i=s_i-1 \oplus v_j_i)
	for(int i=1; i<n; i++){
		int rMZero=_RightMostZero(i+1); //i+1 selon le papier car initialTerm est en fait déjà le deuxième terme de la suite 
										//(mais alors lequel est le premier ?)
										//i selon deltaquants avec initialTerm qui est bien le n°1
		previousTerm=previousTerm^_dN[rMZero-1]; //rMZero-1 because we want the rMzeroth term
		_sobolVec[i]=previousTerm.ToDec();
	}

}


Sobol::Sobol(int degree, int intPolynomial, int n) //same thing but we generate the initial initialisation numbers (sobol improved)
												//we still need the degree of the polynomial to know how many numbers we must generate
{
	clock_t t=clock()-intPolynomial;
	_InitialIN(degree,t); // here.
	_InitialisationNumbers(intPolynomial);
	_DirectionNumbers();
	_InitialTerm(t);
	

	_sobolVec.resize(n,0);
	FBin previousTerm=_initialTerm;
	_sobolVec[0]=previousTerm.ToDec();
	for(int i=1; i<n; i++){
		int rMZero=_RightMostZero(i+1); //i+ selon le papier car initialTerm est en fait déjà le deuxième terme de la suite
										//(mais alors lequel est le premier ?)
										//i selon deltaquants avec initialTerm qui est bien le n°1
		previousTerm=previousTerm^_dN[rMZero-1]; //rMZero-1 because we want the rMzeroth term
		_sobolVec[i]=previousTerm.ToDec(); 
	}

}



Sobol::~Sobol(void)
{
}










void Sobol::_InitialisationNumbers(int intPolynomial){
	int degree=_initialIN.size();
	vector<int> p=IntToPolynomial(intPolynomial,degree);
	int s=p.size();
	vector<int> result;
	_iN=_initialIN;
	for(int i=degree; i<32;i++){
		unsigned temp=_iN[i-degree];
		if(degree==1){ //if degree=1 the recurrence relation does not work properly
			temp=2*temp^temp;
		}
		else{
			for(int j=0;j<s;j++){ //compute equation (2). the 2^i are included in p
				temp=temp^(p[s-1-j]*_iN[i-degree+j]); // 
			}
		}
		_iN.push_back(temp);
	}

}
void Sobol::_DirectionNumbers(){
	_dN.resize(_iN.size());
	for(int i=0;i<_iN.size();i++){
		_dN[i]=FBin(DecToBin(_iN[i]),i+1); //i+1 because the ith initialisation number is _dN[i-1]
	}
}



void Sobol::_InitialTerm(clock_t t){  //iniNumbers is the vector of initialisation numbers (m_i=v_i*2^i)
	int seed=((clock()-t)*123456)%4294967295;  //draw a seed
	vector<int> graySeed = DecToBin(IntToGrayC(seed)); //transform it to gray code
	int s=graySeed.size();
	FBin result(s); //transform it in binary fraction to bitwise XOR
	for(int i=0; i < s ; i++){
		if(graySeed[s-1-i]==1){
			result=result^_dN[i]; //bitwise XOR
		}
	}
	_initialTerm=result;
}//InitialTerm







int Sobol::_RightMostZero(int n){
	vector<int> nBin=DecToBin(n);
	for(unsigned int i=0; i < nBin.size();i++){
		if(nBin[nBin.size()-1-i]==0){
			return i+1;
		}
	}
	return nBin.size()+1;
} 


void Sobol::_InitialIN(int n, clock_t t){ // compute n initial IN
	_initialIN.resize(n);

	vector<_int64> vLCG=LCG(69069,0,pow(2.0,32.0),2,50000); //size 50000 to have a sufficient choice 
															//and not to long to compite
	clock_t seed;
	seed=((clock()-t)*2013)%50000; // random number
	for(int i=0;i<n;i++){
		unsigned temp=0;
		int j=0;
		while(temp%2==0){ //condition imposed by Silva  [2003]
			temp=max(1.0,vLCG[seed+j]/pow(2.0,(double) 32-(i+1))-1); 
			j++;
		}
		_initialIN[i]=temp;
		cout << "in"<<temp << "\n";
	}
}