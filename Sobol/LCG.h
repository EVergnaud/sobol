//LCG.h

#pragma once
using namespace std;
#include <vector>
//linear congruencial generator. returns a vector of _int64 (to not risk overflows)
vector<_int64> LCG(_int64 a, _int64 c, _int64 m, _int64 seed, unsigned n); 