//LCG.cpp
#pragma once

#include "LCG.h"

vector<_int64> LCG(_int64 a, _int64 c, _int64 m, _int64 seed, unsigned n){ //n length of the result
	_int64 previous=seed;
	vector<_int64> result(n);
	for(unsigned i=0; i<n; i++){
		result[i]=(a*previous+c)%m;
		previous=result[i];
	}
	return result;
}