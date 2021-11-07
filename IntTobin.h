#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <cmath>
#include <math.h>
#include <regex>
#include "RealToBin.h"
using namespace std;

class IntToBin:public FloatToBin {
public:
    bool isFormat(string);
    vector<int> x16_bit(string );
    int x16bit_convertback(string );
};

ostream& operator<<(ostream& , vector<int>);